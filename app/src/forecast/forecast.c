#include "forecast.h"
#include "user_data.h"
#include "wifi.h"
#include "cjson/cJSON.h"

#include <float.h>

#include <zephyr/kernel.h>
#include <zephyr/net/socket.h>
#include <zephyr/data/json.h>
#include <zephyr/logging/log.h>

#include <zephyr/net/net_ip.h>
#include <zephyr/net/tls_credentials.h>
#include <zephyr/net/http/client.h>

LOG_MODULE_REGISTER(forecast);

K_MSGQ_DEFINE(temperature_outside_msgq, sizeof(float), 1, 1);
K_MSGQ_DEFINE(humidity_outside_msgq, sizeof(unsigned long), 1, 1);
K_MSGQ_DEFINE(forecast_async_state_msgq, sizeof(unsigned short), 1, 1);

unsigned char recv_buf[3072];

static int socket_setup(const char* server, const char* port, int *sock);
static int forecast_get(const char *server, const char *api_key);
static void response_cb(struct http_response *response,
                        enum http_final_call final_data,
                        void *user_data);
static int forecast_response_parse(char *response);
static int forecast_array_get_min_max(cJSON *array, struct forecast_data *data);
static int forecast_array_get_current(cJSON *array, struct forecast_data *data, unsigned int current_hour);

static int socket_setup(const char* server, const char* port, int *sock)
{
    int ret = 0;

    struct zsock_addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    ret = zsock_getaddrinfo(server, port, &hints, &res);
    if (ret != 0) {
        LOG_ERR("getaddrinfo status: %d\n", ret);
        return -EINVAL;
    }

    *sock = zsock_socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (*sock < 0) {
        LOG_ERR("Failed to create HTTP socket - %d.", -errno);
        zsock_freeaddrinfo(res);
        return -errno;
    }

    ret = zsock_connect(*sock, res->ai_addr, res->ai_addrlen);
    if (ret < 0) {
        LOG_ERR("Cannot connect to remote - %d.", -errno);
        zsock_close(*sock);
        *sock = -1;
        zsock_freeaddrinfo(res);
        return -errno;
    }

    zsock_freeaddrinfo(res);
    return 0;
}

static int forecast_get(const char *server, const char *api_key)
{
    int sock;
    struct sockaddr_in addr;
    int timeout = 10 * MSEC_PER_SEC;

    int ret = socket_setup(server, "80", &sock);
    if (sock < 0) {
        LOG_ERR("Failed to establish HTTP connection.");
    }

    struct http_request req;
    memset(&req, 0, sizeof(req));

    req.method = HTTP_GET;
    req.url = api_key;
    req.host = server;
    req.protocol = "HTTP/1.1";
    req.response = response_cb;
    req.recv_buf = recv_buf;
    req.recv_buf_len = sizeof(recv_buf);

    ret = http_client_req(sock, &req, timeout, NULL);

    zsock_close(sock);

    return ret;
}

static void response_cb(struct http_response *response, enum http_final_call final_data, void *user_data)
{
    if (final_data == HTTP_DATA_MORE) {
        LOG_INF("Partial data received (%zd bytes).", response->data_len);
    } else if (final_data == HTTP_DATA_FINAL) {
        LOG_INF("All the data received (%zd bytes).", response->data_len);
    }

    LOG_INF("GET response status - %s.", response->http_status);

    forecast_response_parse(strchr(response->recv_buf, '{'));
    
    unsigned char forecast_async_state = 1;
    k_msgq_purge(&forecast_async_state_msgq);
    int ret = k_msgq_put(&forecast_async_state_msgq, &forecast_async_state, K_NO_WAIT);
    if (ret != 0) {
        LOG_ERR("Failed to push to wifi state queue");
    }
}

static int forecast_response_parse(char *response)
{
    cJSON_Hooks hooks = {
        .malloc_fn = malloc,
        .free_fn = free,
    };

    cJSON_InitHooks(&hooks);

    cJSON *json = cJSON_Parse(response);
    if (json == NULL) {
        LOG_ERR("Error parsing JSON");
        return -1;
    }

    cJSON *current = cJSON_GetObjectItemCaseSensitive(json, "current");
    cJSON *temperature_current = cJSON_GetObjectItemCaseSensitive(current, "temperature_2m");
    cJSON *humidity_current = cJSON_GetObjectItemCaseSensitive(current, "relative_humidity_2m");
    cJSON *wind_speed_current = cJSON_GetObjectItemCaseSensitive(current, "wind_speed_10m");

    cJSON *hourly = cJSON_GetObjectItemCaseSensitive(json, "hourly");
    cJSON *temperature_array = cJSON_GetObjectItemCaseSensitive(hourly, "temperature_2m");
    cJSON *humidity_array = cJSON_GetObjectItemCaseSensitive(hourly, "relative_humidity_2m");
    cJSON *wind_speed_array = cJSON_GetObjectItemCaseSensitive(hourly, "wind_speed_10m");
    cJSON *uvi_array = cJSON_GetObjectItemCaseSensitive(hourly, "uv_index");

    struct forecast forecast;
    forecast_array_get_min_max(temperature_array, &forecast.temperature);
    forecast_array_get_min_max(humidity_array, &forecast.humidity);
    forecast_array_get_min_max(wind_speed_array, &forecast.wind_speed);
    forecast_array_get_min_max(uvi_array, &forecast.uvi);

    if (cJSON_IsNumber(temperature_current))
        forecast.temperature.current = temperature_current->valuedouble;
    else
        LOG_ERR("Error parsing current temperature");

    if (cJSON_IsNumber(humidity_current))
        forecast.humidity.current = temperature_current->valuedouble;
    else
        LOG_ERR("Error parsing current humidity");
    /* TODO - need to initialise rtc and ntp and use correct time */
    forecast_array_get_current(wind_speed_array, &forecast.wind_speed, 0);
    forecast_array_get_current(uvi_array, &forecast.uvi, 0);
    /*------------------------------------------------------------*/

    cJSON_Delete(json);

    return 0;
}

static int forecast_array_get_min_max(cJSON *array, struct forecast_data *data)
{
    if (!cJSON_IsArray(array)) {
        LOG_ERR("Not an array");
        return -1;
    }

    double min = FLT_MAX, max = -FLT_MAX;

    for (size_t i = 0; i < 24; i++) {
        if (cJSON_GetArrayItem(array, i)->valuedouble < min)
            min = cJSON_GetArrayItem(array, i)->valuedouble;
        if (cJSON_GetArrayItem(array, i)->valuedouble > max)
            max = cJSON_GetArrayItem(array, i)->valuedouble;
    }

    data->max = max;
    data->min = min;

    return 0;
}

static int forecast_array_get_current(cJSON *array, struct forecast_data *data, unsigned int current_hour)
{
    if (!cJSON_IsArray(array)) {
        LOG_ERR("Not an array");
        return -1;
    }

    data->current = cJSON_GetArrayItem(array, current_hour)->valuedouble;

    return 0;
}

void forecast_handler(void *, void *, void *) {
    unsigned char forecast_async_state = 0;
    int ret = k_msgq_put(&forecast_async_state_msgq, &forecast_async_state, K_NO_WAIT);
    if (ret != 0) {
        LOG_ERR("Failed to push to wifi state queue");
    }
    
    ret = wifi_connect(WIFI_USER_SSID, WIFI_USER_PSK);

    if (ret != 0) {
        LOG_ERR("Failed to connect to provided wifi station.");
        return;
    } else {
        LOG_INF("Succesfully connected to provided wifi station.");
    }
   
    forecast_get(FORECAST_SERVER, FORECAST_APICALL);
 

    while (true) {
        k_msleep(100);
    }
}
