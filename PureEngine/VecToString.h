#pragma once

#include "declspec.h"
#include <string>

namespace sf
{
	template<typename T>
	class Vector2;
}

namespace pure
{
	template <typename T>
	std::string vecToString(sf::Vector2<T> vec)
	{
		std::string vecStr = "X: ";
		vecStr += vec.x;
		vecStr += " Y: ";
		vecStr += vec.y;
		return vecStr;
	}
}

