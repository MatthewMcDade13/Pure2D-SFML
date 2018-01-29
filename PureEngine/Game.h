#pragma once

#ifdef PUREENGINE_EXPORTS
#define PUREENGINE_API __declspec(dllexport)
#else
#define PUREENGINE_API __declspec(dllimport)
#endif

#include <string>

namespace sf
{
	class Event;
	class RenderWindow;
	class VideoMode;
}


namespace pure
{
	struct ResourceHolder;
	struct Context;

	class PUREENGINE_API Game
	{
	public:
		Game();
		Game(const Game& g) = delete;
		virtual ~Game();

		Game& operator=(const Game& g) = delete;

		sf::RenderWindow& getWindow();

		void createWindow(const sf::VideoMode vm, const std::string& title);

		void start();

		void setFPS(bool show);

		void setFrameTime(float framesPerSecond);

		void setUseFixedTimeStep(bool shouldUseTimeStep);

	protected:
		ResourceHolder m_resources;
		Context m_context;

		virtual void onGameStart() = 0;

		virtual void draw() = 0;

		virtual void update(float deltaTime) = 0;

		virtual void handleInput(const sf::Event& event) = 0;

	private:

		sf::RenderWindow m_window;
		std::string m_name;
		bool m_bShowFPS;
		bool m_bUseFixedTimeStep;
		sf::Time m_timePerFrame;

		void processInput();
		void render();

	};
}





