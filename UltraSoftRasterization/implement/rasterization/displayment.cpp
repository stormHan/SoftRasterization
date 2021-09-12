
#include "rasterization/displayment.h"

namespace rasterization
{
	IDisplay::~IDisplay()
	{}

	DisplayOpenCv::DisplayOpenCv(std::shared_ptr<RenderTarget>& rt, std::string& name) : _displayRT(rt), _displayName(name)
	{
		int w = rt->getRenderTargetDesc()->getWidth();
		int h = rt->getRenderTargetDesc()->getHeight();

		_displayMat = cv::Mat::zeros(h, w, CV_8UC3);
	}

	DisplayOpenCv::~DisplayOpenCv()
	{
		cv::destroyWindow(_displayName.c_str());

		_displayMat.release();
	}

	void DisplayOpenCv::display()
	{
		dataTransfer();
		displayCV();
	}

	void DisplayOpenCv::dataTransfer()
	{
		for (int i = 0; i < _displayMat.rows; ++i)
		{
			for (int j = 0; j < _displayMat.cols; ++j)
			{
				Color tColor = _displayRT->getColor(Uint32(j), Uint32(i));
				_displayMat.at<cv::Vec3b>(i, j)[0] = (uchar)(tColor.r * 255);
				_displayMat.at<cv::Vec3b>(i, j)[1] = (uchar)(tColor.g * 255);
				_displayMat.at<cv::Vec3b>(i, j)[2] = (uchar)(tColor.b * 255);
			}
		}
	}

	void DisplayOpenCv::displayCV()
	{
		cv::namedWindow(_displayName.c_str()); // 创建一个标题为 "hello" 的窗口
		cv::imshow(_displayName.c_str(), _displayMat); // 在窗口 "hello" 中显示图片
		cv::waitKey(0);
	}
}