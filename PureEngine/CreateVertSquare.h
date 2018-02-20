#pragma once

#include "declspec.h"
#include <SFML/Graphics/Color.hpp>

namespace sf
{
	class VertexArray;
	template <typename T> class Rect;
	typedef Rect<float> FloatRect;
}

namespace pure
{
	PUREENGINE_API sf::VertexArray createVertSquare(const sf::FloatRect& rect, const sf::Color& color = sf::Color::Green);
}

