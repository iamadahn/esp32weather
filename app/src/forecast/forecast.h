#ifndef FORECAST_H_
#define FORECAST_H_ 

#include "display/widgets.h"
#include "cjson/cJSON.h"

#include <zephyr/net/socket.h>
#include <zephyr/net/net_ip.h>
#include <zephyr/net/tls_credentials.h>
#include <zephyr/net/http/client.h>
#include <zephyr/net/sntp.h>

struct forecast {
    struct widget_data temperature;
    struct widget_data humidity;
    struct widget_data wind_speed;
    struct widget_data uvi;
};

void forecast_handler(void *, void *, void *);

int forecast_get(const char *server, const char *api_key);
void response_cb(struct http_response *response, enum http_final_call final_data, void *user_data);
int forecast_response_parse(char *response);
int forecast_array_get_min_max(cJSON *array, struct widget_data *data);
int forecast_array_get_current(cJSON *array, struct widget_data *data, unsigned int current_hour);
int sntp_sync_time(void);


#endif
