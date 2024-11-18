#include "display.h"

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <lvgl_input_device.h>
#include <zephyr/drivers/gpio.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(app);

LV_IMG_DECLARE(wife);

static uint32_t count;

static void lv_btn_click_callback(lv_event_t *e)
{
	ARG_UNUSED(e);

	count = 0;
}

void display_handler(void *, void *, void *)
{
    const struct gpio_dt_spec backlight = GPIO_DT_SPEC_GET(DT_ALIAS(backlight), gpios);
    gpio_pin_configure_dt(&backlight, GPIO_OUTPUT_ACTIVE);
    gpio_pin_set_dt(&backlight, true);

	char count_str[11] = {0};
	const struct device *display_dev;
	lv_obj_t *hello_world_label;
	lv_obj_t *count_label;

	display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display_dev)) {
		LOG_ERR("Device not ready, aborting test");
		return;
	}

	if (IS_ENABLED(CONFIG_LV_Z_POINTER_INPUT)) {
		lv_obj_t *hello_world_button;

		hello_world_button = lv_btn_create(lv_scr_act());
		lv_obj_align(hello_world_button, LV_ALIGN_BOTTOM_LEFT, 5, -5);
		lv_obj_add_event_cb(hello_world_button, lv_btn_click_callback, LV_EVENT_CLICKED,
				    NULL);
		hello_world_label = lv_label_create(hello_world_button);
	} else {
		hello_world_label = lv_label_create(lv_scr_act());
	}

	lv_label_set_text(hello_world_label, "Hello world!");
	lv_obj_align(hello_world_label, LV_ALIGN_CENTER, 0, 0);

	count_label = lv_label_create(lv_scr_act());
	lv_obj_align(count_label, LV_ALIGN_BOTTOM_MID, 20, -10);

	lv_task_handler();
	display_blanking_off(display_dev);

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

    lv_obj_t *wife_img;
    wife_img = lv_img_create(lv_scr_act());
    lv_img_set_src(wife_img, &wife);
    lv_obj_align(wife_img, LV_ALIGN_LEFT_MID, 0, 20);

	while (1) {
		if ((count % 100) == 0U) {
			sprintf(count_str, "%d", count/100U);
			lv_label_set_text(count_label, count_str);
		}
		lv_task_handler();
		++count;
		k_sleep(K_MSEC(10));
	}
}
