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
LOG_MODULE_REGISTER(app);

extern struct k_msgq temperature_inside_msgq,
                        humidity_inside_msgq,
                        temperature_outside_msgq,
                        humidity_outside_msgq;

LV_IMG_DECLARE(wife);

static uint32_t count;

static void lv_btn_click_callback(lv_event_t *e)
{
    ARG_UNUSED(e);

    LOG_INF("Button clicked.");
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

    /*----------------*/

    lv_obj_t *right_button;
    right_button = lv_btn_create(lv_scr_act());
    lv_obj_align(right_button, LV_ALIGN_BOTTOM_RIGHT, -5, -5);
    lv_obj_add_event_cb(right_button, lv_btn_click_callback, LV_EVENT_CLICKED, NULL);
    
    lv_obj_t *right_button_label;
    right_button_label = lv_label_create(right_button);
    lv_label_set_text(right_button_label, LV_SYMBOL_RIGHT);
    lv_obj_align(right_button_label, LV_ALIGN_CENTER, 0, 0);

    /*----------------*/

    lv_obj_t *date_label;
    date_label = lv_label_create(lv_scr_act());
    lv_label_set_text(date_label, "Date: ");
    lv_obj_align(date_label, LV_ALIGN_TOP_LEFT, 0, 0);

    lv_obj_t *date_data_label;
    date_data_label = lv_label_create(lv_scr_act());
    char date_data_str[32];
    sprintf(date_data_str,"the %d%s of %s!", 4, "th", "July"); 
    lv_label_set_text(date_data_label, date_data_str);
    lv_obj_align(date_data_label, LV_ALIGN_TOP_LEFT, 67, 0); // literally pixel counting...
  
    /*----------------*/

    lv_obj_t *location_label;
    location_label = lv_label_create(lv_scr_act());
    lv_label_set_text(location_label, "Location: ");
    lv_obj_align(location_label, LV_ALIGN_TOP_LEFT, 0, 25);

    lv_obj_t *location_data_label;
    location_data_label = lv_label_create(lv_scr_act());
    char location_data_str[32];
    sprintf(location_data_str, "%s", "Sigil...");
    lv_label_set_text(location_data_label, location_data_str);
    lv_obj_align(location_data_label, LV_ALIGN_TOP_LEFT, 110, 25);

    /*----------------*/

    lv_obj_t *temp_inside_label;
    temp_inside_label = lv_label_create(lv_scr_act());
    lv_label_set_text(temp_inside_label, "Temperature inside: ");
    lv_obj_align(temp_inside_label, LV_ALIGN_TOP_LEFT, 0, 50);

    lv_obj_t *temp_inside_data_label;
    temp_inside_data_label = lv_label_create(lv_scr_act());
    char temp_inside_data_str[16];
    sprintf(temp_inside_data_str, "%.1f", 0.0);
    lv_label_set_text(temp_inside_data_label, temp_inside_data_str);
    lv_obj_align(temp_inside_data_label, LV_ALIGN_TOP_LEFT, 229, 50); // i love pixel counting
    
    /*----------------*/

    lv_obj_t *hmdty_inside_label;
    hmdty_inside_label = lv_label_create(lv_scr_act());
    lv_label_set_text(hmdty_inside_label, "Humidity inside: ");
    lv_obj_align(hmdty_inside_label, LV_ALIGN_TOP_LEFT, 0, 75);

    lv_obj_t *hmdty_inside_data_label;
    hmdty_inside_data_label = lv_label_create(lv_scr_act());
    char hmdty_inside_data_str[16];
    sprintf(hmdty_inside_data_str, "%.1f", 0.0);
    lv_label_set_text(hmdty_inside_data_label, hmdty_inside_data_str);
    lv_obj_align(hmdty_inside_data_label, LV_ALIGN_TOP_LEFT, 189, 75); // i really do
    
    /*----------------*/

    lv_obj_t *weather_logo_img;
    weather_logo_img = lv_img_create(lv_scr_act());
    lv_img_set_src(weather_logo_img, &wife);
    lv_obj_align(weather_logo_img, LV_ALIGN_LEFT_MID, 0, 20);

    lv_obj_t *wind_logo_img;
    wind_logo_img = lv_img_create(lv_scr_act());
    lv_img_set_src(wind_logo_img, &wife);
    lv_obj_align(wind_logo_img, LV_ALIGN_LEFT_MID, 84, 20);

    lv_obj_t *hmdty_logo_img;
    hmdty_logo_img = lv_img_create(lv_scr_act());
    lv_img_set_src(hmdty_logo_img, &wife);
    lv_obj_align(hmdty_logo_img, LV_ALIGN_LEFT_MID, 168, 20);

    /*----------------*/
    
    lv_task_handler();
    display_blanking_off(display_dev);


    while (1) {
        float temperature_outside;
        unsigned long humidity_outside;
        struct sensor_value temperature_inside, humidity_inside;

        int ret = k_msgq_peek(&temperature_inside_msgq, &temperature_inside);
        if (ret != 0) {
            LOG_ERR("Failed to get inside temperature data from the queue: %d", ret);
        }
        sprintf(temp_inside_data_str, "%.1f", sensor_value_to_double(&temperature_inside));
        lv_label_set_text(temp_inside_data_label, temp_inside_data_str);

        ret = k_msgq_peek(&humidity_inside_msgq, &humidity_inside);
        if (ret != 0) {
            LOG_ERR("Failed to get inside humidity data from the queue: %d", ret);
        }
        sprintf(hmdty_inside_data_str, "%.1f", sensor_value_to_double(&humidity_inside));
        lv_label_set_text(hmdty_inside_data_label, hmdty_inside_data_str);

        ret = k_msgq_peek(&temperature_outside_msgq, &temperature_outside);
        if (ret != 0) {
            LOG_ERR("Faield to get outside temperature data from the queue: %d", ret);
        }

        ret = k_msgq_peek(&humidity_outside_msgq, &humidity_outside);
        if (ret != 0) {
            LOG_ERR("Failed to get outside humidity data from the queue: %d", ret);
        }

        lv_task_handler();
        k_sleep(K_MSEC(10));
    }
}
