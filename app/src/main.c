#include <zephyr/kernel.h>

#include "forecast/forecast.h"
#include "display/display.h"
#include "ths/ths.h"

K_THREAD_STACK_DEFINE(display_thread_stack_area, 4096);
struct k_thread display_thread_data;

K_THREAD_STACK_DEFINE(forecast_thread_stack_area, 4096);
struct k_thread forecast_thread_data;

K_THREAD_STACK_DEFINE(ths_thread_stack_area, 512);
struct k_thread ths_thread_data;

int
main(void) {
    k_tid_t display_tid = k_thread_create(&display_thread_data,
                                          display_thread_stack_area,
                                          K_THREAD_STACK_SIZEOF(display_thread_stack_area),
                                          display_handler,
                                          NULL, NULL, NULL,
                                          5, 0, K_NO_WAIT);

    k_tid_t forecast_tid = k_thread_create(&forecast_thread_data,
                                          forecast_thread_stack_area,
                                          K_THREAD_STACK_SIZEOF(forecast_thread_stack_area),
                                          forecast_handler,
                                          NULL, NULL, NULL,
                                          5, 0, K_NO_WAIT);

    k_tid_t ths_tid = k_thread_create(&ths_thread_data,
                                      ths_thread_stack_area,
                                      K_THREAD_STACK_SIZEOF(ths_thread_stack_area),
                                      ths_handler,
                                      NULL, NULL, NULL,
                                      5, 0, K_NO_WAIT);

    return 0;
}
