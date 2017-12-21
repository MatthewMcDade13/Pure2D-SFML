#include "stdafx.h"
#include "SplitString.h"

#include <sstream>

std::vector<std::string> pure::splitString(const std::string & string, char delim)
{
	std::vector<std::string> strings;
	std::istringstream ss(string);
	std::string buffer;
	while (std::getline(ss, buffer, delim))
	{
		strings.push_back(buffer);
	}

	return std::move(strings);
}
