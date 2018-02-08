#pragma once

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
		vecStr += to_string(vec.x);
		vecStr += " Y: ";
		vecStr += to_string(vec.y);
		return vecStr;
	}
}

