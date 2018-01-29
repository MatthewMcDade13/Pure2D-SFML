#pragma once

#include "ResourceManager.h"

namespace sf
{
	class Texture;
	class Font;
	class Image;
}

namespace pure
{
	struct ResourceHolder
	{
		pure::ResourceManager<sf::Texture> textureManager;
		pure::ResourceManager<sf::Font> fontManager;
		pure::ResourceManager<sf::Image> imageManager;
	};
}
