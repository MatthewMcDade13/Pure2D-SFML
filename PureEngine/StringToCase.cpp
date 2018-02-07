#include "stdafx.h"
#include "StringToCase.h"
#include <algorithm>

using std::string;
using std::transform;

std::string pure::stringToUpper(const std::string & str)
{
	string cpy(str);

	transform(cpy.begin(), cpy.end(), cpy.begin(), ::toupper);

	return cpy;
}

std::string pure::stringToLower(const std::string & str)
{
	string cpy(str);

	transform(cpy.begin(), cpy.end(), cpy.begin(), ::tolower);

	return cpy;
}
