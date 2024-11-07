#include <zephyr/kernel.h>

#include "wifi/wifi.h"

#define WIFI_USER_SSID  "ssid"
#define WIFI_USER_PSK   "psk"

int
main(void) {
    int ret = wifi_connect(WIFI_USER_SSID, WIFI_USER_PSK);

    if (ret != 0) {
        printk("Failed to connect to provided wifi station.");
        return 1;
    } else {
        printk("Succesfully connected to provided wifi station.");
    }

    return 0;
}
