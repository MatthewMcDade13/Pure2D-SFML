#pragma once

#include <vector>
#include <string>

#ifdef PUREENGINE_EXPORTS
#define PUREENGINE_API __declspec(dllexport)
#else
#define PUREENGINE_API __declspec(dllimport)
#endif

namespace pure
{
	PUREENGINE_API std::string flattenStrings(const std::vector<std::string> strings);
}