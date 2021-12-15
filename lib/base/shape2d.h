#ifndef _SHAPES_BASE_SHAPE_2D_INCLUDED_H_
#define _SHAPES_BASE_SHAPE_2D_INCLUDED_H_
#pragma once

#include <iostream>
#include <vector>
#include "shape.h"
#include "../coords/point2d.h"

namespace shapes {

template <typename T>
class Shape2DT : public Shape {
public:
	Shape2DT() {}
	virtual ~Shape2DT() {}

	const std::vector<Point2DT<T>>& get_bounds(void) const { return _points; }
	const Point2DT<T>& get_center(void) const { return _center; }
    unsigned int length(void) const { return _points.size(); }

protected:
	std::vector<Point2DT<T>> _points;
    Point2DT<T> _center;

    void _set_center(const Point2DT<T> center) { _center = center; }
	virtual void _build(void) = 0;

};

typedef Shape2DT<int> Shape2D;
typedef Shape2DT<double> Shape2DF;

} // namespace shapes

#endif // !_SHAPES_BASE_SHAPE_2D_INCLUDED_H_
