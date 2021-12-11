#ifndef _SHAPES_LIB_2D_FREEHAND_INCLUDED_H_
#define _SHAPES_LIB_2D_FREEHAND_INCLUDED_H_
#pragma once

#include <vector>
#include "../base/shape2d.h"
#include "line.h"

namespace shapes {

template <typename T>
class FreeHandT : public Shape2DT<T> {
public:
	FreeHandT(const std::vector<Point2DT<T>> &points)
		: _local_points(points)
    {
		_build();
	}

	FreeHandT(const std::vector<Point2DT<T>> &points, const Color& color)
		: _local_points(points)
    {
        this->set_color(color.get_rgba());
		_build();
	}

    FreeHandT(const std::vector<Point2DT<T>> &points, const Color& color, const Color& inner_color)
        : _local_points(points)
    {
        this->set_color(color.get_rgba());
		this->set_inner_color(inner_color.get_rgba());
		_build();
	}

	~FreeHandT() { this->_points.clear(); }

    void set_size(T width, T height) {};

	double get_size(void) const
	{
		return 0;
	}

	double get_area(void) const
	{
		return 0;
	}

	void translate(const Point2DT<T>& point)
	{

	}

    void rotate(int angle)
	{

	}

private:
    std::vector<Point2DT<T>> _local_points;

    void _build(void)
    {
        typename std::vector<Point2DT<T>>::iterator it = _local_points.begin();
        for (++it; it != _local_points.end(); ++it) {
            Line ln((it - 1)->get_x(), (it - 1)->get_y(), (it)->get_x() - 1, (it)->get_y() - 1);
            auto np = ln.get_bounds();
            this->_points.insert(this->_points.end(), np.begin(), np.end());
        }
        this->_points.push_back(_local_points.back());

#ifdef __DEBUG
        for (auto i : this->_points) std::cout << i;
#endif // __DEBUG
    }

};

typedef FreeHandT<int> FreeHand;
typedef FreeHandT<double> FreeHandF;

} // namespace shapes

#endif // !_SHAPES_LIB_2D_FREEHAND_INCLUDED_H_
