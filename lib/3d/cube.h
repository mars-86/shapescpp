#ifndef _SHAPES_LIB_3D_CUBE_INCLUDED_H_
#define _SHAPES_LIB_3D_CUBE_INCLUDED_H_
#pragma once

#include "hyperrect.h"

namespace shapes {

template <typename T>
class CubeT : public HyperrectT<T> {
public:
	CubeT(T x, T y, T z, T size)
		: HyperrectT<T>(x, y, z, size, size, size) {}

	~CubeT() {}
};

typedef CubeT<int> Cube;
typedef CubeT<double> CubeF;

} // namespace shapes

#endif // !_SHAPES_LIB_3D_CUBE_INCLUDED_H_
