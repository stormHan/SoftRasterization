#include "raster.h"
#include <algorithm>

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
			fillTriangle(rt, tri, color);
			//drawTriangle(rt, tri, color);
		}
	}



	void Rasterization::fillTriangle(std::shared_ptr<RenderTarget> rt, const Triangle2Df& tri, const Color& color)
	{
		Uint32 width = rt->getRenderTargetDesc()->getWidth(), height = rt->getRenderTargetDesc()->getHeight();

		Vector2ui bboxmin(width - 1, height - 1);
		Vector2ui bboxmax(0, 0);
		Vector2ui clamp(width - 1, height - 1);

		Point2Di p1 = transferNDCtoScreenCoord(width, height, tri._p1);
		Point2Di p2 = transferNDCtoScreenCoord(width, height, tri._p2);
		Point2Di p3 = transferNDCtoScreenCoord(width, height, tri._p3);
		
		bboxmin._x = std::max((Uint32)0, std::min(bboxmin._x, p1._x));
		bboxmin._x = std::max((Uint32)0, std::min(bboxmin._x, p2._x));
		bboxmin._x = std::max((Uint32)0, std::min(bboxmin._x, p3._x));
		bboxmin._y = std::max((Uint32)0, std::min(bboxmin._y, p1._y));
		bboxmin._y = std::max((Uint32)0, std::min(bboxmin._y, p2._y));
		bboxmin._y = std::max((Uint32)0, std::min(bboxmin._y, p3._y));

		bboxmax._x = std::min(clamp._x, std::max(bboxmax._x, p1._x));
		bboxmax._x = std::min(clamp._x, std::max(bboxmax._x, p2._x));
		bboxmax._x = std::min(clamp._x, std::max(bboxmax._x, p3._x));
		bboxmax._y = std::min(clamp._y, std::max(bboxmax._y, p1._y));
		bboxmax._y = std::min(clamp._y, std::max(bboxmax._y, p2._y));
		bboxmax._y = std::min(clamp._y, std::max(bboxmax._y, p3._y));

		Triangle2Dui tri_d(p1, p2, p3);

		/*for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				bboxmin[j] = std::max(0, std::min(bboxmin[j], pts[i][j]));
				bboxmax[j] = std::min(clamp[j], std::max(bboxmax[j], pts[i][j]));
			}
		}*/
		Point2Di p(0, 0);
		for (p._x = bboxmin._x; p._x <= bboxmax._x; p._x++)
		{
			for (p._y = bboxmin._y; p._y <= bboxmax._y; p._y++)
			{
				Vector3f bc_screen = computeBarycenterCoordinates(tri_d, p);
				if (bc_screen.x < 0 || bc_screen.y < 0 || bc_screen.z < 0) continue;
				rt->setColor(p._x, p._y, color);
			}
		}

		/*
		 Vec2i P;
		for (P.x=bboxmin.x; P.x<=bboxmax.x; P.x++) {
			for (P.y=bboxmin.y; P.y<=bboxmax.y; P.y++) {
				Vec3f bc_screen  = barycentric(pts, P);
				if (bc_screen.x<0 || bc_screen.y<0 || bc_screen.z<0) continue;
				image.set(P.x, P.y, color);
		}
	}
		
		*/
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
		return Point2Di(x, y);
	}

	const Vector3f Rasterization::computeBarycenterCoordinates(const Triangle2Dui& tri, const Point2Di& point)
	{
		Vector3f u = Vector3f(tri._p3._x - tri._p1._x, tri._p2._x - tri._p1._x, tri._p1._x - point._x)
			.cross(Vector3f(tri._p3._y - tri._p1._y, tri._p2._y - tri._p1._y, tri._p1._y - point._y));

		if (std::abs(u.z) < 1) return Vector3f(-1, 1, 1);
		return Vector3f(1.f - (u.x + u.y) / u.z, u.y / u.z, u.x / u.z);
	}
}