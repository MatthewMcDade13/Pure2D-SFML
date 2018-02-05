#pragma once

#include "PureEngine.h"

#include <string>
#include <vector>
#include <functional>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace sf
{
	class Texture;
}

namespace pure
{
	class PUREENGINE_API Tilemap : sf::Drawable
	{
	public:
		Tilemap(sf::Texture* tileSheet, uint32 tileSize, uint32 mapSize, uint32 width, uint32 height);
		virtual ~Tilemap();

		bool mapToTiles(std::vector<int> tiles, std::function<sf::Vector2u(sf::VertexArray, sf::Vector2u)> getUV);

	private:

		sf::Texture* m_tileSheet;
		sf::VertexArray m_tiles;

		uint32 m_width;
		uint32 m_height;
		uint32 m_tileSize;
		uint32 m_mapSize;
		
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	};
}



