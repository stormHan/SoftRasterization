#pragma once
// ----------- Pixel Data -----------
// Author: stormhan
// Date: 2021/01/23

#ifndef  __PIXEL__
#define __PIXEL__

#include <vector>
#include "math/color.h"

namespace rasterization
{
	enum PIXELSTATE
	{
		IN_TRIANGLE,
		OUT_TRIANGLE,
		OUTLINE_TRIANGLE,
	};

	class Pixel
	{
	public:
		Pixel();

		Pixel(const Color& color, const float depth);

		Pixel(const Pixel& rhs);

		~Pixel();

		Pixel& operator= (const Pixel& rhs);

		void setColor(const Color& color);

		void setColor(float r, float g, float b, float alpha = 1.0);

		void setDepth(float depth);

		Color& getColor();

	private:
		Color _color;
		float _depth;
	};

	typedef std::vector<Pixel> PixelRow;
	typedef std::vector<PixelRow> PixelMat;
}

#endif// __PIXEL__