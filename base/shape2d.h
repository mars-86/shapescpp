#ifndef _SHAPES_BASE_SHAPE_2D_INCLUDED_H_
#define _SHAPES_BASE_SHAPE_2D_INCLUDED_H_
#pragma once

#include <vector>
#include "shape.h"
#include "../coords/point2d.h"

namespace shapes {

template <typename T>
class Shape2DT : public Shape {
public:
	Shape2DT() {}
	virtual ~Shape2DT() {}
	virtual double get_area(void) const = 0;
	virtual void translate(const Point2DT<T>& point) = 0;
    virtual void rotate(int angle) = 0;

	const std::vector<Point2DT<T>>& get_bounds(void) const { return _points; }
	const Point2DT<T>& get_origin(void) const { return _points[0]; }
    int length(void) const { this->_points.size(); }

protected:
	std::vector<Point2DT<T>> _points;

	virtual void _build(void) = 0;
	template <typename U>
	friend std::ostream& operator<<(std::ostream& out, const Point2DT<U>& point);

};

typedef Shape2DT<int> Shape2D;
typedef Shape2DT<double> Shape2DF;

template <typename T>
std::ostream& operator<<(std::ostream& out, const Point2DT<T>& point)
{
    return out << "{" << point.get_x() << "," << point.get_y() << "}";
}

} // namespace shapes

#endif // !_SHAPES_BASE_SHAPE_2D_INCLUDED_H_
