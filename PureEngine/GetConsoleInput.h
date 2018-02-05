#pragma once

#include "PureEngine.h"
#include <string>

namespace pure
{
	PUREENGINE_API std::string getConsoleInputstr(const std::string& message);

	PUREENGINE_API bool getConsoleInputb(const std::string& message, const std::string& errorMessage = "");

	PUREENGINE_API int getConsoleInputi(const std::string& message, const std::string& errorMessage = "");

	PUREENGINE_API long getConsoleInputl(const std::string& message, const std::string& errorMessage = "");

	PUREENGINE_API long long getConsoleInputll(const std::string& message, const std::string& errorMessage = "");
}