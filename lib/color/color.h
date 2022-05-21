#ifndef _SHAPES_COLOR_COLOR_INCLUDED_H_
#define _SHAPES_COLOR_COLOR_INCLUDED_H_
#pragma once

#include "rgb.h"

namespace shapes {

class Color {
public:
	Color();
	Color(unsigned char red, unsigned char green, unsigned char blue);
	Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
	~Color();

	void set_rgb(const RGB& rgb);
	const RGB& get_rgb(void) const;
	void set_rgba(const RGBA& rgba);
	const RGBA& get_rgba(void) const;
	void set_red(const unsigned char red);
	unsigned char get_red(void) const;
	void set_green(const unsigned char green);
	unsigned char get_green(void) const;
	void set_blue(const unsigned char blue);
	unsigned char get_blue(void) const;
	void set_alpha(const unsigned char alpha);
	unsigned char get_alpha(void) const;

	inline int get_rgb_color(void)
	{
<<<<<<< HEAD:lib/color/color.h
		return ((_color.rgb.r << rgb_r_shift) | (_color.rgb.g << rgb_g_shift) | _color.rgb.b) & rgb_mask;
=======
		return ((_color.r << rgb_r_shift) | (_color.g << rgb_g_shift) | _color.b) & rgb_mask;
>>>>>>> master:color/color.h
	}

	inline int get_rgba_color(void)
	{
<<<<<<< HEAD:lib/color/color.h
		return ((_color.rgb.r << rgba_r_shift) | (_color.rgb.g << rgba_g_shift) | (_color.rgb.b << rgba_b_shift) | _color.a);
=======
		return ((_color.r << rgba_r_shift) | (_color.g << rgba_g_shift) | (_color.b << rgba_b_shift) | _color.a);
>>>>>>> master:color/color.h
	}

private:
	RGBA _color;
};

} // namespace shapes

#endif // !_SHAPES_COLOR_COLOR_INCLUDED_H_
