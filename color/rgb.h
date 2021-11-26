#ifndef _SHAPES_COLOR_RGB_INCLUDED_H_
#define _SHAPES_COLOR_RGB_INCLUDED_H_
#pragma once

namespace shapes {

typedef struct _RGBA {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
} RGBA;

const unsigned int rgba_mask = 0xFFFFFFFF;

const unsigned char rgba_r_shift = 24;
const unsigned char rgba_g_shift = 16;
const unsigned char rgba_b_shift = 8;
const unsigned char rgba_a_shift = 0;

} // namespace shapes

#endif // !_SHAPES_COLOR_RGB_INCLUDED_H_
