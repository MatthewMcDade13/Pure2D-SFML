#pragma once

#ifdef PUREENGINE_EXPORTS
#define PUREENGINE_API __declspec(dllexport)
#else
#define PUREENGINE_API __declspec(dllimport)
#endif

#include <vector>
#include <string>

namespace pure
{
	PUREENGINE_API std::vector<std::string> splitString(const std::string& string, char delim);
}