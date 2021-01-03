
#include "inputdata2D.h"

InputData2D::InputData2D()
{}

InputData2D::~InputData2D()
{
	_points.clear();
}

void InputData2D::loadData()
{
	Point2D p1(0.5, 1.0), p2(0.0, 0.0), p3(1.0, 0.0);
	_points.push_back(p1);
	_points.push_back(p2);
	_points.push_back(p3);
}