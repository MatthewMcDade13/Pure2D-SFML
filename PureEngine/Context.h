#pragma once

namespace sf
{
	class RenderWindow;
}

namespace pure
{
	struct Context
	{
		struct ResourceHolder* resources;
		sf::RenderWindow* window;
		class Player* player;
	};
}
