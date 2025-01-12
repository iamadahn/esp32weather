#ifndef WIDGETS_H_
#define WIDGETS_H_

#include "lvgl.h"

#define DEFAULT_OUTLINE 10

#define JETBRAINS_14_WIDTH 8
#define JETBRAINS_12_WIDTH 7

struct frame_widget {
    lv_obj_t *parent;
    lv_obj_t *self;
    const lv_font_t *font;
    char *text;
    lv_point_t line_points[6];
    lv_style_t style;
    lv_color_t bg_color;
    lv_color_t font_color;
    unsigned int width;
    unsigned int height;
    lv_align_t align;
    lv_event_cb_t event_cb;
    lv_event_code_t event_code;
};

struct data_widget {
    lv_obj_t *parent;
    lv_obj_t *self;
    const lv_font_t *label_font;
    const lv_font_t *data_font;
    char *text;
    lv_obj_t *data_current_label;
    lv_obj_t *data_min_label;
    lv_obj_t *data_max_label;
    lv_point_t main_line_points[4];
    lv_point_t left_line_points[3];
    lv_point_t right_line_points[3];
    lv_style_t style;
    lv_color_t color;
    unsigned int width;
    unsigned int height;
    lv_align_t align;
    lv_event_cb_t event_cb;
    lv_event_code_t event_code;
};

struct data_min_widget {
    lv_obj_t *parent;
    lv_obj_t *self;
    const lv_font_t *font;
    char *text;
    lv_obj_t *data_label;
    lv_point_t left_line_points[3];
    lv_point_t right_line_points[3];
    lv_point_t bottom_line_points[2];
    lv_style_t style;
    lv_color_t color;
    unsigned int width;
    unsigned int height;
    lv_align_t align;
    lv_event_cb_t event_cb;
    lv_event_code_t event_code;
};

struct time_and_date_widget {
    lv_obj_t *parent;
    lv_obj_t *self;
    lv_obj_t *time_label;
    lv_obj_t *date_label;
    lv_obj_t *day_label;
    lv_font_t *font;
    lv_style_t style;
    lv_color_t color;
    unsigned int width;
    unsigned int height;
    lv_align_t align;
    lv_event_cb_t event_cb;
    lv_event_code_t event_code;
};

void frame_widget_create(struct frame_widget *widget,
                         unsigned int x_start,
                         unsigned int y_start,
                         unsigned int x_end,
                         unsigned int y_end);

void data_widget_create(struct data_widget *widget,
                        unsigned int x_start,
                        unsigned int y_start,
                        unsigned int x_end,
                        unsigned int y_end);

void data_min_widget_create(struct data_min_widget *widget,
                            unsigned int x_start,
                            unsigned int y_start,
                            unsigned int x_end,
                            unsigned int y_end);

void time_and_date_widget_create(struct time_and_date_widget *widget,
                                 unsigned int x_start,
                                 unsigned int y_start);

#endif
