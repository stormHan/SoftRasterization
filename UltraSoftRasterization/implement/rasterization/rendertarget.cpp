
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

		_render_target = new Pixel[w * h];
		memset(_render_target, 0, sizeof(Pixel) * w * h);

		/*for (Uint32 i = 0; i < w * h; ++i)
		{
			_render_target[i].setColor(*_bg_color);
			_render_target[i].setDepth(1.0f);
		}*/
	}

	void RenderTarget::clear()
	{
		Uint32 w = _desc->getWidth(), h = _desc->getHeight();

		for (Uint32 i = 0; i < w * h; ++i)
		{
			_render_target[i].setColor(*_bg_color);
			_render_target[i].setDepth(1.0f);
		}
	}
	void RenderTarget::setColor(const Uint32& x, const Uint32& y, const Color& color)
	{
		if (x >= _desc->getWidth() || y >= _desc->getHeight())
		{
			LogWarning("[RenderTarget] setColor failed , w or h oversize");
			return;
		}

		//setRawColor
		_render_target[y * _desc->getWidth() + x].setColor(color);
	}

	const Color& RenderTarget::getColor(const Uint32& x, const Uint32& y)
	{
		if (x >= _desc->getWidth() || y >= _desc->getHeight())
		{
			LogWarning("[RenderTarget] getColor failed , w or h oversize");
			return Color();
		}

		return _render_target[y * _desc->getWidth() + x].getColor();
	}

	RenderTarget::~RenderTarget()
	{
		delete _desc;
		_desc = nullptr;

		delete _bg_color;
		_bg_color = nullptr;

		delete[] _render_target;
		_render_target = nullptr;
	}

	const RenderTargetDesc* RenderTarget::getRenderTargetDesc() const
	{
		return _desc;
	}
}