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

		void Raster2D(RenderTarget* rt, const std::vector<Triangle2Df> triangles);

	private:

		bool _is_multisample;

	};
}


#endif // __RASTER__