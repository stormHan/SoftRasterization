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

		void raster2D(std::shared_ptr<RenderTarget> rt, const std::vector<Triangle2Df>& triangles, const Color& color);

		// ��һ��2D��������������һ��rt�������ݵ�д��.
		void rasterSingleTriangle(std::shared_ptr<RenderTarget> rt, const Triangle2Df& tri);

		// ����
		void drawLine(std::shared_ptr<RenderTarget> rt, const Point2Di& v1, const Point2Di& v2, const Color& color);

		//��������
		void drawTriangle(std::shared_ptr<RenderTarget> rt, const Triangle2Df& tri, const Color& color);

	private:
		const Point2Di transferNDCtoScreenCoord(const int& width, const int& height, const Point2D& ndcVertex);

		bool _is_multisample;

	};
}


#endif // __RASTER__