#include "display.h"
#include "widgets.h"

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

#define SCR_WIDTH 320
#define SCR_HEIGHT 240

LOG_MODULE_REGISTER(display);

LV_IMG_DECLARE(wife);

LV_FONT_DECLARE(jetbrains_12);
LV_FONT_DECLARE(jetbrains_14);
LV_FONT_DECLARE(jetbrains_18);
LV_FONT_DECLARE(jetbrains_20);
LV_FONT_DECLARE(jetbrains_28);

static unsigned char scr_pressed = 0;

extern struct k_msgq temperature_inside_msgq,
    humidity_inside_msgq,
    temperature_outside_msgq,
    forecast_async_state_msgq,
    humidity_outside_msgq;


static lv_obj_t *forecast_scr, *wife_scr;

static void scr_pressed_cb(lv_event_t *event)
{
    scr_pressed = 1;
    printf("Clicked on screen!\n");
}

void display_handler(void *, void *, void *)
{
    const struct device *display_dev;

    display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
    if (!device_is_ready(display_dev)) {
        LOG_ERR("Device not ready, aborting test");
        return;
	}

    const struct gpio_dt_spec display_backlight = GPIO_DT_SPEC_GET(DT_ALIAS(backlight), gpios);
    gpio_pin_configure_dt(&display_backlight, GPIO_OUTPUT_ACTIVE);
    gpio_pin_set_dt(&display_backlight, true);

    lv_color_t background_color = lv_color_make(0xEA, 0x93, 0x2E);
    lv_color_t font_color = lv_color_make(0x00, 0x00, 0x00);

    wife_scr = lv_obj_create(NULL);
    lv_scr_load(wife_scr);
    lv_obj_add_event_cb(wife_scr, scr_pressed_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_set_style_bg_color(lv_scr_act(), background_color, 0);

    lv_obj_t *wife_img = lv_img_create(lv_scr_act());
    lv_img_set_src(wife_img, &wife);
    lv_obj_align(wife_img, LV_ALIGN_TOP_LEFT, 0, 0);

    forecast_scr = lv_obj_create(NULL);
    lv_scr_load(forecast_scr);
    lv_obj_add_event_cb(forecast_scr, scr_pressed_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_set_style_bg_color(lv_scr_act(), background_color, 0);
    lv_obj_set_style_border_width(forecast_scr, 0, 0);
    lv_obj_set_style_outline_width(forecast_scr, 0, 0);
    lv_obj_clear_flag(forecast_scr, LV_OBJ_FLAG_SCROLLABLE);

    /*--------------------*/
    /* Frame-realted vars */
    /*--------------------*/
    unsigned int data_widget_width = 62,
        data_widget_height = 62;

    unsigned int big_frame_width = SCR_WIDTH,
        big_frame_height = SCR_HEIGHT / 2,
        small_frame_width = SCR_WIDTH / 2,
        small_frame_height = big_frame_height;

    struct frame_widget outside_frame_widget = {
        .parent = lv_scr_act(),
        .font = &jetbrains_14,
        .text = "Outside",
        .bg_color = background_color,
        .font_color = font_color,
        .align = LV_ALIGN_TOP_LEFT,
        .event_cb = scr_pressed_cb,
        .event_code = LV_EVENT_PRESSED,
    };

    frame_widget_create(
        &outside_frame_widget,
        big_frame_width,
        big_frame_height,
        0,
        0
    );

    /*---------------------------------*/
    /* Outside temperature data widget */
    /*---------------------------------*/
    unsigned int outside_temp_data_widget_x_start = DEFAULT_OUTLINE * 2,
        outside_temp_data_widget_y_start = DEFAULT_OUTLINE * 3;

    struct data_widget outside_temp_data_widget = {
        .parent = outside_frame_widget.self,
        .label_font = &jetbrains_12,
        .data_font = &jetbrains_18,
        .text = "Temp",
        .bg_color = background_color,
        .font_color = font_color,
        .event_cb = scr_pressed_cb,
        .event_code = LV_EVENT_PRESSED,
    };

    data_widget_create(
        &outside_temp_data_widget,
        data_widget_width,
        data_widget_height,
        outside_temp_data_widget_x_start,
        outside_temp_data_widget_y_start
    );

    /*------------------------------*/
    /* Outside humidity data widget */
    /*------------------------------*/
    unsigned int outside_hmdty_data_widget_x_start = outside_temp_data_widget_x_start + data_widget_width + DEFAULT_OUTLINE,
        outside_hmdty_data_widget_y_start = outside_temp_data_widget_y_start;

    struct data_widget outside_hmdty_data_widget = {
        .parent = outside_frame_widget.self,
        .label_font = &jetbrains_12,
        .data_font = &jetbrains_18,
        .text = "Hmd",
        .bg_color = background_color,
        .font_color = font_color,
        .event_cb = scr_pressed_cb,
        .event_code = LV_EVENT_PRESSED,
    };

    data_widget_create(
        &outside_hmdty_data_widget,
        data_widget_width,
        data_widget_height,
        outside_hmdty_data_widget_x_start,
        outside_hmdty_data_widget_y_start
    );

    /*--------------------------------*/
    /* Outside wind speed data widget */
    /*--------------------------------*/
    unsigned int outside_winds_data_widget_x_start = outside_hmdty_data_widget_x_start + data_widget_width + DEFAULT_OUTLINE + 1,
        outside_winds_data_widget_y_start = outside_hmdty_data_widget_y_start;

    struct data_widget outside_winds_data_widget = {
        .parent = outside_frame_widget.self,
        .label_font = &jetbrains_12,
        .data_font = &jetbrains_18,
        .text = "Wind",
        .bg_color = background_color,
        .font_color = font_color,
        .event_cb = scr_pressed_cb,
        .event_code = LV_EVENT_PRESSED,
    };

    data_widget_create(
        &outside_winds_data_widget,
        data_widget_width,
        data_widget_height,
        outside_winds_data_widget_x_start,
        outside_winds_data_widget_y_start
    );

    /*---------------------------------------*/
    /* Outside ultraviolet index data widget */
    /*---------------------------------------*/
    unsigned int outside_uvi_data_widget_x_start = outside_winds_data_widget_x_start + data_widget_width + DEFAULT_OUTLINE,
        outside_uvi_data_widget_y_start = outside_winds_data_widget_y_start;

    struct data_widget outside_uvi_data_widget = {
        .parent = outside_frame_widget.self,
        .label_font = &jetbrains_12,
        .data_font = &jetbrains_18,
        .text = "Uvi",
        .bg_color = background_color,
        .font_color = font_color,
        .event_cb = scr_pressed_cb,
        .event_code = LV_EVENT_PRESSED,
    };

    data_widget_create(
        &outside_uvi_data_widget,
        data_widget_width,
        data_widget_height,
        outside_uvi_data_widget_x_start,
        outside_uvi_data_widget_y_start
    );

    /*---------------------*/
    /* Inside frame widget */
    /*---------------------*/
    struct frame_widget inside_frame_widget = {
        .parent = lv_scr_act(),
        .font = &jetbrains_14,
        .text = "Inside",
        .bg_color = background_color,
        .font_color = font_color,
        .align = LV_ALIGN_TOP_LEFT,
        .event_cb = scr_pressed_cb,
        .event_code = LV_EVENT_PRESSED,
    };

    frame_widget_create(
        &inside_frame_widget,
        small_frame_width,
        small_frame_height,
        0,
        SCR_HEIGHT / 2
    );

    /*---------------------------*/
    /* Inside temperature widget */
    /*---------------------------*/
    struct data_min_widget inside_temp_widget = {
        .parent = inside_frame_widget.self,
        .label_font = &jetbrains_12,
        .data_font = &jetbrains_28,
        .text = "Temp",
        .bg_color = background_color,
        .font_color = font_color,
        .event_cb = scr_pressed_cb,
        .event_code = LV_EVENT_PRESSED,
    };

    data_min_widget_create(
        &inside_temp_widget,
        60,
        50,
        15,
        30
    );

    lv_label_set_text(inside_temp_widget.data_label, "99°");

    /*------------------------*/
    /* Inside humidity widget */
    /*------------------------*/
    struct data_min_widget inside_hmdty_widget = {
        .parent = inside_frame_widget.self,
        .label_font = &jetbrains_12,
        .data_font = &jetbrains_28,
        .text = "Hmd",
        .bg_color = background_color,
        .font_color = font_color,
        .event_cb = scr_pressed_cb,
        .event_code = LV_EVENT_PRESSED,
    };

    data_min_widget_create(
        &inside_hmdty_widget,
        60,
        50,
        85,
        30
    );

    lv_label_set_text(inside_hmdty_widget.data_label, "50%");

    /*-------------------*/
    /* Time frame widget */
    /*-------------------*/
    struct frame_widget time_frame_widget = {
        .parent = lv_scr_act(),
        .font = &jetbrains_14,
        .text = "Time",
        .bg_color = background_color,
        .font_color = font_color,
        .align = LV_ALIGN_TOP_LEFT,
        .event_cb = scr_pressed_cb,
        .event_code = LV_EVENT_PRESSED,
    };
    
    frame_widget_create(
        &time_frame_widget,
        small_frame_width,
        small_frame_height,
        SCR_WIDTH / 2,
        SCR_HEIGHT / 2
    );

    /*----------------------*/
    /* Time and date widget */
    /*----------------------*/
    struct time_and_date_widget time_and_date_widget_instance = {
        .parent = time_frame_widget.self,
        .bg_color = background_color,
        .font_color = font_color,
        .time_font = &jetbrains_28,
        .date_font = &jetbrains_20,
        .day_of_week_font = &jetbrains_20,
        .event_cb = scr_pressed_cb,
        .event_code = LV_EVENT_PRESSED,
    };

    time_and_date_widget_create(
        &time_and_date_widget_instance,
        125,
        85,
        20,
        20
    );

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
        if (scr_pressed == 1) {
            scr_pressed = 0;
            if (lv_scr_act() == forecast_scr) {
                lv_scr_load(wife_scr);
            } else {
                lv_scr_load(forecast_scr);
            }
        }            

        lv_task_handler();
        k_sleep(K_MSEC(100));
    }
}
