#pragma once
// ----------- Input Data -----------
// Author: stormhan
// Date: 2021/01/03

#ifndef __INPUT_DATA_BASE__
#define __INPUT_DATA_BASE__

class InputDataBase
{
public:

	InputDataBase();

	virtual ~InputDataBase();

	virtual void loadData();

	virtual void loadIndexData() = 0;

	virtual void loadVertexData() = 0;

	void indexDataCheck();

private:

};

#endif