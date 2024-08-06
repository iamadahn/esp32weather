#include <stdio.h>
#include <inttypes.h>
#include "FreeRTOSConfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig_arch.h"
#include "freertos/projdefs.h"
#include "freertos/task.h"
#include "display_controller.h"

void app_main(void)
{
    printf("This is gonna be yet another weather station.\n");
    vTaskDelay(pdMS_TO_TICKS(1000));

    xTaskCreate(display_controller_task, "display_controller", configMINIMAL_STACK_SIZE, NULL, configMAX_PRIORITIES - 3, NULL);

    fflush(stdout);
}

void
delay_ms(uint32_t ms) {
    vTaskDelay(pdMS_TO_TICKS(ms));
}
