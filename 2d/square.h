#ifndef _SHAPES_2D_SQUARE_INCLUDED_H_
#define _SHAPES_2D_SQUARE_INCLUDED_H_
#pragma once

#include <vector>
#include "rect.h"

namespace shapes {

template <typename T>
class SquareT : public RectT<T> {
public:
	SquareT()
		: RectT<T>() {}

	SquareT(T x, T y, T size)
		: RectT<T>(x, y, size, size)
	{
		this->build(x, y, size, size);
	}

	SquareT(T x, T y, T size, const Color& color)
		: RectT<T>(x, y, size, size)
	{
		this->set_color(color.get_rgba());
		this->build(x, y, size, size);
	}

	~SquareT() {}
};

typedef SquareT<int> Square;
typedef SquareT<double> SquareF;

} // namespace shapes

#endif // !_SHAPES_2D_SQUARE_INCLUDED_H_
