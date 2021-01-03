// ----------- Soft Rasterization -----------
// Author: stormhan
// Date: 2021/01/03

#ifndef __ENTRANCE__
#define __ENTRANCE__

#include "tools/logger.h"
#include "inputdata2D.h"

int main(int argc, char** argv)
{
	Log("Soft Rasterization starts...");

	InputData2D single_input;
	single_input.loadData();


	Log("Soft Rasterization ends...");
	return 0;
}


#endif