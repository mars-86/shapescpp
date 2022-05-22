#ifndef _SHAPES_LIB_3D_LINE_INCLUDED_H_
#define _SHAPES_LIB_3D_LINE_INCLUDED_H_
#pragma once

#include <cmath>
#include "../base/shape3d.h"

namespace shapes {

namespace _3D {

template <typename T>
class LineT : public Shape3DT<T> {
public:
	LineT(T x1, T y1, T z1, T x2, T y2, T z2)
		: _x1(x1), _y1(y1), _z1(z1), _x2(x2), _y2(y2), _z2(z2)
	{
        this->_set_center({(x1 + x2) >> 1, (y1 + y2) >> 1, (z1 + z2) >> 1});
        _build();
	}

	~LineT()
	{
		this->_points.clear();
	}

    LineT<T> &operator=(LineT<T> &line)
    {
        _x1 = line._x1;
        _y1 = line._y1;
        _z1 = line._z1;
        _x2 = line._x2;
        _y2 = line._y2;
        _z2 = line._z2;

        return *this;
    }

private:
	T _x1, _y1, _z1, _x2, _y2, _z2;

	void _build(void)
	{
        T x1 = _x1, y1 = _y1, z1 = _z1, x2 = _x2, y2 = _y2, z2 = _z2;
		T dx = std::abs(x2 - x1),
            sx = x1 < x2 ? 1 : -1,
			dy = std::abs(y2 - y1),
			sy = y1 < y2 ? 1 : -1,
			dz = std::abs(z2 - z1),
			sz = z1 < z2 ? 1 : -1,
			md = (dx >= dy && dx >= dz) ? dx : (dy >= dz) ? dy : dz, // maximum difference
			i = md;
			x2 = y2 = z2 = md / 2;  /* error value e_xyz */
		while (true){   /* loop */
#ifdef __DEBUG
            std::cout << "x1:" << x1 << " y1:"  << y1 << " z1:" << z1 << " i:" << i << std::endl;
            std::getchar();
#endif // __DEBUG
			this->_points.push_back({ x1, y1, z1 });
			if(i-- == 0) break;
			x2 -= dx;
			if (x2 < 0){
				x2 += md;
				x1 += sx;
			}
			y2 -= dy;
			if (y2 < 0){
				y2 += md;
				y1 += sy;
			}
			z2 -= dz;
			if (z2 < 0){
				z2 += md;
				z1 += sz;
			}
		}
#ifdef __DEBUG
    for (auto i : this->_points) std::cout << i;
#endif // __DEBUG
	}
};

typedef LineT<int> Line;
typedef LineT<double> LineF;

} // namespace _3D

} // namespace shapes

#endif // !_SHAPES_LIB_2D_LINE_INCLUDED_H_
