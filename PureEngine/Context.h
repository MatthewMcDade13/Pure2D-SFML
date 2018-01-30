#pragma once

namespace sf
{
	class RenderWindow;
}

namespace pure
{
	struct Context
	{
		class ResourceHolder* resources;
		sf::RenderWindow* window;
		class Player* player;
	};
}
