#include "forecast.h"
#include "user_data.h"
#include "wifi.h"

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

static int forecast_response_parse(char *response);
static void response_cb(struct http_response *response,
                        enum http_final_call final_data,
                        void *user_data);
static int forecast_get(const char *server, const char *api_key);
static int socket_setup(const char* server, const char* port, int *sock);

static int forecast_response_parse(char *response)
{
    /*
    while (k_msgq_put(&temperature_outside_msgq, &forecast.current.temperature_2m, K_NO_WAIT) != 0) {
        k_msgq_purge(&temperature_outside_msgq);
    }

    while (k_msgq_put(&humidity_outside_msgq, &forecast.current.relative_humidity_2m, K_NO_WAIT) != 0) {
        k_msgq_purge(&humidity_outside_msgq);
    }
    */

    return 0;
}

static void response_cb(struct http_response *response, enum http_final_call final_data, void *user_data)
{
    if (final_data == HTTP_DATA_MORE) {
        LOG_INF("Partial data received (%zd bytes).", response->data_len);
    } else if (final_data == HTTP_DATA_FINAL) {
        LOG_INF("All the data received (%zd bytes).", response->data_len);
    }

    LOG_INF("GET response status - %s.", response->http_status);

    printk(response->recv_buf);
    k_msleep(1000);
    forecast_response_parse(strchr(response->recv_buf, '{'));
    
    unsigned char forecast_async_state = 1;
    k_msgq_purge(&forecast_async_state_msgq);
    int ret = k_msgq_put(&forecast_async_state_msgq, &forecast_async_state, K_NO_WAIT);
    if (ret != 0) {
        LOG_ERR("Failed to push to wifi state queue");
    }
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
