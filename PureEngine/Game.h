#pragma once

#ifdef PUREENGINE_EXPORTS
#define PUREENGINE_API __declspec(dllexport)
#else
#define PUREENGINE_API __declspec(dllimport)
#endif

#include "ResourceManager.h"
#include <SFML\Graphics.hpp>

namespace pure
{

	class PUREENGINE_API Game
	{
	public:
		Game();
		Game(const Game& g) = delete;
		virtual ~Game();

		Game& operator=(const Game& g) = delete;

		sf::RenderWindow& getWindow();

		void createWindow(const sf::VideoMode vm, const std::string& title);

		// Starts game loop
		void start();

		// Toggle showing fps in window title ON/OFF
		void setFPS(bool show);

	protected:
		ResourceManager<sf::Texture> m_textureMan;
		ResourceManager<sf::Font> m_fontMan;
		ResourceManager<sf::Image> m_imageMan;
		sf::RenderWindow m_window;

		// Called before game loop,
		// use this for setup
		virtual void onGameStart() = 0;

		// Called every frame	
		// derived class must handle drawing to window here
		virtual void update(float deltaTime) = 0;

		// Handle user input
		virtual void handleInput(const sf::Event& event) = 0;

	private:

		std::string m_name;
		bool m_bShowFPS;

	};


}





