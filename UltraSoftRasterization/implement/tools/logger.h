#pragma once
// ----------- Log System -----------
// Author: stormhan
// Date: 2021/01/03

#ifndef __LOGGER__
#define __LOGGER__

#include <iostream>

inline void Log(const char* logstr)
{
	std::cout << "[LogWarning] " << logstr << std::endl;
}

inline void LogWarning(const char* logstr)
{
	std::cout << "[LogWarning] " << logstr << std::endl;
}

inline void LogError(const char* logstr)
{
	std::cout << "[LogError] " << logstr << std::endl;
}


#endif