#ifndef FORECAST_H_
#define FORECAST_H_ 

#include "cjson/cJSON.h"

#include <zephyr/net/socket.h>
#include <zephyr/net/net_ip.h>
#include <zephyr/net/tls_credentials.h>
#include <zephyr/net/http/client.h>
#include <zephyr/net/sntp.h>

struct forecast_data {
    double max;
    double min;
    double current;
};

struct forecast_data_full {
    struct forecast_data temperature;
    struct forecast_data humidity;
    struct forecast_data wind_speed;
    struct forecast_data uvi;
};

int forecast_get(const char *server, const char *api_key);
int forecast_response_parse(char *response);
int forecast_array_get_min_max(cJSON *array, struct forecast_data *data);
int forecast_array_get_current(cJSON *array, struct forecast_data *data, unsigned int current_hour);
int forecast_sntp_sync(void);


#endif
