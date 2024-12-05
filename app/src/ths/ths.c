#include "ths.h"

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/sensor.h>

extern struct k_msgq wifi_state_msgq;

LOG_MODULE_REGISTER(ths);

K_MSGQ_DEFINE(temperature_inside_msgq, sizeof(struct sensor_value), 1, 1);
K_MSGQ_DEFINE(humidity_inside_msgq, sizeof(struct sensor_value), 1, 1);

void ths_handler(void *, void *, void *)
{
    const struct device *const aht30 = DEVICE_DT_GET_ONE(aosong_aht20);

    unsigned char wifi_state = 0;
    while (k_msgq_peek(&wifi_state_msgq, &wifi_state) != 0) {
        k_sleep(K_MSEC(100));
    }
    
    if (wifi_state != 1) {
        LOG_ERR("Failed to get wifi state, aborting.");
    }

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

        struct sensor_value temperature_inside, humidity_inside;

        ret = sensor_channel_get(aht30, SENSOR_CHAN_AMBIENT_TEMP, &temperature_inside);
        if (ret != 0) {
           LOG_ERR("Failed to get temperature data: %d", ret);
           failure_detected = true;
        }

        ret = sensor_channel_get(aht30, SENSOR_CHAN_HUMIDITY, &humidity_inside);
        if (ret != 0) {
           LOG_ERR("Failed to get humidity data: %d", ret);
           failure_detected = true;
        } 

        while (k_msgq_put(&temperature_inside_msgq, &temperature_inside, K_NO_WAIT) != 0) {
            k_msgq_purge(&temperature_inside_msgq);
        }

        while (k_msgq_put(&humidity_inside_msgq, &humidity_inside, K_NO_WAIT) != 0) {
            k_msgq_purge(&humidity_inside_msgq);
        }

        if (failure_detected) {
            k_msleep(5000);
            failure_detected = false;
        } else {
            k_msleep(100);
        }
    }
}
