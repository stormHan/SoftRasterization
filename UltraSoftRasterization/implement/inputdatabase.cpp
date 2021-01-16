
// Input data base implement

#include "inputdatabase.h"

InputDataBase::InputDataBase()
{}

InputDataBase::~InputDataBase()
{}

void InputDataBase::loadData()
{
	loadVertexData();

	loadIndexData();

	indexDataCheck();
}

void InputDataBase::indexDataCheck()
{
	// Todo
}