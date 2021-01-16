
#include "inputdata2D.h"

InputData2D::InputData2D()
{}

InputData2D::~InputData2D()
{
	_points.clear();
}

void InputData2D::loadVertexData()
{
	// Fake data
	Point2D p1(0.5, 1.0), p2(0.0, 0.0), p3(1.0, 0.0);
	_points.push_back(p1);
	_points.push_back(p2);
	_points.push_back(p3);
}

void InputData2D::loadIndexData()
{
	// Fake data
	_indexes.push_back(0);
	_indexes.push_back(1);
	_indexes.push_back(2);
}

const std::vector<Point2D> InputData2D::getVextexData()
{
	return _points;
}

const std::vector<Uint32> InputData2D::getIndexData()
{
	return _indexes;
}