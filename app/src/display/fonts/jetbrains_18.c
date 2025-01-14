/*******************************************************************************
 * Size: 18 px
 * Bpp: 4
 * Opts: --bpp 4 --size 18 --no-compress --font JetBrainsMonoNL-Regular.ttf --symbols 1234567890.,temphmduviawnoTEMPHMDUVIAWNO%° --format lvgl -o jetbrains_18.c
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

#ifndef JETBRAINS_18
#define JETBRAINS_18 1
#endif

#if JETBRAINS_18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0025 "%" */
    0xa, 0xfd, 0x50, 0x0, 0x2f, 0x38, 0xe4, 0x8f,
    0x10, 0xc, 0x80, 0xba, 0x1, 0xf4, 0x8, 0xc0,
    0xb, 0x90, 0x1f, 0x43, 0xf2, 0x0, 0x9d, 0x15,
    0xf2, 0xd7, 0x0, 0x2, 0xdf, 0xf8, 0x9b, 0x0,
    0x0, 0x0, 0x21, 0x4f, 0x10, 0x0, 0x0, 0x0,
    0x1e, 0x58, 0xef, 0x90, 0x0, 0xa, 0xa4, 0xf6,
    0x5f, 0x50, 0x5, 0xe1, 0x7d, 0x0, 0xc8, 0x1,
    0xe4, 0x7, 0xd0, 0xc, 0x80, 0xb9, 0x0, 0x4f,
    0x44, 0xf5, 0x6d, 0x0, 0x0, 0x8e, 0xe8, 0x0,

    /* U+002C "," */
    0x2, 0x74, 0x6, 0xf7, 0x9, 0xf4, 0xc, 0xf0,
    0xf, 0xc0, 0x2f, 0x90,

    /* U+002E "." */
    0x8, 0xd5, 0xf, 0xfd, 0xa, 0xf7,

    /* U+0030 "0" */
    0x1, 0x9e, 0xfd, 0x80, 0x0, 0xdf, 0x96, 0xaf,
    0xa0, 0x5f, 0x50, 0x0, 0x9f, 0x28, 0xf0, 0x0,
    0x4, 0xf5, 0x9f, 0x0, 0x0, 0x3f, 0x59, 0xf0,
    0x7f, 0x43, 0xf5, 0x9f, 0x8, 0xf4, 0x3f, 0x59,
    0xf0, 0x0, 0x3, 0xf5, 0x9f, 0x0, 0x0, 0x3f,
    0x58, 0xf0, 0x0, 0x4, 0xf5, 0x6f, 0x50, 0x0,
    0x9f, 0x20, 0xdf, 0x96, 0xaf, 0xa0, 0x1, 0x9d,
    0xfd, 0x80, 0x0,

    /* U+0031 "1" */
    0x0, 0x3d, 0xfc, 0x0, 0x0, 0x7f, 0xde, 0xc0,
    0x0, 0x5f, 0xa0, 0xdc, 0x0, 0x5, 0x50, 0xd,
    0xc0, 0x0, 0x0, 0x0, 0xdc, 0x0, 0x0, 0x0,
    0xd, 0xc0, 0x0, 0x0, 0x0, 0xdc, 0x0, 0x0,
    0x0, 0xd, 0xc0, 0x0, 0x0, 0x0, 0xdc, 0x0,
    0x0, 0x0, 0xd, 0xc0, 0x0, 0x0, 0x0, 0xdc,
    0x0, 0x2, 0x77, 0x7e, 0xe7, 0x75, 0x6f, 0xff,
    0xff, 0xff, 0xb0,

    /* U+0032 "2" */
    0x1, 0x9e, 0xfd, 0x70, 0x0, 0xdf, 0x97, 0xbf,
    0xa0, 0x6f, 0x50, 0x0, 0xaf, 0x27, 0xc0, 0x0,
    0x6, 0xf4, 0x0, 0x0, 0x0, 0x7f, 0x30, 0x0,
    0x0, 0xd, 0xd0, 0x0, 0x0, 0xa, 0xf4, 0x0,
    0x0, 0x9, 0xf6, 0x0, 0x0, 0x8, 0xf7, 0x0,
    0x0, 0x8, 0xf8, 0x0, 0x0, 0x7, 0xf8, 0x0,
    0x0, 0x5, 0xfe, 0x77, 0x77, 0x73, 0x7f, 0xff,
    0xff, 0xff, 0x70,

    /* U+0033 "3" */
    0x6f, 0xff, 0xff, 0xfd, 0x2, 0x77, 0x77, 0x9f,
    0xb0, 0x0, 0x0, 0x1e, 0xc1, 0x0, 0x0, 0x1d,
    0xd1, 0x0, 0x0, 0x1d, 0xf2, 0x0, 0x0, 0x3,
    0xff, 0xfa, 0x0, 0x0, 0x2, 0x38, 0xfa, 0x0,
    0x0, 0x0, 0xa, 0xf0, 0x0, 0x0, 0x0, 0x7f,
    0x27, 0xa0, 0x0, 0x7, 0xf2, 0x8f, 0x30, 0x0,
    0xcf, 0x2, 0xff, 0x87, 0xcf, 0x80, 0x2, 0xae,
    0xfc, 0x50, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x4f, 0x90, 0x0, 0x0, 0xde, 0x0,
    0x0, 0x7, 0xf5, 0x0, 0x0, 0x2f, 0xb0, 0x0,
    0x0, 0xbf, 0x20, 0x0, 0x5, 0xf7, 0x0, 0x66,
    0xe, 0xd0, 0x0, 0xcd, 0x8f, 0x40, 0x0, 0xcd,
    0xbe, 0x22, 0x22, 0xdd, 0xbf, 0xff, 0xff, 0xfd,
    0x35, 0x55, 0x55, 0xdd, 0x0, 0x0, 0x0, 0xcd,
    0x0, 0x0, 0x0, 0xcd,

    /* U+0035 "5" */
    0x3f, 0xff, 0xff, 0xfc, 0x3, 0xfa, 0x77, 0x77,
    0x50, 0x3f, 0x50, 0x0, 0x0, 0x3, 0xf5, 0x0,
    0x0, 0x0, 0x3f, 0x62, 0x10, 0x0, 0x3, 0xff,
    0xff, 0xfa, 0x10, 0x15, 0x55, 0x59, 0xfb, 0x0,
    0x0, 0x0, 0x9, 0xf1, 0x0, 0x0, 0x0, 0x5f,
    0x36, 0xa0, 0x0, 0x6, 0xf3, 0x7f, 0x40, 0x0,
    0xaf, 0x11, 0xef, 0x97, 0xbf, 0x90, 0x1, 0xae,
    0xfd, 0x60, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0xde, 0x0, 0x0, 0x0, 0x7f, 0x50,
    0x0, 0x0, 0x1f, 0xb0, 0x0, 0x0, 0x9, 0xf2,
    0x0, 0x0, 0x2, 0xf9, 0x0, 0x0, 0x0, 0xbf,
    0xcf, 0xfa, 0x10, 0x3f, 0xe6, 0x47, 0xfd, 0x9,
    0xf2, 0x0, 0x5, 0xf6, 0xcd, 0x0, 0x0, 0xf,
    0x9c, 0xd0, 0x0, 0x1, 0xf9, 0x8f, 0x40, 0x0,
    0x7f, 0x41, 0xdf, 0x97, 0xaf, 0xb0, 0x1, 0x9e,
    0xfd, 0x70, 0x0,

    /* U+0037 "7" */
    0x8f, 0xff, 0xff, 0xff, 0xd8, 0xf8, 0x77, 0x77,
    0xfc, 0x8f, 0x10, 0x0, 0x5f, 0x64, 0x90, 0x0,
    0xb, 0xf0, 0x0, 0x0, 0x2, 0xf9, 0x0, 0x0,
    0x0, 0x8f, 0x30, 0x0, 0x0, 0xe, 0xc0, 0x0,
    0x0, 0x5, 0xf6, 0x0, 0x0, 0x0, 0xcf, 0x0,
    0x0, 0x0, 0x2f, 0x90, 0x0, 0x0, 0x9, 0xf3,
    0x0, 0x0, 0x0, 0xec, 0x0, 0x0, 0x0, 0x6f,
    0x60, 0x0, 0x0,

    /* U+0038 "8" */
    0x1, 0x9e, 0xfd, 0x80, 0x0, 0xef, 0x97, 0xaf,
    0xb0, 0x5f, 0x60, 0x0, 0x9f, 0x25, 0xf4, 0x0,
    0x7, 0xf2, 0xd, 0xd4, 0x25, 0xea, 0x0, 0x1b,
    0xff, 0xf9, 0x0, 0xc, 0xf7, 0x59, 0xfa, 0x7,
    0xf3, 0x0, 0x7, 0xf4, 0xbe, 0x0, 0x0, 0x1f,
    0x8c, 0xe0, 0x0, 0x1, 0xf8, 0x8f, 0x50, 0x0,
    0x8f, 0x41, 0xdf, 0x97, 0xbf, 0xb0, 0x1, 0x9e,
    0xfd, 0x80, 0x0,

    /* U+0039 "9" */
    0x1, 0x9e, 0xfd, 0x70, 0x0, 0xdf, 0xa7, 0xbf,
    0xb0, 0x7f, 0x50, 0x0, 0x8f, 0x5c, 0xe0, 0x0,
    0x1, 0xf9, 0xcd, 0x0, 0x0, 0xf, 0x9a, 0xf1,
    0x0, 0x4, 0xf6, 0x3f, 0xc3, 0x14, 0xef, 0x0,
    0x5e, 0xff, 0xef, 0x80, 0x0, 0x2, 0x2c, 0xe0,
    0x0, 0x0, 0x6, 0xf6, 0x0, 0x0, 0x1, 0xed,
    0x0, 0x0, 0x0, 0x9f, 0x40, 0x0, 0x0, 0x3f,
    0xb0, 0x0, 0x0,

    /* U+0041 "A" */
    0x0, 0x0, 0xdf, 0xa0, 0x0, 0x0, 0x1, 0xfe,
    0xe0, 0x0, 0x0, 0x5, 0xf7, 0xf2, 0x0, 0x0,
    0x9, 0xe1, 0xf6, 0x0, 0x0, 0xd, 0xa0, 0xda,
    0x0, 0x0, 0x2f, 0x50, 0x9e, 0x0, 0x0, 0x6f,
    0x10, 0x4f, 0x30, 0x0, 0xae, 0x11, 0x2f, 0x70,
    0x0, 0xef, 0xff, 0xff, 0xb0, 0x2, 0xf8, 0x44,
    0x4a, 0xf0, 0x7, 0xf2, 0x0, 0x5, 0xf3, 0xb,
    0xe0, 0x0, 0x1, 0xf8, 0xf, 0xa0, 0x0, 0x0,
    0xdc,

    /* U+0044 "D" */
    0x5f, 0xff, 0xfc, 0x50, 0x5, 0xf9, 0x67, 0xdf,
    0x60, 0x5f, 0x40, 0x0, 0xce, 0x5, 0xf4, 0x0,
    0x7, 0xf2, 0x5f, 0x40, 0x0, 0x6f, 0x35, 0xf4,
    0x0, 0x6, 0xf3, 0x5f, 0x40, 0x0, 0x6f, 0x35,
    0xf4, 0x0, 0x6, 0xf3, 0x5f, 0x40, 0x0, 0x6f,
    0x35, 0xf4, 0x0, 0x7, 0xf2, 0x5f, 0x40, 0x0,
    0xce, 0x5, 0xf9, 0x67, 0xcf, 0x60, 0x5f, 0xff,
    0xfc, 0x50, 0x0,

    /* U+0045 "E" */
    0x3f, 0xff, 0xff, 0xff, 0x53, 0xfa, 0x77, 0x77,
    0x72, 0x3f, 0x60, 0x0, 0x0, 0x3, 0xf6, 0x0,
    0x0, 0x0, 0x3f, 0x60, 0x0, 0x0, 0x3, 0xf7,
    0x11, 0x11, 0x10, 0x3f, 0xff, 0xff, 0xfb, 0x3,
    0xf9, 0x44, 0x44, 0x30, 0x3f, 0x60, 0x0, 0x0,
    0x3, 0xf6, 0x0, 0x0, 0x0, 0x3f, 0x60, 0x0,
    0x0, 0x3, 0xfa, 0x77, 0x77, 0x72, 0x3f, 0xff,
    0xff, 0xff, 0x50,

    /* U+0048 "H" */
    0x5f, 0x40, 0x0, 0x8f, 0x25, 0xf4, 0x0, 0x8,
    0xf2, 0x5f, 0x40, 0x0, 0x8f, 0x25, 0xf4, 0x0,
    0x8, 0xf2, 0x5f, 0x40, 0x0, 0x8f, 0x25, 0xf6,
    0x22, 0x29, 0xf2, 0x5f, 0xff, 0xff, 0xff, 0x25,
    0xf8, 0x55, 0x5a, 0xf2, 0x5f, 0x40, 0x0, 0x8f,
    0x25, 0xf4, 0x0, 0x8, 0xf2, 0x5f, 0x40, 0x0,
    0x8f, 0x25, 0xf4, 0x0, 0x8, 0xf2, 0x5f, 0x40,
    0x0, 0x8f, 0x20,

    /* U+0049 "I" */
    0x1f, 0xff, 0xff, 0xfe, 0x7, 0x7a, 0xf9, 0x76,
    0x0, 0x6, 0xf3, 0x0, 0x0, 0x6, 0xf3, 0x0,
    0x0, 0x6, 0xf3, 0x0, 0x0, 0x6, 0xf3, 0x0,
    0x0, 0x6, 0xf3, 0x0, 0x0, 0x6, 0xf3, 0x0,
    0x0, 0x6, 0xf3, 0x0, 0x0, 0x6, 0xf3, 0x0,
    0x0, 0x6, 0xf3, 0x0, 0x7, 0x7b, 0xf9, 0x76,
    0x1f, 0xff, 0xff, 0xfe,

    /* U+004D "M" */
    0xbf, 0xd0, 0x1, 0xff, 0x8b, 0xcf, 0x20, 0x5d,
    0xe8, 0xbb, 0xd6, 0xa, 0x8f, 0x8b, 0xc8, 0xb0,
    0xf3, 0xf8, 0xbd, 0x3f, 0x5e, 0xf, 0x8b, 0xd0,
    0xee, 0x90, 0xf8, 0xbd, 0x9, 0xf4, 0x1f, 0x8b,
    0xd0, 0x13, 0x1, 0xf8, 0xbd, 0x0, 0x0, 0x1f,
    0x8b, 0xd0, 0x0, 0x1, 0xf8, 0xbd, 0x0, 0x0,
    0x1f, 0x8b, 0xd0, 0x0, 0x1, 0xf8, 0xbd, 0x0,
    0x0, 0x1f, 0x80,

    /* U+004E "N" */
    0x6f, 0xe0, 0x0, 0x6f, 0x36, 0xff, 0x50, 0x6,
    0xf3, 0x6f, 0xca, 0x0, 0x6f, 0x36, 0xf8, 0xf1,
    0x6, 0xf3, 0x6f, 0x3f, 0x60, 0x6f, 0x36, 0xf2,
    0xac, 0x6, 0xf3, 0x6f, 0x35, 0xf2, 0x6f, 0x36,
    0xf3, 0xe, 0x76, 0xf3, 0x6f, 0x30, 0x9d, 0x5f,
    0x36, 0xf3, 0x3, 0xf8, 0xf3, 0x6f, 0x30, 0xe,
    0xdf, 0x36, 0xf3, 0x0, 0x8f, 0xf3, 0x6f, 0x30,
    0x2, 0xff, 0x30,

    /* U+004F "O" */
    0x0, 0x8d, 0xfd, 0x60, 0x0, 0xcf, 0xa7, 0xbf,
    0x90, 0x3f, 0x80, 0x0, 0xbf, 0x6, 0xf3, 0x0,
    0x7, 0xf3, 0x6f, 0x30, 0x0, 0x6f, 0x36, 0xf3,
    0x0, 0x6, 0xf3, 0x6f, 0x30, 0x0, 0x6f, 0x36,
    0xf3, 0x0, 0x6, 0xf3, 0x6f, 0x30, 0x0, 0x6f,
    0x36, 0xf3, 0x0, 0x7, 0xf3, 0x3f, 0x70, 0x0,
    0xbf, 0x0, 0xcf, 0xa7, 0xbf, 0x90, 0x0, 0x8d,
    0xfd, 0x70, 0x0,

    /* U+0050 "P" */
    0x5f, 0xff, 0xfe, 0xb3, 0x5, 0xf9, 0x77, 0x8e,
    0xf3, 0x5f, 0x40, 0x0, 0x2f, 0xb5, 0xf4, 0x0,
    0x0, 0xde, 0x5f, 0x40, 0x0, 0xe, 0xc5, 0xf5,
    0x22, 0x3b, 0xf6, 0x5f, 0xff, 0xff, 0xf7, 0x5,
    0xf8, 0x54, 0x30, 0x0, 0x5f, 0x40, 0x0, 0x0,
    0x5, 0xf4, 0x0, 0x0, 0x0, 0x5f, 0x40, 0x0,
    0x0, 0x5, 0xf4, 0x0, 0x0, 0x0, 0x5f, 0x40,
    0x0, 0x0, 0x0,

    /* U+0054 "T" */
    0xf, 0xff, 0xff, 0xff, 0xfd, 0x7, 0x77, 0xaf,
    0x97, 0x75, 0x0, 0x0, 0x6f, 0x30, 0x0, 0x0,
    0x0, 0x6f, 0x30, 0x0, 0x0, 0x0, 0x6f, 0x30,
    0x0, 0x0, 0x0, 0x6f, 0x30, 0x0, 0x0, 0x0,
    0x6f, 0x30, 0x0, 0x0, 0x0, 0x6f, 0x30, 0x0,
    0x0, 0x0, 0x6f, 0x30, 0x0, 0x0, 0x0, 0x6f,
    0x30, 0x0, 0x0, 0x0, 0x6f, 0x30, 0x0, 0x0,
    0x0, 0x6f, 0x30, 0x0, 0x0, 0x0, 0x6f, 0x30,
    0x0,

    /* U+0055 "U" */
    0x6f, 0x30, 0x0, 0x7f, 0x36, 0xf3, 0x0, 0x7,
    0xf3, 0x6f, 0x30, 0x0, 0x7f, 0x36, 0xf3, 0x0,
    0x7, 0xf3, 0x6f, 0x30, 0x0, 0x7f, 0x36, 0xf3,
    0x0, 0x7, 0xf3, 0x6f, 0x30, 0x0, 0x7f, 0x36,
    0xf3, 0x0, 0x7, 0xf3, 0x6f, 0x30, 0x0, 0x7f,
    0x35, 0xf4, 0x0, 0x7, 0xf2, 0x2f, 0x80, 0x0,
    0xbf, 0x0, 0xbf, 0x97, 0xbf, 0x80, 0x0, 0x9d,
    0xfd, 0x70, 0x0,

    /* U+0056 "V" */
    0xf, 0xb0, 0x0, 0x0, 0xec, 0xb, 0xe0, 0x0,
    0x2, 0xf8, 0x7, 0xf3, 0x0, 0x6, 0xf3, 0x3,
    0xf7, 0x0, 0xa, 0xf0, 0x0, 0xeb, 0x0, 0xe,
    0xb0, 0x0, 0xaf, 0x0, 0x2f, 0x70, 0x0, 0x6f,
    0x30, 0x5f, 0x30, 0x0, 0x2f, 0x70, 0x9e, 0x0,
    0x0, 0xe, 0xb0, 0xda, 0x0, 0x0, 0xa, 0xf1,
    0xf6, 0x0, 0x0, 0x5, 0xf8, 0xf2, 0x0, 0x0,
    0x1, 0xfe, 0xe0, 0x0, 0x0, 0x0, 0xdf, 0xa0,
    0x0,

    /* U+0057 "W" */
    0x9e, 0x0, 0x7f, 0x50, 0xf, 0x57, 0xf0, 0xa,
    0xe7, 0x2, 0xf4, 0x5f, 0x10, 0xcc, 0x90, 0x4f,
    0x23, 0xf3, 0xe, 0x8b, 0x5, 0xf0, 0x1f, 0x50,
    0xf4, 0xd0, 0x7e, 0x0, 0xf7, 0x2e, 0x1f, 0x9,
    0xc0, 0xd, 0x84, 0xc0, 0xf1, 0xba, 0x0, 0xba,
    0x6a, 0xd, 0x3d, 0x80, 0x9, 0xc9, 0x80, 0xc5,
    0xe6, 0x0, 0x8d, 0xb6, 0xa, 0x8f, 0x40, 0x6,
    0xfd, 0x40, 0x8b, 0xf2, 0x0, 0x4f, 0xf2, 0x6,
    0xef, 0x0, 0x2, 0xff, 0x0, 0x4f, 0xe0, 0x0,

    /* U+0061 "a" */
    0x1, 0x9e, 0xfd, 0x80, 0x0, 0xde, 0x86, 0x9f,
    0x90, 0x2a, 0x40, 0x0, 0xaf, 0x0, 0x0, 0x0,
    0x7, 0xf2, 0x7, 0xef, 0xff, 0xff, 0x26, 0xfa,
    0x43, 0x39, 0xf2, 0xbe, 0x0, 0x0, 0x7f, 0x2b,
    0xf0, 0x0, 0xc, 0xf2, 0x5f, 0xc6, 0x6b, 0xcf,
    0x20, 0x6d, 0xfe, 0x77, 0xf2,

    /* U+0064 "d" */
    0x0, 0x0, 0x0, 0x7f, 0x20, 0x0, 0x0, 0x7,
    0xf2, 0x0, 0x0, 0x0, 0x7f, 0x20, 0x2b, 0xee,
    0x77, 0xf2, 0xd, 0xf8, 0x6b, 0xcf, 0x24, 0xf6,
    0x0, 0xc, 0xf2, 0x6f, 0x30, 0x0, 0x8f, 0x27,
    0xf3, 0x0, 0x7, 0xf2, 0x7f, 0x30, 0x0, 0x7f,
    0x26, 0xf3, 0x0, 0x8, 0xf2, 0x4f, 0x60, 0x0,
    0xcf, 0x20, 0xdf, 0x86, 0xbc, 0xf2, 0x2, 0xbf,
    0xe8, 0x7f, 0x20,

    /* U+0065 "e" */
    0x0, 0x9e, 0xfd, 0x70, 0x0, 0xce, 0x75, 0x9f,
    0xa0, 0x4f, 0x50, 0x0, 0x8f, 0x17, 0xf2, 0x0,
    0x5, 0xf4, 0x7f, 0xff, 0xff, 0xff, 0x47, 0xf4,
    0x33, 0x33, 0x30, 0x7f, 0x20, 0x0, 0x0, 0x4,
    0xf7, 0x0, 0x6, 0xb1, 0xc, 0xf9, 0x69, 0xfa,
    0x0, 0x19, 0xef, 0xd8, 0x0,

    /* U+0068 "h" */
    0x5f, 0x40, 0x0, 0x0, 0x5, 0xf4, 0x0, 0x0,
    0x0, 0x5f, 0x40, 0x0, 0x0, 0x5, 0xf5, 0xaf,
    0xe9, 0x0, 0x5f, 0xc9, 0x6a, 0xfa, 0x5, 0xf9,
    0x0, 0xb, 0xf0, 0x5f, 0x50, 0x0, 0x7f, 0x25,
    0xf4, 0x0, 0x7, 0xf3, 0x5f, 0x40, 0x0, 0x7f,
    0x35, 0xf4, 0x0, 0x7, 0xf3, 0x5f, 0x40, 0x0,
    0x7f, 0x35, 0xf4, 0x0, 0x7, 0xf3, 0x5f, 0x40,
    0x0, 0x7f, 0x30,

    /* U+0069 "i" */
    0x0, 0x5, 0xfa, 0x0, 0x0, 0x0, 0x8f, 0xd0,
    0x0, 0x0, 0x0, 0x31, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xff, 0xfa, 0x0, 0x0, 0x77,
    0x7f, 0xa0, 0x0, 0x0, 0x0, 0xfa, 0x0, 0x0,
    0x0, 0xf, 0xa0, 0x0, 0x0, 0x0, 0xfa, 0x0,
    0x0, 0x0, 0xf, 0xa0, 0x0, 0x0, 0x0, 0xfa,
    0x0, 0x0, 0x0, 0xf, 0xa0, 0x0, 0x37, 0x77,
    0xfd, 0x77, 0x77, 0xff, 0xff, 0xff, 0xff,

    /* U+006D "m" */
    0xe9, 0xdf, 0x59, 0xfb, 0x1e, 0xc2, 0x9f, 0x63,
    0xf8, 0xe9, 0x4, 0xf1, 0xc, 0xbe, 0x90, 0x4f,
    0x10, 0xcb, 0xe9, 0x4, 0xf1, 0xc, 0xbe, 0x90,
    0x4f, 0x10, 0xcb, 0xe9, 0x4, 0xf1, 0xc, 0xbe,
    0x90, 0x4f, 0x10, 0xcb, 0xe9, 0x4, 0xf1, 0xc,
    0xbe, 0x90, 0x4f, 0x10, 0xcb,

    /* U+006E "n" */
    0x5f, 0x5a, 0xfe, 0x90, 0x5, 0xfd, 0x73, 0x7f,
    0xa0, 0x5f, 0x80, 0x0, 0xaf, 0x5, 0xf4, 0x0,
    0x7, 0xf2, 0x5f, 0x40, 0x0, 0x7f, 0x35, 0xf4,
    0x0, 0x7, 0xf3, 0x5f, 0x40, 0x0, 0x7f, 0x35,
    0xf4, 0x0, 0x7, 0xf3, 0x5f, 0x40, 0x0, 0x7f,
    0x35, 0xf4, 0x0, 0x7, 0xf3,

    /* U+006F "o" */
    0x1, 0x9e, 0xfd, 0x70, 0x0, 0xcf, 0x97, 0xbf,
    0x90, 0x4f, 0x70, 0x0, 0xaf, 0x17, 0xf2, 0x0,
    0x5, 0xf4, 0x7f, 0x20, 0x0, 0x5f, 0x47, 0xf2,
    0x0, 0x5, 0xf4, 0x7f, 0x20, 0x0, 0x5f, 0x44,
    0xf7, 0x0, 0xa, 0xf1, 0xc, 0xf9, 0x7a, 0xf9,
    0x0, 0x19, 0xef, 0xd7, 0x0,

    /* U+0070 "p" */
    0x5f, 0x5a, 0xfe, 0x90, 0x5, 0xfd, 0x74, 0x7f,
    0xa0, 0x5f, 0x80, 0x0, 0x9f, 0x15, 0xf4, 0x0,
    0x6, 0xf3, 0x5f, 0x40, 0x0, 0x6f, 0x35, 0xf4,
    0x0, 0x6, 0xf3, 0x5f, 0x50, 0x0, 0x6f, 0x35,
    0xf9, 0x0, 0xa, 0xf1, 0x5f, 0xca, 0x6a, 0xfa,
    0x5, 0xf4, 0xaf, 0xe9, 0x0, 0x5f, 0x40, 0x0,
    0x0, 0x5, 0xf4, 0x0, 0x0, 0x0, 0x5f, 0x40,
    0x0, 0x0, 0x0,

    /* U+0074 "t" */
    0x0, 0x2, 0x82, 0x0, 0x0, 0x0, 0x5, 0xf5,
    0x0, 0x0, 0x0, 0x5, 0xf5, 0x0, 0x0, 0x2f,
    0xff, 0xff, 0xff, 0xf5, 0x17, 0x7a, 0xfa, 0x77,
    0x72, 0x0, 0x5, 0xf5, 0x0, 0x0, 0x0, 0x5,
    0xf5, 0x0, 0x0, 0x0, 0x5, 0xf5, 0x0, 0x0,
    0x0, 0x5, 0xf5, 0x0, 0x0, 0x0, 0x5, 0xf5,
    0x0, 0x0, 0x0, 0x4, 0xf5, 0x0, 0x0, 0x0,
    0x1, 0xfd, 0x77, 0x71, 0x0, 0x0, 0x4d, 0xff,
    0xf4,

    /* U+0075 "u" */
    0x6f, 0x30, 0x0, 0x7f, 0x36, 0xf3, 0x0, 0x7,
    0xf3, 0x6f, 0x30, 0x0, 0x7f, 0x36, 0xf3, 0x0,
    0x7, 0xf3, 0x6f, 0x30, 0x0, 0x7f, 0x36, 0xf3,
    0x0, 0x7, 0xf3, 0x5f, 0x40, 0x0, 0x7f, 0x23,
    0xf8, 0x0, 0xc, 0xf0, 0xb, 0xf9, 0x7b, 0xf8,
    0x0, 0x8, 0xdf, 0xd6, 0x0,

    /* U+0076 "v" */
    0xd, 0xd0, 0x0, 0x0, 0xfa, 0x8, 0xf3, 0x0,
    0x5, 0xf5, 0x3, 0xf8, 0x0, 0xa, 0xf0, 0x0,
    0xdd, 0x0, 0xf, 0xa0, 0x0, 0x8f, 0x20, 0x5f,
    0x50, 0x0, 0x2f, 0x70, 0xaf, 0x0, 0x0, 0xd,
    0xc0, 0xfa, 0x0, 0x0, 0x8, 0xf5, 0xf4, 0x0,
    0x0, 0x2, 0xfd, 0xf0, 0x0, 0x0, 0x0, 0xdf,
    0xa0, 0x0,

    /* U+0077 "w" */
    0x5f, 0x0, 0x7f, 0x40, 0x2f, 0x23, 0xf2, 0xa,
    0xe7, 0x5, 0xf0, 0xf, 0x50, 0xda, 0xa0, 0x7c,
    0x0, 0xe7, 0xf, 0x5d, 0x9, 0xa0, 0xb, 0x93,
    0xe2, 0xf0, 0xc7, 0x0, 0x8b, 0x6b, 0xf, 0x2e,
    0x40, 0x6, 0xe8, 0x80, 0xc6, 0xf2, 0x0, 0x3f,
    0xb6, 0xa, 0xbf, 0x0, 0x1, 0xff, 0x30, 0x7f,
    0xc0, 0x0, 0xe, 0xf0, 0x5, 0xfa, 0x0,

    /* U+00B0 "°" */
    0x4, 0xdf, 0xc2, 0x1, 0xf5, 0x8, 0xd0, 0x4e,
    0x0, 0x1f, 0x1, 0xf5, 0x8, 0xd0, 0x4, 0xdf,
    0xc2, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 173, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 173, .box_w = 4, .box_h = 6, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 84, .adv_w = 173, .box_w = 4, .box_h = 3, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 378, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 437, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 496, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 555, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 614, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 173, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 738, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 797, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 856, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 915, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 967, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1026, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1085, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1144, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1203, .adv_w = 173, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1268, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1327, .adv_w = 173, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1392, .adv_w = 173, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1464, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1509, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1568, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1613, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1672, .adv_w = 173, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1735, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1780, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1825, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1870, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1929, .adv_w = 173, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1994, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2039, .adv_w = 173, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2089, .adv_w = 173, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2144, .adv_w = 173, .box_w = 7, .box_h = 5, .ofs_x = 2, .ofs_y = 8}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x7, 0x9, 0xb, 0xc, 0xd, 0xe, 0xf,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x1c, 0x1f, 0x20,
    0x23, 0x24, 0x28, 0x29, 0x2a, 0x2b, 0x2f, 0x30,
    0x31, 0x32, 0x3c, 0x3f, 0x40, 0x43, 0x44, 0x48,
    0x49, 0x4a, 0x4b, 0x4f, 0x50, 0x51, 0x52, 0x8b
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 37, .range_length = 140, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 40, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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

extern const lv_font_t lv_font_montserrat_18;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t jetbrains_18 = {
#else
lv_font_t jetbrains_18 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_18,
#endif
    .user_data = NULL,
};



#endif /*#if JETBRAINS_18*/

