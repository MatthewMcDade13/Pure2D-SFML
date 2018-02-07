#include "stdafx.h"
#include "FlattenStrings.h"

std::string pure::flattenStrings(const std::vector<std::string> strings)
{
	std::string newString = "";

	for (size_t i = 0; i < strings.size(); i++)
	{
		newString += strings[i];
	}

	return newString;
}
