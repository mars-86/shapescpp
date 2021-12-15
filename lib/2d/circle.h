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
        this->_set_center({x, y});
		_build();
	}

	~CircleT()
	{
		this->_points.clear();
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
