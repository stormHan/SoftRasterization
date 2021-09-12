#include "raster.h"

namespace rasterization
{
	Rasterization::Rasterization() : _is_multisample(false)
	{
	}

	Rasterization::~Rasterization()
	{
	}

	void Rasterization::raster2D(std::shared_ptr<RenderTarget> rt, const std::vector<Triangle2Df>& triangles, const Color& color)
	{
		for (auto tri : triangles)
		{
			//rasterSingleTriangle(rt, tri);
			drawTriangle(rt, tri, color);
		}
	}



	void Rasterization::rasterSingleTriangle(std::shared_ptr<RenderTarget> rt, const Triangle2Df& tri)
	{
		
	}

	void Rasterization::drawLine(std::shared_ptr<RenderTarget> rt, const Point2Di& v1, const Point2Di& v2, const Color& color)
	{
		int x0 = v1._x, y0 = v1._y, x1 = v2._x, y1 = v2._y;
		bool steep = false;

		if (std::abs(x0 - x1) < std::abs(y0 - y1))
		{
			std::swap(x0, y0);
			std::swap(x1, y1);
			steep = true;
		}

		if (x0 > x1)
		{
			std::swap(x0, x1);
			std::swap(y0, y1);
		}

		int dx = x1 - x0, dy = y1 - y0;
		float derror = std::abs(dy / float(dx));
		float error = 0;
		int y = y0;

		for (int x = x0; x <= x1; ++x)
		{
			if (steep)
			{
				rt->setColor(y, x, color);
			}
			else
			{
				rt->setColor(x, y, color);
			}
			error += derror;
			if (error > .5)
			{
				y += (y1 > y0 ? 1 : -1);
				error -= 1.;
			}
		}

	}

	void Rasterization::drawTriangle(std::shared_ptr<RenderTarget> rt, const Triangle2Df& tri, const Color& color)
	{
		Point2Di p1 = transferNDCtoScreenCoord(rt->getRenderTargetDesc()->getWidth(), rt->getRenderTargetDesc()->getHeight(), tri._p1);
		Point2Di p2 = transferNDCtoScreenCoord(rt->getRenderTargetDesc()->getWidth(), rt->getRenderTargetDesc()->getHeight(), tri._p2);
		Point2Di p3 = transferNDCtoScreenCoord(rt->getRenderTargetDesc()->getWidth(), rt->getRenderTargetDesc()->getHeight(), tri._p3);

		drawLine(rt, p1, p2, color);
		drawLine(rt, p2, p3, color);
		drawLine(rt, p3, p1, color);
	}

	const Point2Di Rasterization::transferNDCtoScreenCoord(const int& width, const int& height, const Point2D& ndcVertex)
	{
		Uint32 x = width * (ndcVertex._x / 2.0 + 0.5f);
		Uint32 y = height * (ndcVertex._y / 2.0 + 0.5f);
		Point2Di tPoint(x, y);
		return tPoint;
	}

}