#include "stdafx.h"
#include "Tilemap.h"

using namespace pure;

Tilemap::Tilemap(sf::Texture* tileSheet, uint32 tileSize, uint32 mapSize, uint32 width, uint32 height)
	:m_tileSheet(tileSheet),
	m_tiles(sf::Quads, width * height * 4),
	m_tileSize(tileSize),
	m_mapSize(mapSize),
	m_width(width),
	m_height(height)
{
}


Tilemap::~Tilemap() { }

bool pure::Tilemap::mapToTiles(std::vector<int> tiles, std::function<sf::Vector2u(sf::VertexArray, sf::Vector2u)> getUV)
{
	return false;
}

void pure::Tilemap::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.texture = m_tileSheet;
	target.draw(m_tiles, states);
}
