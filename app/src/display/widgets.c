#include "widgets.h"

static lv_obj_t* label_create(lv_obj_t *parent,
                              char *text,
                              const lv_font_t *font,
                              lv_color_t color,
                              lv_align_t align,
                              unsigned short x,
                              unsigned short y)
{
    lv_obj_t* label;
    label = lv_label_create(parent);
    lv_label_set_text(label, text);
    lv_obj_set_style_text_font(label, font, 0);
    lv_obj_set_style_text_color(label, color, 0);
    lv_obj_align(label, align, x, y);

    return label;
}

static lv_obj_t* line_create(lv_obj_t *parent,
                             lv_point_t *points,
                             lv_style_t *style,
                             lv_color_t color,
                             unsigned char width,
                             unsigned char points_num,
                             lv_align_t align,
                             unsigned int x,
                             unsigned int y)
{
    lv_style_set_line_width(style, width);
    lv_style_set_line_rounded(style, true);

    lv_obj_t* line;
    line = lv_line_create(parent);
    lv_line_set_points(line, points, points_num);
    lv_obj_add_style(line, style, 0);
    lv_obj_align(line, align, x, y);

    return line;
}

void frame_widget_create(struct frame_widget *widget,
                                unsigned int width,
                                unsigned int height,
                                unsigned int x_start,
                                unsigned int y_start)
{
    widget->self = lv_obj_create(widget->parent);
    lv_obj_align(widget->self, widget->align, x_start, y_start);
    lv_obj_set_width(widget->self, width);
    lv_obj_set_height(widget->self, height);
    lv_obj_set_style_border_width(widget->self, 0, 0);
    lv_obj_set_style_outline_width(widget->self, 0, 0);
    lv_obj_set_style_outline_pad(widget->self, 0, 0);
    lv_obj_set_style_pad_top(widget->self, 0, 0);
    lv_obj_set_style_pad_left(widget->self, 0, 0);
    lv_obj_set_style_radius(widget->self, 0, 0);
    lv_obj_set_style_bg_color(widget->self, widget->bg_color, 0);
    lv_obj_clear_flag(widget->self, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_event_cb(widget->self, widget->event_cb, widget->event_code, NULL);

    unsigned char label_opacity = 5;
    unsigned char label_pixel_size = strlen(widget->text) * JETBRAINS_14_WIDTH;
    unsigned int label_x_start = DEFAULT_OUTLINE + (label_opacity * 2), label_y_start = 5;

    lv_obj_t *label = label_create(widget->self,
                                   widget->text,
                                   widget->font,
                                   widget->font_color,
                                   widget->align,
                                   label_x_start,
                                   label_y_start);

    unsigned short line_x_start = label_x_start - label_opacity,
        line_x_end = label_x_start + label_pixel_size + label_opacity,
        line_y_start = DEFAULT_OUTLINE,
        line_y_end = height - DEFAULT_OUTLINE;

    widget->line_points[0].x = line_x_start;
    widget->line_points[0].y = line_y_start;

    widget->line_points[1].x = DEFAULT_OUTLINE;
    widget->line_points[1].y = line_y_start;

    widget->line_points[2].x = DEFAULT_OUTLINE;
    widget->line_points[2].y = line_y_end;

    widget->line_points[3].x = width - DEFAULT_OUTLINE;
    widget->line_points[3].y = line_y_end;

    widget->line_points[4].x = width - DEFAULT_OUTLINE;
    widget->line_points[4].y = line_y_start;

    widget->line_points[5].x = line_x_end;
    widget->line_points[5].y = line_y_start;

    lv_style_init(&widget->style);
    lv_obj_t *line = line_create(widget->self,
                                 widget->line_points,
                                 &widget->style,
                                 widget->font_color,
                                 2,
                                 6,
                                 widget->align,
                                 0,
                                 0);
} 

void data_widget_create(struct data_widget *widget,
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
    lv_obj_t *main_line = line_create(widget->parent,
                                      widget->main_line_points,
                                      &widget->style, widget->color,
                                      1,
                                      4,
                                      widget->align,
                                      0,
                                      0);

    /*------------*/
    /* Text label */
    /*------------*/
    unsigned char label_pixel_size = strlen(widget->text) * JETBRAINS_12_WIDTH;
    unsigned char label_space_length = 5;
    unsigned char label_opacity = 2;

    unsigned int text_label_x = main_line_x_start + label_space_length + label_opacity,
        text_label_y = y_start;

    lv_obj_t *text_label = label_create(widget->parent,
                                        widget->text,
                                        widget->label_font,
                                        widget->color,
                                        widget->align,
                                        text_label_x,
                                        text_label_y);

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

    lv_obj_t *left_out_line = line_create(widget->parent,
                                          widget->left_line_points,
                                          &widget->style,
                                          widget->color,
                                          1,
                                          3,
                                          widget->align,
                                          0,
                                          0);

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

    lv_obj_t *right_out_line = line_create(widget->parent,
                                           widget->right_line_points,
                                           &widget->style,
                                           widget->color,
                                           1,
                                           3,
                                           widget->align,
                                           0,
                                           0);

    /*--------------------*/
    /* Current data label */
    /*--------------------*/
    char* data_label_text = "test";
    unsigned int data_current_label_x = main_line_x_start + 10,
                data_current_label_y = text_label_y + (DEFAULT_OUTLINE * 1.5f) + label_opacity;

    widget->data_current_label = label_create(widget->parent,
                                              data_label_text,
                                              widget->data_font,
                                              widget->color,
                                              widget->align,
                                              data_current_label_x,
                                              data_current_label_y);

    /*----------------*/
    /* Min data label */
    /*----------------*/
    unsigned int data_min_label_x = main_line_x_start + 5,
                data_min_label_y = main_line_y_start + 7;

    widget->data_min_label = label_create(widget->parent,
                                          data_label_text,
                                          widget->label_font,
                                          widget->color,
                                          widget->align,
                                          data_min_label_x,
                                          data_min_label_y);

    /*----------------*/
    /* Max data label */
    /*----------------*/
    unsigned int data_max_label_x = main_line_x_center + label_opacity,
                data_max_label_y = main_line_y_start + 7;

    widget->data_max_label = label_create(widget->parent,
                                          data_label_text,
                                          widget->label_font,
                                          widget->color,
                                          widget->align,
                                          data_max_label_x,
                                          data_max_label_y);
}

void data_min_widget_create(struct data_min_widget *widget,
                                   unsigned int x_start,
                                   unsigned int y_start,
                                   unsigned int x_end,
                                   unsigned int y_end)
{
    /*------------*/
    /* Text label */
    /*------------*/
    unsigned char label_pixel_size = strlen(widget->text) * JETBRAINS_12_WIDTH;
    unsigned char label_space_length = 5;
    unsigned char label_opacity = 2;

    unsigned int text_label_x = x_start + label_space_length + label_opacity,
        text_label_y = y_start;

    lv_style_init(&widget->style);

    lv_obj_t *text_label = label_create(widget->parent,
                                        widget->text,
                                        widget->font,
                                        widget->color,
                                        widget->align,
                                        text_label_x,
                                        text_label_y);

    /*-----------*/
    /* Left line */
    /*-----------*/
    unsigned int left_line_x_start = text_label_x - label_opacity,
        left_line_y_start = text_label_y + 4;

    widget->left_line_points[0].x = left_line_x_start;
    widget->left_line_points[0].y = left_line_y_start;

    widget->left_line_points[1].x = x_start;
    widget->left_line_points[1].y = left_line_y_start;

    widget->left_line_points[2].x = x_start;
    widget->left_line_points[2].y = left_line_y_start + label_space_length;

    lv_obj_t *left_out_line = line_create(widget->parent,
                                          widget->left_line_points,
                                          &widget->style,
                                          widget->color,
                                          1,
                                          3,
                                          widget->align,
                                          0,
                                          0);

    /*------------*/
    /* Right line */
    /*------------*/
    unsigned int right_line_x_start = text_label_x + label_pixel_size + label_opacity,
        right_line_y_start = text_label_y + 4;

    widget->right_line_points[0].x = right_line_x_start;
    widget->right_line_points[0].y = right_line_y_start;

    widget->right_line_points[1].x = x_end;
    widget->right_line_points[1].y = right_line_y_start;

    widget->right_line_points[2].x = x_end;
    widget->right_line_points[2].y = right_line_y_start + label_space_length;

    lv_obj_t *right_out_line = line_create(widget->parent,
                                           widget->right_line_points,
                                           &widget->style,
                                           widget->color,
                                           1,
                                           3,
                                           widget->align,
                                           0,
                                           0);

    /*-------------*/
    /* Bottom line */
    /*-------------*/
    widget->bottom_line_points[0].x = x_start;
    widget->bottom_line_points[0].y = y_end;

    widget->bottom_line_points[1].x = x_end;
    widget->bottom_line_points[1].y = y_end;

    lv_obj_t *bottom_out_line = line_create(widget->parent,
                                            widget->bottom_line_points,
                                            &widget->style,
                                            widget->color,
                                            1,
                                            2,
                                            widget->align,
                                            0,
                                            0);

    /*------------*/
    /* Data label */
    /*------------*/
    char* data_label_text = "0";
    unsigned int data_label_x = x_start,
                data_label_y = y_end - (DEFAULT_OUTLINE * 3);

    widget->data_label = label_create(widget->parent,
                                      data_label_text,
                                      &lv_font_montserrat_28,
                                      widget->color,
                                      widget->align,
                                      data_label_x,
                                      data_label_y);
}

void time_and_date_widget_create(struct time_and_date_widget *widget,
                                        unsigned int x_start,
                                        unsigned int y_start)
{
    /*------------*/
    /* Time label */
    /*------------*/
    char* time_label_text = "13:37";

    widget->time_label = label_create(widget->parent,
                                      time_label_text,
                                      &lv_font_montserrat_28,
                                      widget->color,
                                      widget->align,
                                      x_start + (DEFAULT_OUTLINE * 3),
                                      y_start);

    /*------------*/
    /* Date label */
    /*------------*/
    char* date_label_text = "28.06.2021";

    widget->date_label = label_create(widget->parent,
                                      date_label_text,
                                      &lv_font_montserrat_24,
                                      widget->color,
                                      widget->align,
                                      x_start,
                                      y_start + (DEFAULT_OUTLINE * 2.5f));

    /*-----------*/
    /* Day label */
    /*-----------*/
    char* day_label_text = "Saturday";

    widget->day_label = label_create(widget->parent,
                                     day_label_text,
                                     &lv_font_montserrat_24,
                                     widget->color,
                                     widget->align,
                                     x_start + 5,
                                     y_start + (DEFAULT_OUTLINE * 4.5f));
}

