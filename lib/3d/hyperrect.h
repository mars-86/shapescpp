#ifndef _SHAPES_LIB_3D_HYPERRECT_INCLUDED_H_
#define _SHAPES_LIB_3D_HYPERRECT_INCLUDED_H_
#pragma once

#include <vector>
#include "../base/shape3d.h"
#include "../2d/line.h"

namespace shapes {

template <typename T>
class HyperrectT : public Shape3DT<T> {
public:
	HyperrectT(T x, T y, T z, T width, T height, T deep)
		: _x(x - (width >> 1)), _y(y - (height >> 1)), _z(z - (deep >> 1)), _w(width), _h(height), _d(deep)
	{
        this->_set_center({x, y, z});
        _build();
	}

	virtual ~HyperrectT()
	{
		this->_points.clear();
	}

	T get_width(void) const
	{
		return _w;
	}

	T get_height(void) const
	{
		return _h;
	}

	T get_deep(void) const
	{
		return _z;
	}

    RectT<T> &operator=(HyperrectT<T> &hyperrect)
    {
        _x = hyperrect._x;
        _y = hyperrect._y;
        _z = hyperrect._z;
        _w = hyperrect._w;
        _h = hyperrect._h;
        _d = hyperrect._d

        return *this;
    }

protected:
	T _x, _y, _z, _w, _h, _d;

    void _build(void)
	{
        T x = _x, y = _y, z = _z, width = _w, height = _h, deep = _d;
		std::vector<Point3DT<T>> e1 = Line(x, y, x + width, y).get_bounds();
		std::vector<Point3DT<T>> e2 = Line(x + width, y + 1, x + width, y + height - 1).get_bounds();
		std::vector<Point3DT<T>> e3 = Line(x + width, y + height, x, y + height).get_bounds();
		std::vector<Point3DT<T>> e4 = Line(x, y + height - 1, x, y + 1).get_bounds();

#ifdef __DEBUG
		for (auto i : e1) std::cout << i;
		std::cout << '\n';
		for (auto i : e2) std::cout << i;
		std::cout << '\n';
		for (auto i : e3) std::cout << i;
		std::cout << '\n';
        for (auto i : e4) std::cout << i;
        std::cout << '\n';
#endif // __DEBUG

		this->_points.insert(this->_points.end(), e1.begin(), e1.end());
		this->_points.insert(this->_points.end(), e2.begin(), e2.end());
		this->_points.insert(this->_points.end(), e3.begin(), e3.end());
		this->_points.insert(this->_points.end(), e4.begin(), e4.end());
	}

};

typedef HyperrectT<int> Hyperrect;
typedef HyperrectT<double> HyperrectF;

} // namespace shapes

#endif // !_SHAPES_LIB_3D_HYPERRECT_INCLUDED_H_
