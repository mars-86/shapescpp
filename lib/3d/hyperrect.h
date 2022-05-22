#ifndef _SHAPES_LIB_3D_HYPERRECT_INCLUDED_H_
#define _SHAPES_LIB_3D_HYPERRECT_INCLUDED_H_
#pragma once

#include <vector>
#include "../base/shape3d.h"
#include "./line.h"

namespace shapes {

namespace _3D {

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
		return _d;
	}

    HyperrectT<T> &operator=(HyperrectT<T> &hyperrect)
    {
        _x = hyperrect._x;
        _y = hyperrect._y;
        _z = hyperrect._z;
        _w = hyperrect._w;
        _h = hyperrect._h;
        _d = hyperrect._d;

        return *this;
    }

protected:
	T _x, _y, _z, _w, _h, _d;

    void _build(void)
	{
        T x = _x, y = _y, z = _z, width = _w, height = _h, deep = _d;
        std::vector<std::vector<Point3DT<T>>> points;

        points.push_back(Line(x, y, z, x + width, y, z).get_bounds());
		points.push_back(Line(x + width, y + 1, z, x + width, y + height - 1, z).get_bounds());
		points.push_back(Line(x + width, y + height, z, x, y + height, z).get_bounds());
		points.push_back(Line(x, y + height - 1, z, x, y + 1, z).get_bounds());

		points.push_back(Line(x, y, z, x, y, z + deep - 1).get_bounds());
		points.push_back(Line(x + width, y, z + deep - 1, x + width, y, z + deep - 1).get_bounds());
        points.push_back(Line(x + width, y + height, z + deep - 1, x + width, y + height, z).get_bounds());
        points.push_back(Line(x, y + height, z + deep - 1, x, y + height, z + deep - 1).get_bounds());

		points.push_back(Line(x, y, z + deep, x + width, y, z + deep).get_bounds());
		points.push_back(Line(x + width, y + 1, z + deep, x + width, y + height - 1, z + deep).get_bounds());
		points.push_back(Line(x + width, y + height, z + deep, x, y + height, z + deep).get_bounds());
		points.push_back(Line(x, y + height - 1, z + deep, x, y + 1, z + deep).get_bounds());

#ifdef __DEBUG
		for (auto i : points) {
            for (auto j : i)
                std::cout << j;
        	std::cout << '\n';
		}
#endif // __DEBUG

        for (auto i : points)
            this->_points.insert(this->_points.end(), i.begin(), i.end());
	}

};

typedef HyperrectT<int> Hyperrect;
typedef HyperrectT<double> HyperrectF;

} // namespace _3D

} // namespace shapes

#endif // !_SHAPES_LIB_3D_HYPERRECT_INCLUDED_H_
