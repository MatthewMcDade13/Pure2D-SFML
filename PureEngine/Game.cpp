#include "stdafx.h"
#include "Game.h"

#include <thread>
#include <exception>

using sf::VideoMode;
using sf::RenderWindow;
using pure::Game;

Game::Game(): m_bShowFPS(false), m_name("")
{
}

Game::~Game()
{
}

RenderWindow& Game::getWindow()
{
	return m_window;
}

void Game::createWindow(const VideoMode vm, const std::string& title)
{
	m_name = title;
	m_window.create(vm, title);
}

void Game::start()
{
	m_window.setActive(false);

	std::thread renderThread(&Game::render, std::ref(*this));

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}

			handleInput(event);
		}
	}

	renderThread.join();
}

void Game::setFPS(bool show)
{
	m_bShowFPS = show;
}

void Game::render()
{
	onGameStart();

	sf::Clock clock;

	while (m_window.isOpen())
	{
		m_window.clear();

		float elapsedTime = clock.restart().asSeconds();

		if (m_bShowFPS)
		{
			m_window.setTitle(m_name + " - FPS: " + std::to_string(1 / elapsedTime));
		}

		update(elapsedTime);

		m_window.display();
	}	
}
