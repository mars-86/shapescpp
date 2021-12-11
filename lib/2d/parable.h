#ifndef _SHAPES_LIB_2D_PARABLE_INCLUDED_H_
#define _SHAPES_LIB_2D_PARABLE_INCLUDED_H_
#pragma once

#include <cmath>
#include <iostream>
#include "../base/shape2d.h"
#include "../coords/point2d.h"

namespace shapes {

template <typename T>
class ParableT : public Shape2DT<T> {
public:
	ParableT(T x, T y, T rx, T ry)
		: _x(x), _y(y), _rx(rx), _ry(ry)
	{
		this->_build();
	}

	ParableT(T x, T y, T rx, T ry, const Color& color)
		:  _x(x), _y(y), _rx(rx), _ry(ry)
	{
		this->set_color(color.get_rgba());
		this->_build();
	}

	~ParableT()
	{
		this->_points.clear();
	}

	void set_size(T width, T height){}

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

    ParableT<T> &operator=(ParableT<T> &parable)
    {
        _x = parable._x;
        _y = parable._y;
        _rx = parable._rx;
        _ry = parable._ry;

        return *this;
    }

private:
	T _x, _y, _rx, _ry;

	void _build(void)
	{
        // FIX: bad calculation
		// Middle point algorithm based
		T x = _x, y = _y; // , rx = _rx, ry = _ry;
		T x0 = 0, y0 = 0, p0 = 1;
		this->_points.insert(this->_points.end(), {{(x + x0), (y + y0)}, {(x - x0), (y + y0)}});
		while (x0 < x) {
			++x0;
			if (p0 < 0)
				++p0;
			else {
				++y0;
				p0 -= (y0 << 1) + 1;
			}
			this->_points.insert(this->_points.end(), {
				{(x + x0), (y + y0)}, {(x - x0), (y + y0)}
			});
		}
#ifdef __DEBUG
    for (auto i : this->_points) std::cout << i;
#endif // __DEBUG
	}

};

typedef ParableT<int> Parable;
typedef ParableT<double> ParableF;

} // namespace shapes

#endif // !_SHAPES_LIB_2D_PARABLE_INCLUDED_H_
