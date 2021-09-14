#pragma once

#ifndef __VECTOR__
#define __VECTOR__

#include "commondefine.h"
#include "mathconst.h"

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
		this->_x = rhs._x;
		this->_y = rhs._y;

		return *this;
	}

	Vector2 operator +(const Vector2& rhs)
	{
		return Vector2(_x + rhs._x, _y + rhs._y);
	}

	Vector2 operator -(const Vector2& rhs)
	{
		return Vector2(_x - rhs._x, _y - rhs._y);
	}


	~Vector2()
	{}

	T _x;
	T _y;
};

template <class T>
class Vector3
{
public:

	Vector3(T x0, T y0, T z0) : x(x0), y(y0), z(z0)
	{}

	Vector3(const Vector3& rhs) : x(rhs.x), y(rhs.y), z(rhs.z)
	{}


	~Vector3()
	{}

	Vector3& operator =(const Vector3& rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;

		return *this;
	}

	Vector3 operator +(const Vector3& rhs)
	{
		return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	Vector3 operator -(const Vector3& rhs)
	{
		return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	Vector3 cross(const Vector3& rhs) const
	{
		T x0 = y * rhs.z - z * rhs.y;
		T y0 = z * rhs.x - x * rhs.z;
		T z0 = x * rhs.y - y * rhs.x;
		return Vector3(x0, y0, z0);
	}

	Float dot(const Vector3& rhs) const
	{
		return x * rhs.x + y * rhs.y + z * rhs.z;
	}

	Vector3 normalize()
	{
		Float len = length();

		if (len > math::EPSILON)
		{
			Float recip = 1 / len;
			return Vector3(x * recip, y * recip, z * recip);
		}
		else
		{
			return Vector3(0, 0, 0);
		}
	}

	Float length() const
	{
		return (Float)sqrt(x * x + y * y + z * z);
	}

	T x;
	T y;
	T z;
};

typedef Vector2<Float> Point2D, Vector2f;
typedef Vector2<Uint32> Point2Di, Vector2ui;

typedef Vector3<Float> Vector3f;
typedef Vector3<int>   Vector3i;
#endif // __VECTOR__