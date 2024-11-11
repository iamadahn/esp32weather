#include <zephyr/kernel.h>

#include "wifi/wifi.h"
#include "weather/weather.h"

#define WIFI_USER_SSID  "your-ssid"
#define WIFI_USER_PSK   "your-password"

#define WEATHER_SERVER  "api.open-meteo.com"
#define WEATHER_APICALL "your-api-key"

int
main(void) {
    int ret = wifi_connect(WIFI_USER_SSID, WIFI_USER_PSK);

    if (ret != 0) {
        printk("Failed to connect to provided wifi station.");
        return 1;
    } else {
        printk("Succesfully connected to provided wifi station.");
    }
    
    weather_get(WEATHER_SERVER, WEATHER_APICALL);

    return 0;
}
