#ifndef _SHAPES_BASE_SHAPE_3D_INCLUDED_H_
#define _SHAPES_BASE_SHAPE_3D_INCLUDED_H_
#pragma once

#include <vector>
#include "shape.h"
#include "../coords/point3d.h"

namespace shapes {

template <typename T>
class Shape3DT : public Shape {
public:
	Shape3DT() {}
	virtual ~Shape3DT() {}
	virtual double get_area(void) const = 0;
	virtual void translate(const Point3DT<T>& point) = 0;
	virtual void rotate(int angle, int axis) = 0;
    virtual void fill(const Color& color) = 0;

	const std::vector<Point3DT<T>>& get_bounds(void) const { return _points; }
	const Point3DT<T>& get_origin(void) const { return _points[0]; }

protected:
	std::vector<Point3DT<T>> _points;
	friend std::ostream& operator<<(std::ostream& out, const Point3DT<T>& point)
	{
		return out << "{" << point.get_x() << ", " << point.get_y() << ", " << point.get_z() << "}" << std::endl;
	}
};

typedef Shape3DT<int> Shape3D;
typedef Shape3DT<double> Shape3DF;

} // namespace shapes

#endif // !_SHAPES_BASE_SHAPE_3D_INCLUDED_H_
