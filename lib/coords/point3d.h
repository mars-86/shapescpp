#ifndef _SHAPES_COORDS_POINT_3D_INCLUDED_H_
#define _SHAPES_COORDS_POINT_3D_INCLUDED_H_

#include "point2d.h"

namespace shapes {

template <typename T>
class Point3DT : public Point2DT<T> {
public:
	Point3DT() : Point2DT<T>(0, 0), _z(0) {}
	Point3DT(T x, T y, T z) : Point2DT<T>(x, y), _z(z) {}
	~Point3DT() {}

	void set_z( T z ) { _z = z; }
	T get_z(void) const { return _z; }

    /* Operator overloading */
	template <typename U>
	Point3DT<U> operator+(const Point3DT<U> &new_p)
	{
        return Point3DT<U>(this->_x + new_p.get_x(), this->_y + new_p.get_y(), _z + new_p.get_z());
    }

    template <typename U>
	Point3DT<U> operator-(const Point3DT<U> &new_p)
	{
        return Point3DT<U>(this->_x - new_p.get_x(), this->_y - new_p.get_y(), _z - new_p.get_z());
    }

    template <typename U>
	Point3DT<U> operator*(const Point3DT<U> &new_p)
	{
        return Point3DT<U>(this->_x * new_p.get_x(), this->_y * new_p.get_y(), _z * new_p.get_z());
    }

    template <typename U>
	Point3DT<U> &operator+=(const Point3DT<U> &new_p)
	{
        this->_x += new_p.get_x();
        this->_y += new_p.get_y();
        _z += new_p.get_z();

        return *this;
    }

    template <typename U>
	Point3DT<U> &operator-=(const Point3DT<U> &new_p)
	{
        this->_x -= new_p.get_x();
        this->_y -= new_p.get_y();
        _z -= new_p.get_z();

        return *this;
    }

    template <typename U>
	Point3DT<U> &operator*=(const Point3DT<U> &new_p)
	{
        this->_x *= new_p.get_x();
        this->_y *= new_p.get_y();
        _z *= new_p.get_z();

        return *this;
    }

    template <typename U>
	Point3DT<U> &operator=(const Point3DT<U> &new_p)
	{
        this->_x = new_p.get_x();
        this->_y = new_p.get_y();
        _z = new_p.get_z();

        return *this;
    }

    template <typename U>
	bool operator==(const Point3DT<U> &new_p)
	{
        return ((this->_x == new_p.get_x()) && (this->_y == new_p.get_y()) && (_z == new_p.get_z())) ? true : false;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Point3DT<U>& point)
    {
        return out << "{" << point.get_x() << ", " << point.get_y() << ", " << point.get_z() << "}" << std::endl;
    }

private:
	T _z;
};

typedef Point3DT<int> Point3D;
typedef Point3DT<double> Point3DF;

} // namespace shapes

#endif // !_SHAPES_COORDS_POINT_3D_INCLUDED_H_
