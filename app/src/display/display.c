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

#define SCR_WIDTH 320
#define SCR_HEIGHT 240
#define SCR_BORDER_OPACITY 10

#define JETBRAINS_14_WIDTH 8
#define JETBRAINS_12_WIDTH 7

LOG_MODULE_REGISTER(display);

LV_IMG_DECLARE(wife);

LV_FONT_DECLARE(jetbrains_12);
LV_FONT_DECLARE(jetbrains_14);
LV_FONT_DECLARE(jetbrains_18);

struct frame_widget {
    char *text;
    lv_point_t line_points[6];
    lv_style_t style;
    lv_color_t color;
};

struct data_widget {
    char *text;
    lv_obj_t *data_current_label;
    lv_obj_t *data_min_label;
    lv_obj_t *data_max_label;
    lv_point_t main_line_points[4];
    lv_point_t left_line_points[3];
    lv_point_t right_line_points[3];
    lv_style_t style;
    lv_color_t color;
    unsigned int length;
};

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

static lv_obj_t* label_create(char *text, const lv_font_t *font, lv_color_t color, unsigned short x, unsigned short y) {
    lv_obj_t* label;
    label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, text);
    lv_obj_set_style_text_font(label, font, 0);
    lv_obj_set_style_text_color(label, color, 0);
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, x, y);

    return label;
}

static lv_obj_t* line_create(lv_point_t *points, lv_style_t *style, lv_color_t color, unsigned char width, unsigned char points_num)
{
    lv_style_set_line_width(style, width);
    lv_style_set_line_rounded(style, true);

    lv_obj_t* line;
    line = lv_line_create(lv_scr_act());
    lv_line_set_points(line, points, points_num);
    lv_obj_add_style(line, style, 0);
    lv_obj_align(line, LV_ALIGN_TOP_LEFT, 0, 0);

    return line;
}

static void frame_widget_create(struct frame_widget *widget,
                                unsigned int x_start,
                                unsigned int y_start,
                                unsigned int x_end,
                                unsigned int y_end)
{
    unsigned char label_opacity = 2;
    unsigned char label_pixel_size = strlen(widget->text) * JETBRAINS_14_WIDTH;
    unsigned int label_x_start = x_start + SCR_BORDER_OPACITY + label_opacity, label_y_start = 0;
    
    if (y_start < 5) {
        label_y_start = 0;
    } else {
        label_y_start = y_start - 5;
    }

    lv_obj_t *label = label_create(
        widget->text,
        &jetbrains_14,
        widget->color,
        label_x_start,
        label_y_start
    );

    unsigned short line_x_start = label_x_start - label_opacity,
        line_x_end = label_x_start + label_pixel_size + label_opacity;

    widget->line_points[0].x = line_x_start;
    widget->line_points[0].y = y_start;

    widget->line_points[1].x = x_start;
    widget->line_points[1].y = y_start;

    widget->line_points[2].x = x_start;
    widget->line_points[2].y = y_end;

    widget->line_points[3].x = x_end;
    widget->line_points[3].y = y_end;

    widget->line_points[4].x = x_end;
    widget->line_points[4].y = y_start;

    widget->line_points[5].x = line_x_end;
    widget->line_points[5].y = y_start;

    lv_style_init(&widget->style);
    lv_obj_t *line = line_create(widget->line_points, &widget->style, widget->color, 2, 6);
}

static void data_widget_create(struct data_widget *widget,
                               unsigned int x_start,
                               unsigned int y_start,
                               unsigned int x_end,
                               unsigned int y_end)
{
    /*-----------*/
    /* Main line */
    /*-----------*/
    unsigned char main_line_x_length = x_end - x_start,
        main_line_y_length = y_end - y_start;
    widget->length = main_line_x_length;

    unsigned int main_line_x_start = x_start,
        main_line_x_end = main_line_x_start + main_line_x_length,
        main_line_x_center = main_line_x_end - (main_line_x_length / 2),

        main_line_y_start = y_start + 35,
        main_line_y_end = main_line_y_start + main_line_y_length;

    widget->main_line_points[0].x = main_line_x_start;
    widget->main_line_points[0].y = main_line_y_start;

    widget->main_line_points[1].x = main_line_x_end;
    widget->main_line_points[1].y = main_line_y_start;

    widget->main_line_points[2].x = main_line_x_center;
    widget->main_line_points[2].y = main_line_y_start;

    widget->main_line_points[3].x = main_line_x_center;
    widget->main_line_points[3].y = main_line_y_end;

    lv_style_init(&widget->style);
    lv_obj_t *main_line = line_create(widget->main_line_points, &widget->style, widget->color, 1, 4);

    /*------------*/
    /* Text label */
    /*------------*/
    unsigned char label_pixel_size = strlen(widget->text) * JETBRAINS_12_WIDTH;
    unsigned char label_space_length = 5;
    unsigned char label_opacity = 2;

    unsigned int text_label_x = main_line_x_start + label_space_length + label_opacity,
        text_label_y = y_start;

    lv_obj_t *text_label = label_create(widget->text, &jetbrains_12, widget->color, text_label_x, text_label_y);

    /*-----------*/
    /* Left line */
    /*-----------*/
    unsigned int left_line_x_start = text_label_x - label_opacity,
        left_line_y_start = text_label_y + 4;

    widget->left_line_points[0].x = left_line_x_start;
    widget->left_line_points[0].y = left_line_y_start;

    widget->left_line_points[1].x = main_line_x_start;
    widget->left_line_points[1].y = left_line_y_start;

    widget->left_line_points[2].x = main_line_x_start;
    widget->left_line_points[2].y = left_line_y_start + label_space_length;

    lv_obj_t *left_out_line = line_create(widget->left_line_points, &widget->style, widget->color, 1, 3);

    /*------------*/
    /* Right line */
    /*------------*/
    unsigned int right_line_x_start = text_label_x + label_pixel_size + label_opacity,
        right_line_y_start = text_label_y + 4;

    widget->right_line_points[0].x = right_line_x_start;
    widget->right_line_points[0].y = right_line_y_start;

    widget->right_line_points[1].x = main_line_x_end;
    widget->right_line_points[1].y = right_line_y_start;

    widget->right_line_points[2].x = main_line_x_end;
    widget->right_line_points[2].y = right_line_y_start + label_space_length;

    lv_obj_t *right_out_line = line_create(widget->right_line_points, &widget->style, widget->color, 1, 3);

    /*--------------------*/
    /* Current data label */
    /*--------------------*/
    char* data_label_text = "test";
    unsigned int data_current_label_x = main_line_x_start + 10,
                data_current_label_y = text_label_y + (SCR_BORDER_OPACITY * 1.5f) + label_opacity;

    widget->data_current_label = label_create(data_label_text, &jetbrains_18, widget->color, data_current_label_x, data_current_label_y);

    /*----------------*/
    /* Min data label */
    /*----------------*/
    unsigned int data_min_label_x = main_line_x_start + 5,
                data_min_label_y = main_line_y_start + 7;

    widget->data_min_label = label_create(data_label_text, &jetbrains_12, widget->color, data_min_label_x, data_min_label_y);

    /*----------------*/
    /* Max data label */
    /*----------------*/
    unsigned int data_max_label_x = main_line_x_center + label_opacity,
                data_max_label_y = main_line_y_start + 7;

    widget->data_max_label = label_create(data_label_text, &jetbrains_12, widget->color, data_max_label_x, data_max_label_y);
}

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

    /*--------------------*/
    /* Frame-realted vars */
    /*--------------------*/
    unsigned char data_widget_x_length = 62,
        data_widget_y_length = 25;

    struct frame_widget outside_frame_widget = {
        .text = "Outside",
        .color = font_color,
    };

    frame_widget_create(
        &outside_frame_widget,
        SCR_BORDER_OPACITY,
        SCR_BORDER_OPACITY,
        SCR_WIDTH - SCR_BORDER_OPACITY,
        (SCR_HEIGHT - SCR_BORDER_OPACITY) / 2
    );

    /*---------------------------------*/
    /* Outside temperature data widget */
    /*---------------------------------*/
    unsigned int outside_temp_data_widget_x_start = SCR_BORDER_OPACITY * 2,
        outside_temp_data_widget_y_start = SCR_BORDER_OPACITY * 3,
        outside_temp_data_widget_x_end = outside_temp_data_widget_x_start + data_widget_x_length,
        outside_temp_data_widget_y_end = outside_temp_data_widget_y_start + data_widget_y_length;

    struct data_widget outside_temp_data_widget = {
        .text = "Temp",
        .color = font_color,
    };

    data_widget_create(
        &outside_temp_data_widget,
        outside_temp_data_widget_x_start,
        outside_temp_data_widget_y_start,
        outside_temp_data_widget_x_end,
        outside_temp_data_widget_y_end
    );

    /*------------------------------*/
    /* Outside humidity data widget */
    /*------------------------------*/
    unsigned int outside_hmdty_data_widget_x_start = outside_temp_data_widget_x_end + SCR_BORDER_OPACITY,
        outside_hmdty_data_widget_y_start = outside_temp_data_widget_y_start,
        outside_hmdty_data_widget_x_end = outside_hmdty_data_widget_x_start + data_widget_x_length,
        outside_hmdty_data_widget_y_end = outside_hmdty_data_widget_y_start + data_widget_y_length;

    struct data_widget outside_hmdty_data_widget = {
        .text = "Hmd",
        .color = font_color,
    };

    data_widget_create(
        &outside_hmdty_data_widget,
        outside_hmdty_data_widget_x_start,
        outside_hmdty_data_widget_y_start,
        outside_hmdty_data_widget_x_end,
        outside_hmdty_data_widget_y_end
    ); 

    /*--------------------------------*/
    /* Outside wind speed data widget */
    /*--------------------------------*/
    unsigned int outside_winds_data_widget_x_start = outside_hmdty_data_widget_x_end + SCR_BORDER_OPACITY + 1,
        outside_winds_data_widget_y_start = outside_hmdty_data_widget_y_start,
        outside_winds_data_widget_x_end = outside_winds_data_widget_x_start + data_widget_x_length,
        outside_winds_data_widget_y_end = outside_winds_data_widget_y_start + data_widget_y_length;

    struct data_widget outside_winds_data_widget = {
        .text = "Wind",
        .color = font_color,
    };

    data_widget_create(
        &outside_winds_data_widget,
        outside_winds_data_widget_x_start,
        outside_winds_data_widget_y_start,
        outside_winds_data_widget_x_end,
        outside_winds_data_widget_y_end
    ); 

    /*---------------------------------------*/
    /* Outside ultraviolet index data widget */
    /*---------------------------------------*/
    unsigned int outside_uvi_data_widget_x_start = outside_winds_data_widget_x_end + SCR_BORDER_OPACITY,
        outside_uvi_data_widget_y_start = outside_winds_data_widget_y_start,
        outside_uvi_data_widget_x_end = outside_uvi_data_widget_x_start + data_widget_x_length,
        outside_uvi_data_widget_y_end = outside_uvi_data_widget_y_start + data_widget_y_length;

    struct data_widget outside_uvi_data_widget = {
        .text = "Uvi",
        .color = font_color,
    };

    data_widget_create(
        &outside_uvi_data_widget,
        outside_uvi_data_widget_x_start,
        outside_uvi_data_widget_y_start,
        outside_uvi_data_widget_x_end,
        outside_uvi_data_widget_y_end
    );

    /*---------------------*/
    /* Inside frame widget */
    /*---------------------*/
    struct frame_widget inside_frame_widget = {
        .text = "Inside",
        .color = font_color,
    };

    frame_widget_create(
        &inside_frame_widget,
        SCR_BORDER_OPACITY,
        (SCR_HEIGHT / 2) + SCR_BORDER_OPACITY,
        (SCR_WIDTH - SCR_BORDER_OPACITY) / 2,
        SCR_HEIGHT - SCR_BORDER_OPACITY
    );

    /*-------------------*/
    /* Time frame widget */
    /*-------------------*/
    struct frame_widget time_frame_widget = {
        .text = "Time",
        .color = font_color,
    };

    frame_widget_create(
        &time_frame_widget,
        (SCR_WIDTH + SCR_BORDER_OPACITY) / 2,
        (SCR_HEIGHT / 2) + SCR_BORDER_OPACITY,
        SCR_WIDTH - SCR_BORDER_OPACITY,
        SCR_HEIGHT - SCR_BORDER_OPACITY
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

        lv_task_handler();
        k_sleep(K_MSEC(100));
    }
}
