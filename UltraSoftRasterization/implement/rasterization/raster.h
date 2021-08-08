#pragma once
#ifndef __RASTER__
#define __RASTER__

#include "rendertarget.h"
#include "../math/triangle.h"

namespace rasterization
{
	// ��raster��ǰ��render target, �ٸ���ǰһ��Ҫ��raster��buffer(2d or 3d)�����raster֮���render texture.

	class Rasterization final
	{
	public:

		Rasterization();

		~Rasterization();

		void raster2D(RenderTarget* rt, const std::vector<Triangle2Df>& triangles);

		// ��һ��2D��������������һ��rt�������ݵ�д��.
		void rasterSingleTriangle(RenderTarget* rt, const Triangle2Df& tri);

		// ����
		void drawLine(RenderTarget* rt, const Point2D& v1, const Point2D& v2, const Color& color);

		//��������
		void drawTriangle(RenderTarget* rt, const Triangle2Df& tri, const Color& color);

	private:
		Point2D& transferNDCtoScreenCoord(const int& width, const int& height, const Point2D& ndcVertex);

		bool _is_multisample;

	};
}


#endif // __RASTER__