#pragma once

#include "ResourceManager.h"

namespace sf
{
	class Texture;
	class Font;
	class Image;
}

struct ResourceHolder
{
	pure::ResourceManager<sf::Texture> textureManager;
	pure::ResourceManager<sf::Font> fontManager;
	pure::ResourceManager<sf::Image> imageManager;
};