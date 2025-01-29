#ifndef FORECAST_H_
#define FORECAST_H_ 

#include "display/widgets.h"

struct forecast {
    struct widget_data temperature;
    struct widget_data humidity;
    struct widget_data wind_speed;
    struct widget_data uvi;
};

void forecast_handler(void *, void *, void *);

#endif
