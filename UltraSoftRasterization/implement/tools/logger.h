#pragma once
// ----------- Log System -----------
// Author: stormhan
// Date: 2021/01/03

#ifndef __LOGGER__
#define __LOGGER__

#include <iostream>

void Log(const char* logstr)
{
	std::cout << "[LogWarning] " << logstr << std::endl;
}

void LogWarning(const char* logstr)
{
	std::cout << "[LogWarning] " << logstr << std::endl;
}

void LogError(const char* logstr)
{
	std::cout << "[LogError] " << logstr << std::endl;
}


#endif