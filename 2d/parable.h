#ifndef _SHAPES_2D_PARABLE_INCLUDED_H_
#define _SHAPES_2D_PARABLE_INCLUDED_H_
#pragma once

#include <cmath>
#include <iostream>
#include "../base/shape2d.h"
#include "../coords/point2d.h"

namespace shapes {

template <typename T>
class ParableT : public Shape2DT<T> {
public:
	ParableT()
		: _x(0), _y(0), _rx(0), _ry(0) {}

	ParableT(T x, T y, T rx, T ry)
		: _x(x), _y(y), _rx(rx), _ry(ry)
	{
		build(x, y, rx, ry);
	}

	ParableT(T x, T y, T rx, T ry, const Color& color)
		:  _x(x), _y(y), _rx(rx), _ry(ry)
	{
		this->set_color(color.get_rgba());
		build(x, y, rx, ry);
	}

	~ParableT()
	{
		this->_points.clear();
	}

	void build(T x, T y, T rx, T ry)
	{
        // FIX: bad calculation
		// Middle point algorithm based
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
        // this->draw();
	}

    void rotate(int angle)
	{

	}

    void fill(const Color& color)
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

};

typedef ParableT<int> Parable;
typedef ParableT<double> ParableF;

} // namespace shapes

#endif // !_SHAPES_2D_PARABLE_INCLUDED_H_
