#ifndef _SHAPES_BASE_SHAPE_3D_INCLUDED_H_
#define _SHAPES_BASE_SHAPE_3D_INCLUDED_H_
#pragma once

#include <iostream>
#include <vector>
#include "shape.h"
#include "../coords/point3d.h"

namespace shapes {

template <typename T>
class Shape3DT : public Shape {
public:
	Shape3DT() {}
	virtual ~Shape3DT() {}

	const std::vector<Point3DT<T>>& get_bounds(void) const { return _points; }
	const Point3DT<T>& get_center(void) const { return _center; }
	unsigned int length(void) const { return _points.size(); }

protected:
	std::vector<Point3DT<T>> _points;

	virtual void _build(void) = 0;
	template <typename U>
	friend std::ostream& operator<<(std::ostream& out, const Point2DT<U>& point);

};

typedef Shape3DT<int> Shape3D;
typedef Shape3DT<double> Shape3DF;

template <typename T>
std::ostream& operator<<(std::ostream& out, const Point3DT<T>& point)
{
    return out << "{" << point.get_x() << ", " << point.get_y() << ", " << point.get_z() << "}" << std::endl;
}

} // namespace shapes

#endif // !_SHAPES_BASE_SHAPE_3D_INCLUDED_H_
