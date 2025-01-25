#ifndef FORECAST_H_
#define FORECAST_H_ 

struct forecast_data {
    double max;
    double min;
    double current;
};

struct forecast {
    struct forecast_data temperature;
    struct forecast_data humidity;
    struct forecast_data wind_speed;
    struct forecast_data uvi;
};

void forecast_handler(void *, void *, void *);

#endif
