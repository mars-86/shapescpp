#include "color.h"

namespace shapes {

Color::Color()
	: _color({0, 0, 0, 0}) {}

Color::Color(unsigned char r, unsigned char g, unsigned char b)
	: _color({ {r, g, b}, 0 }) {}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	: _color({ {r, g, b}, a }) {}

Color::~Color() {}

void Color::set_rgb(const RGB& rgb)
{
	_color.rgb = rgb;
}

const RGB& Color::get_rgb(void) const
{
	return _color.rgb;
}

void Color::set_rgba(const RGBA& rgba)
{
	_color = rgba;
}

const RGBA& Color::get_rgba(void) const
{
	return _color;
}

void Color::set_red(const unsigned char red)
{
	_color.rgb.r = red;
}

unsigned char Color::get_red(void) const
{
	return _color.rgb.r;
}

void Color::set_green(const unsigned char green)
{
	_color.rgb.g = green;
}

unsigned char Color::get_green(void) const
{
	return _color.rgb.g;
}

void Color::set_blue(const unsigned char blue)
{
	_color.rgb.b = blue;
}

unsigned char Color::get_blue(void) const
{
	return _color.rgb.b;
}

void Color::set_alpha(const unsigned char alpha)
{
	_color.a = alpha;
}

unsigned char Color::get_alpha(void) const
{
	return _color.a;
}

} // namespace shapes
