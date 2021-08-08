#pragma once

#ifndef __VECTOR__
#define __VECTOR__

#include "commondefine.h"

template <typename T>
class Vector2
{
public:
	Vector2(T x, T y) : _x(x), _y(y)
	{}

	/*Vector2(const T& x, const T& y) : _x(x), _y(y)
	{}*/

	Vector2(const Vector2& vec2) : _x(vec2._x), _y(vec2._y)
	{}

	Vector2& operator =(const Vector2& rhs)
	{
		return Vector2(rhs._x, rhs._y);
	}

	Vector2& operator +(const Vector2& rhs)
	{
		return Vector2(_x + rhs._x, _y + rhs._y);
	}

	Vector2& operator -(const Vector2& rhs)
	{
		return Vector2(_x - rhs._x, _y - rhs._y);
	}


	~Vector2()
	{}

	T _x;
	T _y;
};

typedef Vector2<Float> Point2D;

#endif // __VECTOR__