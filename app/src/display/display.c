#include "display.h"

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <lvgl_input_device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(display);

extern struct k_msgq temperature_inside_msgq,
                        humidity_inside_msgq,
                        temperature_outside_msgq,
                        forecast_async_state_msgq,
                        humidity_outside_msgq;

LV_IMG_DECLARE(wife);

static lv_obj_t *forecast_scr, *wife_scr;

void display_handler(void *, void *, void *)
{
    const struct device *display_dev;

    display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
    if (!device_is_ready(display_dev)) {
        LOG_ERR("Device not ready, aborting test");
        return;
	}

    forecast_scr = lv_obj_create(NULL);
    lv_scr_load(forecast_scr);

    /*---------------------*/
    /* Outside frame label */
    /*---------------------*/

    lv_obj_t *outside_frame_label;
    outside_frame_label = lv_label_create(lv_scr_act());
    lv_label_set_text(outside_frame_label, "Outside");
    lv_obj_align(outside_frame_label, LV_ALIGN_TOP_LEFT, 20, 5);

    lv_point_t outside_frame_line_points[] = { {18, 13}, {10, 13}, {10, 110}, {310, 110}, {310, 13}, {80, 13} };
    lv_style_t outside_frame_line_style;
    lv_style_init(&outside_frame_line_style);
    lv_style_set_line_width(&outside_frame_line_style, 2);
    lv_style_set_line_rounded(&outside_frame_line_style, true);

    lv_obj_t *outside_frame_line;
    outside_frame_line = lv_line_create(lv_scr_act());
    lv_line_set_points(outside_frame_line, outside_frame_line_points, 6);
    lv_obj_add_style(outside_frame_line, &outside_frame_line_style, 0);
    lv_obj_align(outside_frame_line, LV_ALIGN_TOP_LEFT, 0, 0);

    /*--------------------*/
    /* Inside frame label */
    /*--------------------*/

    lv_obj_t *inside_frame_label;
    inside_frame_label = lv_label_create(lv_scr_act());
    lv_label_set_text(inside_frame_label, "Inside");
    lv_obj_align(inside_frame_label, LV_ALIGN_TOP_LEFT, 20, 125);

    lv_point_t inside_frame_line_points[] = { {18, 133}, {10, 133}, {10, 230}, {150, 230}, {150, 133}, {66, 133} };
    lv_style_t inside_frame_line_style;
    lv_style_init(&inside_frame_line_style);
    lv_style_set_line_width(&inside_frame_line_style, 2);
    lv_style_set_line_rounded(&inside_frame_line_style, true);

    lv_obj_t *inside_frame_line;
    inside_frame_line = lv_line_create(lv_scr_act());
    lv_line_set_points(inside_frame_line, inside_frame_line_points, 6);
    lv_obj_add_style(inside_frame_line, &inside_frame_line_style, 0);
    lv_obj_align(inside_frame_line, LV_ALIGN_TOP_LEFT, 0, 0);

    /*------------------*/
    /* Time frame label */
    /*------------------*/

    lv_obj_t *time_frame_label;
    time_frame_label = lv_label_create(lv_scr_act());
    lv_label_set_text(time_frame_label, "Time");
    lv_obj_align(time_frame_label, LV_ALIGN_TOP_LEFT, 180, 125);

    lv_point_t time_frame_line_points[] = { {178, 133}, {170, 133}, {170, 230}, {310, 230}, {310, 133}, {218, 133} };
    lv_style_t time_frame_line_style;
    lv_style_init(&time_frame_line_style);
    lv_style_set_line_width(&time_frame_line_style, 2);
    lv_style_set_line_rounded(&time_frame_line_style, true);

    lv_obj_t *time_frame_line;
    time_frame_line = lv_line_create(lv_scr_act());
    lv_line_set_points(time_frame_line, time_frame_line_points, 6);
    lv_obj_add_style(time_frame_line, &time_frame_line_style, 0);
    lv_obj_align(time_frame_line, LV_ALIGN_TOP_LEFT, 0, 0);
    
    const struct gpio_dt_spec display_backlight = GPIO_DT_SPEC_GET(DT_ALIAS(backlight), gpios);
    gpio_pin_configure_dt(&display_backlight, GPIO_OUTPUT_ACTIVE);
    gpio_pin_set_dt(&display_backlight, true);

    /*-------------------------------------*/
    /* The end of widgets creating section */
    /*-------------------------------------*/
    
    lv_task_handler();
    display_blanking_off(display_dev);

    /* Let the async json request handle itself succesfully */
    unsigned char forecast_async_state = 0;
    while (forecast_async_state != 1) {
        k_msgq_peek(&forecast_async_state_msgq, &forecast_async_state);
        k_sleep(K_MSEC(100));
    }

    while (1) {
        float temperature_outside;
        unsigned long humidity_outside;
        struct sensor_value temperature_inside, humidity_inside;

        int ret = k_msgq_peek(&temperature_inside_msgq, &temperature_inside);
        if (ret != 0) {
            LOG_ERR("Failed to get inside temperature data from the queue: %d", ret);
        }
        //sprintf(temp_inside_data_str, "%.1f", sensor_value_to_double(&temperature_inside));

        ret = k_msgq_peek(&humidity_inside_msgq, &humidity_inside);
        if (ret != 0) {
            LOG_ERR("Failed to get inside humidity data from the queue: %d", ret);
        }
        //sprintf(hmdty_inside_data_str, "%.1f", sensor_value_to_double(&humidity_inside));

        ret = k_msgq_peek(&temperature_outside_msgq, &temperature_outside);
        if (ret != 0) {
            LOG_ERR("Failed to get outside temperature data from the queue: %d", ret);
        }
        //sprintf(temp_outside_data_str, "%.1f", (double)temperature_outside);

        ret = k_msgq_peek(&humidity_outside_msgq, &humidity_outside);
        if (ret != 0) {
            LOG_ERR("Failed to get outside humidity data from the queue: %d", ret);
        }
        //sprintf(hmdty_outside_data_str, "%lu", humidity_outside);

        lv_task_handler();
        k_sleep(K_MSEC(100));
    }
}
