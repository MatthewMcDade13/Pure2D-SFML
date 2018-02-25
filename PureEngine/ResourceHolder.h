#pragma once

#include "ResourceManager.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

namespace pure
{
	struct ResourceHolder
	{
		ResourceManager<sf::Texture> textureManager;
		ResourceManager<sf::Font> fontManager;
		ResourceManager<sf::Image> imageManager;
		ResourceManager<sf::SoundBuffer> soundManager;
	};
}
