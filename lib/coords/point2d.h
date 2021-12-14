#ifndef _SHAPES_COORDS_POINT_2D_INCLUDED_H_
#define _SHAPES_COORDS_POINT_2D_INCLUDED_H_

namespace shapes {

template <typename T>
class Point2DT {
public:
	Point2DT() : _x(0), _y(0) {}
	Point2DT(T x, T y) : _x(x), _y(y) {}
	virtual ~Point2DT() {}

	void set_x( T x ) { _x = x; }
	T get_x(void) const { return _x; }
	void set_y( T y ) { _y = y; }
	T get_y(void) const { return _y; }

	/* Operator overloading */
	template <typename U>
	Point2DT<U> operator+(const Point2DT<U> &new_p)
	{
        return Point2DT<U>(_x + new_p.get_x(), _y + new_p.get_y());
    }

    template <typename U>
	Point2DT<U> operator-(const Point2DT<U> &new_p)
	{
        return Point2DT<U>(_x - new_p.get_x(), _y - new_p.get_y());
    }

    template <typename U>
	Point2DT<U> operator*(const Point2DT<U> &new_p)
	{
        return Point2DT<U>(_x * new_p.get_x(), _y * new_p.get_y());
    }

    template <typename U>
	Point2DT<U> &operator+=(const Point2DT<U> &new_p)
	{
        _x += new_p.get_x();
        _y += new_p.get_y();

        return *this;
    }

    template <typename U>
	Point2DT<U> &operator-=(const Point2DT<U> &new_p)
	{
        _x -= new_p.get_x();
        _y -= new_p.get_y();

        return *this;
    }

    template <typename U>
	Point2DT<U> &operator*=(const Point2DT<U> &new_p)
	{
        _x *= new_p.get_x();
        _y *= new_p.get_y();

        return *this;
    }

    template <typename U>
	Point2DT<U> &operator=(const Point2DT<U> &new_p)
	{
        _x = new_p.get_x();
        _y = new_p.get_y();

        return *this;
    }

    template <typename U>
	bool operator==(const Point2DT<U> &new_p)
	{
        return ((_x == new_p.get_x()) && (_y == new_p.get_y())) ? true : false;
    }

protected:
	T _x, _y;

};

typedef Point2DT<int> Point2D;
typedef Point2DT<double> Point2DF;

} // namespace shapes

#endif // !_SHAPES_COORDS_POINT_2D_INCLUDED_H_
