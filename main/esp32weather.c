/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    for (unsigned int i = 10; i >= 1; i--) {
        printf("Restart in %d\n", i);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

    printf("This is gonna be yet another weather station.\n");
    vTaskDelay(pdMS_TO_TICKS(1000));

    fflush(stdout);
    esp_restart();
}
