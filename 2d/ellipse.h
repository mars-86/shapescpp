#ifndef _SHAPES_2D_ELLIPSE_INCLUDED_H_
#define _SHAPES_2D_ELLIPSE_INCLUDED_H_
#pragma once

#include "../base/shape2d.h"

namespace shapes {

template <typename T>
class EllipseT : public Shape2DT<T> {
public:
	EllipseT(T x, T y, T rx, T ry)
		: _x(x), _y(y), _rx(rx), _ry(ry)
	{
		build(x, y, rx, ry);
	}

	EllipseT(T x, T y, T rx, T ry, const Color& color)
		: _x(x), _y(y), _rx(rx), _ry(ry)
	{
		this->set_color(color.get_rgba());
		build(x, y, rx, ry);
	}

	~EllipseT()
	{
		this->_points.clear();
	}

	void build(T xc, T yc, T rx, T ry)
	{
		T x = 0;
		T y = ry;
		T ry2 = ry * ry;
		T rx2 = rx * rx;
		T p1 = ry2 + 1/4 * rx2 - (rx2 * ry);
		T try2 = (ry2 << 1);
		T trx2 = (rx2 << 1);

		this->_points.insert(this->_points.end(), {
			{ (xc + x), (yc + y) }, { (xc + x), (yc - y) }
		});
		while ((try2 * x) <= (trx2 * y)) {
			++x;
			if (p1 < 0)
				p1 += ((ry2 * x) << 1) + ry2;
			else {
				--y;
				p1 += ((ry2 * x) << 1) - ((rx2 * y) << 1) + ry2;
			}
			this->_points.insert(this->_points.end(), {
				{ (xc + x), (yc + y) }, { (xc + x), (yc - y) },
				{ (xc - x), (yc + y) }, { (xc - x), (yc - y) }
			});
		}
		int p2 = ry2 * ((x + (T).5) * (x + (T).5)) + rx2 * ((y - 1) * (y - 1)) - ry2 * rx2;
		while (y > 0) {
			y -= 1;
			if (p2 > 0) {
				p2 -= ((rx2 * y) << 1) + rx2;
			}
			else {
				x += 1;
				p2 += ((ry2 * x) << 1) - ((rx2 * y) << 1) + rx2;
			}
			this->_points.insert(this->_points.end(), {
				{ (xc + x), (yc + y) }, { (xc + x), (yc - y) },
				{ (xc - x), (yc + y) }, { (xc - x), (yc - y) }
			});
		}
#ifdef __DEBUG
        for (auto i : this->_points) std::cout << i;
#endif // __DEBUG
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
        // this->draw();
	}

    void rotate(int angle)
	{

	}

    EllipseT<T> &operator=(EllipseT<T> &ellipse)
    {
        _x = ellipse._x;
        _y = ellipse._y;
        _rx = ellipse._rx;
        _ry = ellipse._ry;

        return *this;
    }

private:
	T _x, _y, _rx, _ry;

};

typedef EllipseT<int> Ellipse;
typedef EllipseT<double> EllipseF;

} // namespace shapes

#endif // !_SHAPES_2D_ELLIPSE_INCLUDED_H_
