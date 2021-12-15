#ifndef _SHAPES_LIB_2D_SQUARE_INCLUDED_H_
#define _SHAPES_LIB_2D_SQUARE_INCLUDED_H_
#pragma once

#include "rect.h"

namespace shapes {

template <typename T>
class SquareT : public RectT<T> {
public:
	SquareT(T x, T y, T size)
		: RectT<T>(x, y, size, size) {}

	~SquareT() {}
};

typedef SquareT<int> Square;
typedef SquareT<double> SquareF;

} // namespace shapes

#endif // !_SHAPES_LIB_2D_SQUARE_INCLUDED_H_
