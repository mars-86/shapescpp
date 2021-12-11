#ifndef _SHAPES_LIB_2D_RECT_INCLUDED_H_
#define _SHAPES_LIB_2D_RECT_INCLUDED_H_
#pragma once

#include <vector>
#include "../base/shape2d.h"
#include "line.h"

namespace shapes {

template <typename T>
class RectT : public Shape2DT<T> {
public:
	RectT(T x, T y, T width, T height)
		: _x(x), _y(y), _w(width), _h(height)
	{
		this->_build();
	}

	RectT(T x, T y, T width, T height, const Color& color)
		: _x(x), _y(y), _w(width), _h(height)
	{
		this->set_color(color.get_rgba());
		this->_build();
	}

	RectT(T x, T y, T width, T height, const Color& color, const Color& inner_color)
		: _x(x), _y(y), _w(width), _h(height)
	{
		this->set_color(color.get_rgba());
		this->set_inner_color(inner_color.get_rgba());
		this->_build();
	}

	virtual ~RectT()
	{
		this->_points.clear();
	}

	void set_size(T width, T height) {};

	T get_width(void) const
	{
		return _w;
	}

	T get_height(void) const
	{
		return _h;
	}

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

    RectT<T> &operator=(RectT<T> &rect)
    {
        _x = rect._x;
        _y = rect._y;
        _w = rect._w;
        _h = rect._h;

        return *this;
    }

protected:
	T _x, _y, _w, _h;

    void _build(void)
	{
        T x = _x, y = _y, width = _w, height = _h;
		std::vector<Point2DT<T>> e1 = Line(x, y, x + width, y).get_bounds();
		std::vector<Point2DT<T>> e2 = Line(x + width, y + 1, x + width, y + height - 1).get_bounds();
		std::vector<Point2DT<T>> e3 = Line(x + width, y + height, x, y + height).get_bounds();
		std::vector<Point2DT<T>> e4 = Line(x, y + height - 1, x, y + 1).get_bounds();

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

typedef RectT<int> Rect;
typedef RectT<double> RectF;

} // namespace shapes

#endif // !_SHAPES_LIB_2D_RECT_INCLUDED_H_
