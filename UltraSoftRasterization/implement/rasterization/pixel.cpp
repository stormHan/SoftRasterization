
#include "pixel.h"

namespace rasterization
{
	Pixel::Pixel() : _color(0.0, 0.0, 0.0), _depth(1.0)
	{}

	Pixel::Pixel(const Color& color, const float depth) : _color(color), _depth(depth)
	{}

	Pixel::Pixel(const Pixel& rhs)
	{
		_color = rhs._color;
		_depth = rhs._depth;
	}

	Pixel::~Pixel()
	{}

	Pixel& Pixel::operator=(const Pixel& rhs)
	{
		_color = rhs._color;
		_depth = rhs._depth;
		return *this;
	}

	void Pixel::setColor(const Color& color)
	{
		setColor(color.r, color.g, color.b, color.alpha);
	}

	void Pixel::setColor(float r, float g, float b, float alpha /* = 1.0 */)
	{
		_color.setColor(r, g, b, alpha);
	}

	void Pixel::setDepth(float depth)
	{
		_depth = depth;
	}

	Color& Pixel::getColor()
	{
		return _color;
	}
}