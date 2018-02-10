#pragma once

#include "declspec.h"

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/NonCopyable.hpp>
#include "ResourceHolder.h"
#include "Context.h"


namespace pure
{

	class PUREENGINE_API Game : private sf::NonCopyable
	{
	public:
		Game();
		virtual ~Game();

		const sf::RenderWindow& getWindow() const;

		void createWindow(const sf::VideoMode vm, const std::string& title);

		void start();

		void setFPS(bool show);

		void setFrameTime(float framesPerSecond);

		void setUseFixedTimeStep(bool shouldUseTimeStep);

	protected:
		sf::RenderWindow m_window;
		ResourceHolder m_resources;
		Context m_context;

		virtual void onGameStart() = 0;

		virtual void draw() = 0;

		virtual void update(float deltaTime) = 0;

		virtual void handleInput(const sf::Event& event) { }

	private:
		std::string m_name;
		bool m_bShowFPS;
		bool m_bUseFixedTimeStep;
		sf::Time m_timePerFrame;

		void processInput();
		void render();

	};
}





