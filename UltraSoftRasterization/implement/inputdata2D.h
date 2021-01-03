#pragma once
// ----------- Input Data 2D -----------
// Author: stormhan
// Date: 2021/01/03

#ifndef __INPUT_DATA_2D__
#define __INPUT_DATA_2D__

#include <vector>
#include "inputdatabase.h"

struct Point2D
{
	Point2D(float x, float y) : _x(x), _y(y)
	{};

	float _x;
	float _y;
};

class InputData2D : public InputDataBase
{
public:
	InputData2D();

	~InputData2D();

	virtual void loadData();

private:
	std::vector<Point2D> _points;
};


#endif