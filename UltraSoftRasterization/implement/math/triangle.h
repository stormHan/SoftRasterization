#pragma once

// ----------- Triangle Data -----------
// Author: stormhan
// Date: 2021/01/16

#ifndef __TRIANGLE__
#define __TRIANGLE__

#include "vector.h"

template<typename T>
class Triangle2D
{
public:

	Triangle2D(const Vector2<T>& p1, const Vector2<T>& p2, const Vector2<T>& p3) :
		_p1(p1), _p2(p2), _p3(p3)
	{}

	~Triangle2D()
	{}

	Triangle2D(const Triangle2D& tri) : _p1(tri._p1), _p2(tri._p2), _p3(tri._p3)
	{
		//_p1 = tri._p1;
		//_p2 = tri._p2;
		//_p3 = tri._p3;
	}

	Triangle2D& operator =(const Triangle2D& rhs)
	{
		return Triangle2D(rhs._p1, rhs._p2, rhs._p3);
	}

	Vector2<T> _p1;
	Vector2<T> _p2;
	Vector2<T> _p3;
};

typedef Triangle2D<Float>	Triangle2Df;
typedef Triangle2D<Float64> Triangle2Dd;

#endif //__TRIANGLE__