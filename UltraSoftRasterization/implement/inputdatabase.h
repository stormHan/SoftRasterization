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
	~InputDataBase();

	virtual void loadData() = 0;

private:

};

#endif