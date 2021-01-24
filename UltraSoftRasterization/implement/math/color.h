#pragma once

#ifndef __COLOR__
#define __COLOR__

class Color final
{
public:
	Color() : r(0.0), g(0.0), b(0.0), alpha(1.0) {};

	Color(const float r0, const float g0, const float b0, const float a0 = 1.0) : r(r0), g(g0), b(b0), alpha(a0) {};

	~Color() {};

	Color(const Color& rhs)
	{
		r = rhs.r;
		g = rhs.g;
		b = rhs.b;
		alpha = rhs.alpha;
	}

	Color& operator= (const Color& rhs)
	{
		r = rhs.r;
		g = rhs.g;
		b = rhs.b;
		alpha = rhs.alpha;
		return *this;
	}

	void setColor(float r0, float g0, float b0, float a0 = 1.0)
	{
		r = r0;
		g = g0;
		b = b0;
		alpha = a0;
	}

	float r;
	float g;
	float b;
	float alpha;
};

#endif // __COLOR__