#ifndef _SHAPES_LIB_2D_CIRCLE_INCLUDED_H_
#define _SHAPES_LIB_2D_CIRCLE_INCLUDED_H_
#pragma once

#include <cmath>
#include "../base/shape2d.h"

namespace shapes {

template <typename T>
class CircleT : public Shape2DT<T> {
public:
	CircleT(T x, T y, T radius)
		: _x(x), _y(y), _radius(radius)
	{
		this->_build();
	}

	CircleT(T x, T y, T radius, const Color& color)
		: _x(x), _y(y), _radius(radius)
	{
		this->set_color(color.get_rgba());
		this->_build();
	}

	CircleT(T x, T y, T radius, const Color& color, const Color& inner_color)
		: _x(x), _y(y), _radius(radius)
	{
		this->set_color(color.get_rgba());
		this->set_inner_color(inner_color.get_rgba());
		this->_build();
	}

	~CircleT()
	{
		this->_points.clear();
	}

	void set_size(T width, T height) {}

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
        this->_points.clear();
        this->_x = point.get_x(), this->_y = point.get_y();
        this->_build();
	}

    void rotate(int angle)
	{

	}

    CircleT<T> &operator=(CircleT<T> &circle)
    {
        _x = circle._x;
        _y = circle._y;
        _radius = circle._radius;

        return *this;
    }

private:
	T _x, _y, _radius;

    void _build(void)
	{
		T x = _x, y = _y, radius = _radius,
            x0 = 0,
            y0 = radius,
            p0 = 1 - radius; // 5 / 4 - r
        this->_points.insert(this->_points.end(), {
            {x + x0, y + y0}, {x - x0, y - y0/* - 1*/}
        });
        // y0 - 1 prevents that last 8 points pair gets duplicate
		while (x0 < y0 - 1) {
			x0 += 1;
			if (p0 < 0)
				p0 += (x0 << 1) + 1;
			else {
				y0 -= 1;
				p0 += (x0 << 1) + 1 - (y0 << 1);
			}
			// insert points for all octants
			this->_points.insert(this->_points.end(), {
				{x + x0, y + y0}, {x + x0, y - y0/* - 1*/},
				{x - x0, y + y0}, {x - x0, y - y0/* - 1*/},
                {x - y0, y + x0}, {x - y0, y - x0/* - 1*/},
				{x + y0, y + x0}, {x + y0, y - x0/* - 1*/}
			});
		}
#ifdef __DEBUG
        for (auto i : this->_points) std::cout << i;
#endif // __DEBUG
	}

};

typedef CircleT<int> Circle;
typedef CircleT<double> CircleF;

} // namespace shapes

#endif // !_SHAPES_LIB_2D_CIRCLE_INCLUDED_H_
