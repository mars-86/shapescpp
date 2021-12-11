#ifndef _SHAPES_BASE_SHAPE_INCLUDED_H_
#define _SHAPES_BASE_SHAPE_INCLUDED_H_
#pragma once

#include <iostream>
#include "../color/color.h"

namespace shapes {

class Shape {
public:
	Shape() : _color({0, 0, 0, 0}), _inner_color({0, 0, 0, 0}) {}
	virtual ~Shape(){}
	virtual void set_size(int width, int height) = 0;
	virtual double get_size(void) const = 0;
	virtual void set_color(const RGBA& color) { _color.set_rgba(color); }
	virtual const Color& get_color(void) const { return _color; }
	virtual void set_inner_color(const RGBA& inner_color) { _inner_color.set_rgba(inner_color); }
	virtual const Color& get_inner_color(void) const { return _inner_color; }
protected:
	Color _color, _inner_color;
};

} // namespace shapes

#endif // !_SHAPES_BASE_SHAPE_INCLUDED_H_
