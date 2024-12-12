/*******************************************************************************
 * Size: 14 px
 * Bpp: 4
 * Opts: --bpp 4 --size 14 --no-compress --font JetBrainsMonoNL-Regular.ttf --symbols 1234567890.,temphmduviawnosTEMPHMDUVIAWNOS%° --format lvgl -o jetbrains_14.c
 ******************************************************************************/
#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

#ifndef JETBRAINS_14
#define JETBRAINS_14 1
#endif

#if JETBRAINS_14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0025 "%" */
    0x4e, 0xf8, 0x0, 0x3c, 0xc, 0x61, 0xf1, 0xc,
    0x20, 0xc6, 0x1f, 0x19, 0x70, 0x4, 0xee, 0x84,
    0xc0, 0x0, 0x0, 0x1, 0xd1, 0x0, 0x0, 0x0,
    0xa8, 0xce, 0x70, 0x0, 0x5a, 0x98, 0x1f, 0x10,
    0x1d, 0x1b, 0x50, 0xd2, 0xb, 0x40, 0x97, 0xf,
    0x17, 0x90, 0x2, 0xde, 0x80,

    /* U+002C "," */
    0x1, 0x51, 0x7, 0xf0, 0xa, 0xc0, 0xc, 0x90,
    0xf, 0x50,

    /* U+002E "." */
    0x13, 0xd, 0xf3, 0xae, 0x20,

    /* U+0030 "0" */
    0x8, 0xef, 0xb2, 0x8, 0xd4, 0x2a, 0xe0, 0xc6,
    0x0, 0xf, 0x3e, 0x50, 0x0, 0xf4, 0xe5, 0x7d,
    0xf, 0x4e, 0x53, 0x70, 0xf4, 0xe5, 0x0, 0xf,
    0x4c, 0x60, 0x0, 0xf3, 0x8e, 0x42, 0xae, 0x0,
    0x8e, 0xfc, 0x30,

    /* U+0031 "1" */
    0x3, 0xef, 0x40, 0x6, 0xf7, 0xf4, 0x0, 0x93,
    0xf, 0x40, 0x0, 0x0, 0xf4, 0x0, 0x0, 0xf,
    0x40, 0x0, 0x0, 0xf4, 0x0, 0x0, 0xf, 0x40,
    0x0, 0x0, 0xf4, 0x0, 0x22, 0x2f, 0x62, 0x1b,
    0xff, 0xff, 0xf9,

    /* U+0032 "2" */
    0x8, 0xef, 0xb2, 0x8, 0xe4, 0x3b, 0xd0, 0xc6,
    0x0, 0x1f, 0x20, 0x0, 0x2, 0xf2, 0x0, 0x0,
    0xab, 0x0, 0x0, 0x8e, 0x10, 0x0, 0x8e, 0x20,
    0x0, 0x8e, 0x20, 0x0, 0x7f, 0x52, 0x22, 0x1c,
    0xff, 0xff, 0xf6,

    /* U+0033 "3" */
    0xb, 0xff, 0xff, 0xe0, 0x2, 0x22, 0x3e, 0x90,
    0x0, 0x1, 0xc9, 0x0, 0x0, 0xc, 0xc1, 0x0,
    0x0, 0xb, 0xcf, 0x50, 0x0, 0x0, 0x7, 0xe0,
    0x0, 0x0, 0x2, 0xf1, 0xd, 0x40, 0x3, 0xf1,
    0xa, 0xd3, 0x3c, 0xc0, 0x1, 0xae, 0xeb, 0x10,

    /* U+0034 "4" */
    0x0, 0x0, 0x9c, 0x0, 0x0, 0x3f, 0x30, 0x0,
    0xd, 0x90, 0x0, 0x7, 0xe1, 0x0, 0x1, 0xf5,
    0x6, 0xd0, 0xbc, 0x0, 0x6d, 0xf, 0x40, 0x6,
    0xd0, 0xff, 0xff, 0xfd, 0x2, 0x22, 0x28, 0xd0,
    0x0, 0x0, 0x6d,

    /* U+0035 "5" */
    0x9f, 0xff, 0xfd, 0x9, 0xa2, 0x22, 0x20, 0x99,
    0x0, 0x0, 0x9, 0xff, 0xeb, 0x20, 0x12, 0x23,
    0xcc, 0x0, 0x0, 0x2, 0xf1, 0x20, 0x0, 0xf,
    0x3d, 0x60, 0x2, 0xf1, 0x8e, 0x43, 0xbc, 0x0,
    0x8e, 0xea, 0x10,

    /* U+0036 "6" */
    0x0, 0x1, 0xf3, 0x0, 0x0, 0xa, 0x80, 0x0,
    0x0, 0x3c, 0x0, 0x0, 0x0, 0xdd, 0xfc, 0x30,
    0x5, 0xd2, 0x19, 0xe1, 0xd, 0x50, 0x0, 0xe6,
    0xf, 0x30, 0x0, 0xc7, 0xf, 0x60, 0x0, 0xe5,
    0xa, 0xe5, 0x3b, 0xd0, 0x0, 0x9e, 0xfb, 0x20,

    /* U+0037 "7" */
    0xdf, 0xff, 0xff, 0xad, 0x82, 0x22, 0xe8, 0xa5,
    0x0, 0x4f, 0x10, 0x0, 0xa, 0xb0, 0x0, 0x1,
    0xf4, 0x0, 0x0, 0x7d, 0x0, 0x0, 0xe, 0x70,
    0x0, 0x5, 0xf1, 0x0, 0x0, 0xba, 0x0, 0x0,
    0x2f, 0x30, 0x0,

    /* U+0038 "8" */
    0x0, 0x9e, 0xfc, 0x30, 0x8, 0xe4, 0x3a, 0xe0,
    0xc, 0x80, 0x1, 0xf2, 0x7, 0xd1, 0x8, 0xd0,
    0x0, 0x9f, 0xfd, 0x20, 0x8, 0xd4, 0x39, 0xd0,
    0xf, 0x40, 0x0, 0xe5, 0xf, 0x40, 0x0, 0xe6,
    0xa, 0xd4, 0x39, 0xf1, 0x0, 0x9e, 0xfc, 0x30,

    /* U+0039 "9" */
    0x0, 0x9e, 0xfc, 0x30, 0xa, 0xd4, 0x39, 0xe1,
    0xf, 0x40, 0x0, 0xd6, 0xf, 0x30, 0x0, 0xd6,
    0xb, 0xc2, 0x7, 0xf3, 0x1, 0xaf, 0xef, 0xc0,
    0x0, 0x0, 0x4f, 0x30, 0x0, 0x0, 0xda, 0x0,
    0x0, 0x6, 0xf1, 0x0, 0x0, 0xe, 0x70, 0x0,

    /* U+0041 "A" */
    0x0, 0xc, 0xf2, 0x0, 0x0, 0xf, 0xc7, 0x0,
    0x0, 0x4d, 0x7b, 0x0, 0x0, 0x99, 0x3f, 0x0,
    0x0, 0xd5, 0xe, 0x30, 0x1, 0xf1, 0xa, 0x80,
    0x5, 0xff, 0xff, 0xc0, 0xa, 0x92, 0x24, 0xf0,
    0xe, 0x50, 0x0, 0xe4, 0x2f, 0x10, 0x0, 0xb9,

    /* U+0044 "D" */
    0xbf, 0xff, 0xa1, 0xb, 0x92, 0x3c, 0xc0, 0xb8,
    0x0, 0x3f, 0x1b, 0x80, 0x1, 0xf2, 0xb8, 0x0,
    0x1f, 0x2b, 0x80, 0x1, 0xf2, 0xb8, 0x0, 0x1f,
    0x2b, 0x80, 0x3, 0xf1, 0xb9, 0x23, 0xcc, 0xb,
    0xff, 0xfa, 0x10,

    /* U+0045 "E" */
    0x9f, 0xff, 0xff, 0x49, 0xb2, 0x22, 0x20, 0x9a,
    0x0, 0x0, 0x9, 0xa0, 0x0, 0x0, 0x9f, 0xff,
    0xfc, 0x9, 0xb2, 0x22, 0x10, 0x9a, 0x0, 0x0,
    0x9, 0xa0, 0x0, 0x0, 0x9b, 0x22, 0x22, 0x9,
    0xff, 0xff, 0xf4,

    /* U+0048 "H" */
    0xb9, 0x0, 0x2f, 0x1b, 0x90, 0x2, 0xf1, 0xb9,
    0x0, 0x2f, 0x1b, 0x90, 0x2, 0xf1, 0xbf, 0xff,
    0xff, 0x1b, 0xa2, 0x24, 0xf1, 0xb9, 0x0, 0x2f,
    0x1b, 0x90, 0x2, 0xf1, 0xb9, 0x0, 0x2f, 0x1b,
    0x90, 0x2, 0xf1,

    /* U+0049 "I" */
    0x8f, 0xff, 0xff, 0x12, 0x8d, 0x22, 0x0, 0x7d,
    0x0, 0x0, 0x7d, 0x0, 0x0, 0x7d, 0x0, 0x0,
    0x7d, 0x0, 0x0, 0x7d, 0x0, 0x0, 0x7d, 0x0,
    0x12, 0x8d, 0x22, 0x8f, 0xff, 0xff,

    /* U+004D "M" */
    0xff, 0x0, 0xaf, 0x6f, 0xc5, 0xe, 0xc6, 0xf7,
    0x94, 0xac, 0x6f, 0x3e, 0x95, 0xc6, 0xf3, 0xbf,
    0xd, 0x6f, 0x34, 0x60, 0xd6, 0xf3, 0x0, 0xd,
    0x6f, 0x30, 0x0, 0xd6, 0xf3, 0x0, 0xd, 0x6f,
    0x30, 0x0, 0xd6,

    /* U+004E "N" */
    0xbf, 0x10, 0x1f, 0x2b, 0xf7, 0x1, 0xf2, 0xba,
    0xd0, 0x1f, 0x2b, 0x7e, 0x31, 0xf2, 0xb7, 0x89,
    0x1f, 0x2b, 0x72, 0xe1, 0xf2, 0xb7, 0xd, 0x5f,
    0x2b, 0x70, 0x7b, 0xf2, 0xb7, 0x1, 0xff, 0x2b,
    0x70, 0xb, 0xf2,

    /* U+004F "O" */
    0x8, 0xef, 0xb2, 0x6, 0xe5, 0x3b, 0xd0, 0xb8,
    0x0, 0x2f, 0x1c, 0x70, 0x1, 0xf2, 0xc7, 0x0,
    0x1f, 0x2c, 0x70, 0x1, 0xf2, 0xc7, 0x0, 0x1f,
    0x2b, 0x80, 0x2, 0xf1, 0x6e, 0x53, 0xbd, 0x0,
    0x8e, 0xfb, 0x20,

    /* U+0050 "P" */
    0xbf, 0xff, 0xd5, 0xb, 0x92, 0x27, 0xf4, 0xb8,
    0x0, 0xb, 0x9b, 0x80, 0x0, 0xaa, 0xb8, 0x0,
    0x4f, 0x5b, 0xff, 0xff, 0x80, 0xb9, 0x22, 0x0,
    0xb, 0x80, 0x0, 0x0, 0xb8, 0x0, 0x0, 0xb,
    0x80, 0x0, 0x0,

    /* U+0053 "S" */
    0x8, 0xef, 0xb2, 0x7, 0xe4, 0x3b, 0xd0, 0xb8,
    0x0, 0x19, 0x8, 0xc1, 0x0, 0x0, 0xb, 0xfb,
    0x60, 0x0, 0x2, 0x7d, 0xc0, 0x0, 0x0, 0x1f,
    0x4c, 0x40, 0x0, 0xe5, 0x9d, 0x42, 0x9f, 0x10,
    0x9e, 0xfc, 0x30,

    /* U+0054 "T" */
    0x3f, 0xff, 0xff, 0xfa, 0x2, 0x28, 0xd2, 0x21,
    0x0, 0x7, 0xd0, 0x0, 0x0, 0x7, 0xd0, 0x0,
    0x0, 0x7, 0xd0, 0x0, 0x0, 0x7, 0xd0, 0x0,
    0x0, 0x7, 0xd0, 0x0, 0x0, 0x7, 0xd0, 0x0,
    0x0, 0x7, 0xd0, 0x0, 0x0, 0x7, 0xd0, 0x0,

    /* U+0055 "U" */
    0xb8, 0x0, 0x2f, 0x2b, 0x80, 0x2, 0xf2, 0xb8,
    0x0, 0x2f, 0x2b, 0x80, 0x2, 0xf2, 0xb8, 0x0,
    0x2f, 0x2b, 0x80, 0x2, 0xf2, 0xb8, 0x0, 0x2f,
    0x2a, 0x90, 0x3, 0xf1, 0x6e, 0x43, 0xbd, 0x0,
    0x8e, 0xfb, 0x20,

    /* U+0056 "V" */
    0x2f, 0x10, 0x0, 0xb9, 0xe, 0x50, 0x0, 0xf4,
    0xa, 0xa0, 0x3, 0xf0, 0x6, 0xe0, 0x7, 0xc0,
    0x1, 0xf2, 0xb, 0x80, 0x0, 0xd6, 0xf, 0x30,
    0x0, 0x9a, 0x3f, 0x0, 0x0, 0x5e, 0x7b, 0x0,
    0x0, 0x1f, 0xc7, 0x0, 0x0, 0xc, 0xf2, 0x0,

    /* U+0057 "W" */
    0xa7, 0x8, 0xf0, 0xf, 0x8, 0x90, 0xae, 0x12,
    0xe0, 0x6b, 0xc, 0xb3, 0x4c, 0x4, 0xd0, 0xd8,
    0x56, 0xa0, 0x2e, 0xc, 0x67, 0x78, 0x0, 0xf3,
    0xa4, 0x99, 0x60, 0xe, 0x78, 0x2b, 0xb4, 0x0,
    0xcb, 0x60, 0xdd, 0x20, 0xa, 0xe4, 0xd, 0xe0,
    0x0, 0x9f, 0x20, 0xce, 0x0,

    /* U+0061 "a" */
    0x0, 0x9e, 0xfc, 0x20, 0x8, 0xd3, 0x29, 0xd0,
    0x0, 0x0, 0x2, 0xf1, 0x2, 0xcf, 0xff, 0xf1,
    0xd, 0x90, 0x2, 0xf1, 0xf, 0x40, 0x3, 0xf1,
    0xd, 0xa2, 0x3b, 0xf1, 0x2, 0xcf, 0xd5, 0xf1,

    /* U+0064 "d" */
    0x0, 0x0, 0x2f, 0x10, 0x0, 0x2, 0xf1, 0xa,
    0xfd, 0x6f, 0x17, 0xe4, 0x3a, 0xf1, 0xb8, 0x0,
    0x3f, 0x1c, 0x70, 0x2, 0xf1, 0xc7, 0x0, 0x2f,
    0x1b, 0x80, 0x3, 0xf1, 0x7e, 0x42, 0xaf, 0x10,
    0xaf, 0xd6, 0xf1,

    /* U+0065 "e" */
    0x7, 0xef, 0xb2, 0x6, 0xd3, 0x19, 0xe0, 0xb7,
    0x0, 0xf, 0x2d, 0xff, 0xff, 0xf3, 0xd6, 0x0,
    0x0, 0xb, 0x80, 0x0, 0x40, 0x6e, 0x42, 0x9e,
    0x0, 0x8e, 0xfb, 0x20,

    /* U+0068 "h" */
    0xb8, 0x0, 0x0, 0xb, 0x80, 0x0, 0x0, 0xb9,
    0xbf, 0xc3, 0xb, 0xe4, 0x2b, 0xd0, 0xba, 0x0,
    0x3f, 0x1b, 0x80, 0x2, 0xf2, 0xb8, 0x0, 0x2f,
    0x2b, 0x80, 0x2, 0xf2, 0xb8, 0x0, 0x2f, 0x2b,
    0x80, 0x2, 0xf2,

    /* U+0069 "i" */
    0x0, 0x16, 0x0, 0x0, 0x8, 0xf5, 0x0, 0x0,
    0x3, 0x0, 0x8, 0xff, 0xf3, 0x0, 0x12, 0x3f,
    0x30, 0x0, 0x1, 0xf3, 0x0, 0x0, 0x1f, 0x30,
    0x0, 0x1, 0xf3, 0x0, 0x0, 0x1f, 0x30, 0x2,
    0x23, 0xf5, 0x22, 0xdf, 0xff, 0xff, 0xc0,

    /* U+006D "m" */
    0x2f, 0xae, 0x6c, 0xd1, 0x2f, 0x27, 0xd0, 0xb7,
    0x2f, 0x5, 0xb0, 0x98, 0x2f, 0x5, 0xb0, 0x99,
    0x2f, 0x5, 0xb0, 0x99, 0x2f, 0x5, 0xb0, 0x99,
    0x2f, 0x5, 0xb0, 0x99, 0x2f, 0x5, 0xb0, 0x99,

    /* U+006E "n" */
    0xb9, 0xbf, 0xc3, 0xb, 0xd2, 0x9, 0xd0, 0xb9,
    0x0, 0x2f, 0x1b, 0x80, 0x2, 0xf2, 0xb8, 0x0,
    0x2f, 0x2b, 0x80, 0x2, 0xf2, 0xb8, 0x0, 0x2f,
    0x2b, 0x80, 0x2, 0xf2,

    /* U+006F "o" */
    0x8, 0xef, 0xb2, 0x6, 0xe4, 0x3a, 0xd0, 0xb8,
    0x0, 0x1f, 0x1d, 0x70, 0x0, 0xf3, 0xd7, 0x0,
    0xf, 0x3b, 0x80, 0x1, 0xf1, 0x6e, 0x43, 0xad,
    0x0, 0x8e, 0xfb, 0x20,

    /* U+0070 "p" */
    0xb9, 0xbf, 0xd3, 0xb, 0xd3, 0x8, 0xe0, 0xb9,
    0x0, 0x1f, 0x2b, 0x80, 0x1, 0xf3, 0xb8, 0x0,
    0x1f, 0x3b, 0xa0, 0x2, 0xf2, 0xbd, 0x52, 0xae,
    0xb, 0x9b, 0xfd, 0x30, 0xb8, 0x0, 0x0, 0xb,
    0x80, 0x0, 0x0, 0xb8, 0x0, 0x0, 0x0,

    /* U+0073 "s" */
    0x1b, 0xff, 0xd4, 0x9, 0xc2, 0x18, 0xe0, 0xaa,
    0x0, 0x0, 0x4, 0xfd, 0xb8, 0x10, 0x2, 0x57,
    0xce, 0x3, 0x10, 0x1, 0xf2, 0xac, 0x21, 0x7f,
    0x1, 0xbf, 0xfd, 0x50,

    /* U+0074 "t" */
    0x0, 0x2f, 0x20, 0x0, 0x0, 0x2f, 0x20, 0x0,
    0x5f, 0xff, 0xff, 0xf4, 0x2, 0x4f, 0x42, 0x20,
    0x0, 0x2f, 0x20, 0x0, 0x0, 0x2f, 0x20, 0x0,
    0x0, 0x2f, 0x20, 0x0, 0x0, 0x1f, 0x20, 0x0,
    0x0, 0xf, 0x72, 0x20, 0x0, 0x6, 0xef, 0xf3,

    /* U+0075 "u" */
    0xb8, 0x0, 0x2f, 0x2b, 0x80, 0x2, 0xf2, 0xb8,
    0x0, 0x2f, 0x2b, 0x80, 0x2, 0xf2, 0xb8, 0x0,
    0x2f, 0x2a, 0x90, 0x3, 0xf0, 0x5f, 0x53, 0xbc,
    0x0, 0x7e, 0xfb, 0x10,

    /* U+0076 "v" */
    0x1f, 0x40, 0x0, 0xd7, 0xc, 0x90, 0x2, 0xf2,
    0x6, 0xe0, 0x7, 0xd0, 0x1, 0xf3, 0xc, 0x70,
    0x0, 0xc8, 0x1f, 0x20, 0x0, 0x7d, 0x6d, 0x0,
    0x0, 0x1f, 0xc8, 0x0, 0x0, 0xc, 0xf3, 0x0,

    /* U+0077 "w" */
    0x79, 0x8, 0xe0, 0x2e, 0x5b, 0xb, 0xd1, 0x4b,
    0x2e, 0xd, 0xa4, 0x68, 0xf, 0x1d, 0x76, 0x96,
    0xd, 0x5a, 0x49, 0xb3, 0xb, 0xa7, 0x2c, 0xd1,
    0x8, 0xe5, 0xe, 0xd0, 0x6, 0xf2, 0xd, 0xb0,

    /* U+00B0 "°" */
    0x3b, 0xc7, 0xc, 0x30, 0xc2, 0xc3, 0xc, 0x23,
    0xbc, 0x70
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 134, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 45, .adv_w = 134, .box_w = 4, .box_h = 5, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 55, .adv_w = 134, .box_w = 3, .box_h = 3, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 60, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 95, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 315, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 390, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 470, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 505, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 540, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 575, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 605, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 640, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 675, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 710, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 745, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 780, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 820, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 855, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 895, .adv_w = 134, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 940, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 972, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1007, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1035, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1070, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1109, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1141, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1169, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1197, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1236, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1264, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1304, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1332, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1364, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1396, .adv_w = 134, .box_w = 5, .box_h = 4, .ofs_x = 2, .ofs_y = 6}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x7, 0x9, 0xb, 0xc, 0xd, 0xe, 0xf,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x1c, 0x1f, 0x20,
    0x23, 0x24, 0x28, 0x29, 0x2a, 0x2b, 0x2e, 0x2f,
    0x30, 0x31, 0x32, 0x3c, 0x3f, 0x40, 0x43, 0x44,
    0x48, 0x49, 0x4a, 0x4b, 0x4e, 0x4f, 0x50, 0x51,
    0x52, 0x8b
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 37, .range_length = 140, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 42, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

extern const lv_font_t lv_font_montserrat_14;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t jetbrains_14 = {
#else
lv_font_t jetbrains_14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_14,
#endif
    .user_data = NULL,
};



#endif /*#if JETBRAINS_14*/

