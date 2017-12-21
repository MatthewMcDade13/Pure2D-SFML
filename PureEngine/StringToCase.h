#pragma once

#ifdef PUREENGINE_EXPORTS
#define PUREENGINE_API __declspec(dllexport)
#else
#define PUREENGINE_API __declspec(dllimport)
#endif

#include <string>

namespace pure
{
	PUREENGINE_API std::string stringToUpper(const std::string& str);

	PUREENGINE_API std::string stringToLower(const std::string& str);
}
