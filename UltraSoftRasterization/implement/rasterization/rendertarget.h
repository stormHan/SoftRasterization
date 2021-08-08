#pragma once
// ----------- RenderTarget -----------
// Author: stormhan
// Date: 2021/01/23

#ifndef __RENDER_TARGET__
#define __RENDER_TARGET__

#include <vector>
#include <memory>

#include "math/commondefine.h"
#include "pixel.h"

namespace rasterization
{
	class RenderTargetDesc
	{
	public:

		RenderTargetDesc(Uint32 w, Uint32 h);

		~RenderTargetDesc();

		void SetRenderTargetDescWidthHeight(const Uint32 w, const Uint32 h);

		const Uint32 getWidth() const;

		const Uint32 getHeight() const;

	private:
		Uint32 _width;
		Uint32 _height;
	};

	class RenderTarget
	{
	public:
		RenderTarget(Uint32 w, Uint32 h);
		~RenderTarget();

		const RenderTargetDesc* getRenderTargetDesc() const;

		void clear();

	private:
		RenderTargetDesc* _desc;
		Pixel* _render_target;

		Color* _bg_color;
		float _bg_depth;
	};
}


#endif // __RENDER_TARGET__