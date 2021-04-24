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

		void Raster2D(RenderTarget* rt, const std::vector<Triangle2Df> triangles);

	private:

		bool _is_multisample;

	};
}


#endif // __RASTER__