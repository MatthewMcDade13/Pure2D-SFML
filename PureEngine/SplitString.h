﻿#pragma once

#include "declspec.h"

#include <vector>
#include <string>

namespace pure
{
	PUREENGINE_API std::vector<std::string> splitString(const std::string& string, char delim);
}