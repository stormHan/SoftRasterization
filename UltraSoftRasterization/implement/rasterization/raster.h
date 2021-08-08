#pragma once
#ifndef __RASTER__
#define __RASTER__

#include "rendertarget.h"
#include "../math/triangle.h"

namespace rasterization
{
	// 给raster当前的render target, 再给当前一块要做raster的buffer(2d or 3d)，输出raster之后的render texture.

	class Rasterization final
	{
	public:

		Rasterization();

		~Rasterization();

		void raster2D(RenderTarget* rt, const std::vector<Triangle2Df>& triangles);

		// 对一个2D的三角形数据在一张rt上做数据的写入.
		void rasterSingleTriangle(RenderTarget* rt, const Triangle2Df& tri);

		// 画线
		void drawLine(RenderTarget* rt, const Point2D& v1, const Point2D& v2, const Color& color);

		//画三角形
		void drawTriangle(RenderTarget* rt, const Triangle2Df& tri, const Color& color);

	private:
		Point2D& transferNDCtoScreenCoord(const int& width, const int& height, const Point2D& ndcVertex);

		bool _is_multisample;

	};
}


#endif // __RASTER__