#include "ths.h"

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/sensor.h>

LOG_MODULE_REGISTER(ths);

void ths_handler(void *, void *, void *)
{
    const struct device *const aht30 = DEVICE_DT_GET_ONE(aosong_aht20);

    if (!device_is_ready(aht30)) {
        LOG_ERR("Failed to initialise aht30 sensor.");
        return;
    }

    while (true) {
        bool failure_detected = false;

        int ret = sensor_sample_fetch(aht30);
        if (ret != 0) {
           LOG_ERR("Failed to fetch sensor: %d", ret);
           failure_detected = true;
        }

        struct sensor_value temperature, humidity;

        ret = sensor_channel_get(aht30, SENSOR_CHAN_AMBIENT_TEMP, &temperature);
        if (ret != 0) {
           LOG_ERR("Failed to get temperature data: %d", ret);
           failure_detected = true;
        }

        ret = sensor_channel_get(aht30, SENSOR_CHAN_HUMIDITY, &humidity);
        if (ret != 0) {
           LOG_ERR("Failed to get humidity data: %d", ret);
           failure_detected = true;
        } 

        if (failure_detected) {
            k_msleep(5000);
            failure_detected = false;
        } else {
            k_msleep(100);
        }
    }
}
