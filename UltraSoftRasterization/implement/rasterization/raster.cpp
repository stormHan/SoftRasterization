#include "raster.h"

namespace rasterization
{
	Rasterization::Rasterization() : _is_multisample(false)
	{
	}

	Rasterization::~Rasterization()
	{
	}

	void Rasterization::raster2D(RenderTarget* rt, const std::vector<Triangle2Df>& triangles)
	{

		for (auto tri : triangles)
		{
			
			
			rasterSingleTriangle(rt, tri);
		}

	}



	void Rasterization::rasterSingleTriangle(RenderTarget* rt, const Triangle2Df& tri)
	{

	}

	void Rasterization::drawLine(RenderTarget* rt, const Point2D& v1, const Point2D& v2, const Color& color)
	{
		/*for (float t = 0.; t < 1.; t += .01) {
			int x = x0 + (x1 - x0) * t;
			int y = y0 + (y1 - y0) * t;
			rt->setColor(x, y, color);
		}*/
	}

	void Rasterization::drawTriangle(RenderTarget* rt, const Triangle2Df& tri, const Color& color)
	{
		Point2D p1 = transferNDCtoScreenCoord(rt->getRenderTargetDesc()->getWidth(), rt->getRenderTargetDesc()->getHeight(), tri._p1);
		Point2D p2 = transferNDCtoScreenCoord(rt->getRenderTargetDesc()->getWidth(), rt->getRenderTargetDesc()->getHeight(), tri._p2);
		Point2D p3 = transferNDCtoScreenCoord(rt->getRenderTargetDesc()->getWidth(), rt->getRenderTargetDesc()->getHeight(), tri._p3);

		drawLine(rt, p1, p2, color);
		drawLine(rt, p2, p3, color);
		drawLine(rt, p3, p1, color);
	}

	Point2D& Rasterization::transferNDCtoScreenCoord(const int& width, const int& height, const Point2D& ndcVertex)
	{
		Float x = width * (ndcVertex._x / 2.0 + 0.5f);
		Float y = height * (ndcVertex._y / 2.0 + 0.5f);
		Point2D tPoint(x, y);
		return tPoint;
	}

}