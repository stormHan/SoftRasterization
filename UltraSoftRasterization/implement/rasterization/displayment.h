#pragma once
/*
	display class

	负责把最终的render target数据显示在屏幕上
*/

#ifndef __DISPLAYMENT__
#define __DISPLAYMENT__

#include <memory>
#include "rasterization/rendertarget.h"
#include <opencv2/opencv.hpp>
//#include <opencv2/core/hal/interface.h>

namespace rasterization {

	class IDisplay
	{
	public:
		IDisplay() {};

		virtual ~IDisplay() = 0;

		virtual void display() = 0;
	};


	class DisplayOpenCv : public IDisplay
	{
	public :
		DisplayOpenCv(std::shared_ptr<RenderTarget>& rt, std::string& name);

		virtual void display() override;

		virtual ~DisplayOpenCv() override;

	private:
		void displayCV();

		void dataTransfer();

	private:
		std::shared_ptr<RenderTarget> _displayRT;
		cv::Mat _displayMat;
		std::string _displayName;
		//Uint32 _width, _height;
	};
}


#endif // __DISPLAYMENT__