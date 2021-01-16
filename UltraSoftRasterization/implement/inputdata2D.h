#pragma once
// ----------- Input Data 2D -----------
// Author: stormhan
// Date: 2021/01/03

#ifndef __INPUT_DATA_2D__
#define __INPUT_DATA_2D__

#include "inputdatabase.h"
#include "math/vector.h"
#include <vector>

// ���դ����2D����
// Ŀǰ����load����Ϊ������vertex��index

class InputData2D : public InputDataBase
{
public:
	InputData2D();

	~InputData2D();

	virtual void loadVertexData();

	virtual void loadIndexData();

	const std::vector<Point2D> getVextexData();

	const std::vector<Uint32> getIndexData();

private:
	std::vector<Uint32> _indexes;
	std::vector<Point2D> _points;
};


#endif