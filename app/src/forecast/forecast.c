#include "forecast.h"
#include "forecast_json.h"
#include "wifi.h"

#include <zephyr/kernel.h>
#include <zephyr/net/socket.h>
#include <zephyr/data/json.h>
#include <zephyr/logging/log.h>

#include <zephyr/net/net_ip.h>
#include <zephyr/net/tls_credentials.h>
#include <zephyr/net/http/client.h>

#define WIFI_USER_SSID  "your_ssid"
#define WIFI_USER_PSK   "your_psk"

#define FORECAST_SERVER  "api.open-meteo.com"
#define FORECAST_APICALL "your_api_key"

LOG_MODULE_REGISTER(weather);

unsigned char recv_buf[3072];

struct forecast_data forecast;

static int forecast_response_parse(char *response);
static void response_cb(struct http_response *response,
                        enum http_final_call final_data,
                        void *user_data);
static int forecast_get(const char *server, const char *api_key);
static int socket_setup(const char* server, const char* port, int *sock);

static int forecast_response_parse(char *response)
{
    int ret = json_obj_parse(response,
                             sizeof(response) - 1, 
                             forecast_data_descr,
                             ARRAY_SIZE(forecast_data_descr),
                             &forecast);

    if (ret <= 0) {
        LOG_ERR("Failed to parse json data. - %d", ret);
    } else {
        LOG_INF("Succesfully parsed json data.");
    }

    LOG_INF("%f:%f", (double)forecast.latitude, (double)forecast.longitude);

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

    printk(strchr(response->recv_buf, '{'));
    forecast_response_parse(strchr(response->recv_buf, '{'));
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

static int socket_setup(const char* server, const char* port, int *sock)
{
    int ret = 0;

    struct zsock_addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    ret = zsock_getaddrinfo(server, port, &hints, &res);
    if (ret != 0) {
        LOG_INF("getaddrinfo status: %d\n", ret);
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

void forecast_handler(void *, void *, void *) {
    int ret = wifi_connect(WIFI_USER_SSID, WIFI_USER_PSK);

    if (ret != 0) {
        LOG_INF("Failed to connect to provided wifi station.");
        return;
    } else {
        LOG_INF("Succesfully connected to provided wifi station.");
    }

    forecast_get(FORECAST_SERVER, FORECAST_APICALL);

    while (true) {
        k_msleep(100);
    }
}
