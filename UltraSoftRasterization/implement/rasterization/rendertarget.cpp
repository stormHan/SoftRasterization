
#include "rendertarget.h"

namespace rasterization
{
	RenderTargetDesc::RenderTargetDesc(Uint32 w, Uint32 h) : _width(w), _height(h)
	{}

	RenderTargetDesc::~RenderTargetDesc()
	{}

	void RenderTargetDesc::SetRenderTargetDescWidthHeight(const Uint32 w, const Uint32 h)
	{
		_width = w;
		_height = h;
	}

	const Uint32 RenderTargetDesc::getWidth() const
	{
		return _width;
	}

	const Uint32 RenderTargetDesc::getHeight() const
	{
		return _height;
	}

	RenderTarget::RenderTarget(Uint32 w, Uint32 h)
	{
		_desc = new RenderTargetDesc(w, h);

		_bg_color = new Color(1.0, 1.0, 1.0, 1.0); // default color: White
		_bg_depth = 1.0;

		_render_target = PixelMat(h, PixelRow(w, Pixel(*_bg_color, _bg_depth)));
	}

	RenderTarget::~RenderTarget()
	{
		delete _desc;
		_desc = nullptr;

		delete _bg_color;
		_bg_color = nullptr;
	}

	const RenderTargetDesc* RenderTarget::getRenderTargetDesc() const
	{
		return _desc;
	}
}