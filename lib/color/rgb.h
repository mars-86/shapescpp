#ifndef _SHAPES_COLOR_RGB_INCLUDED_H_
#define _SHAPES_COLOR_RGB_INCLUDED_H_
#pragma once

namespace shapes {

typedef struct _RGB {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RGB;

typedef struct _RGBA {
	RGB rgb;
	unsigned char a;
} RGBA;

const unsigned int rgb_mask = 0x00FFFFFF;

const unsigned int rgb_r_mask = 0x00FF0000;
const unsigned int rgb_g_mask = 0x0000FF00;
const unsigned int rgb_b_mask = 0x000000FF;

const unsigned char rgb_r_shift = 16;
const unsigned char rgb_g_shift = 8;

const unsigned int rgba_r_mask = 0xFF000000;
const unsigned int rgba_g_mask = 0x00FF0000;
const unsigned int rgba_b_mask = 0x0000FF00;
const unsigned int rgba_a_mask = 0x000000FF;

const unsigned char rgba_r_shift = 24;
const unsigned char rgba_g_shift = 16;
const unsigned char rgba_b_shift = 8;

} // namespace shapes

#endif // !_SHAPES_COLOR_RGB_INCLUDED_H_
