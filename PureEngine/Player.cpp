#include "stdafx.h"
#include "Player.h"
#include "Entity.h"

using namespace pure;

Player::Player()
{ }

Player::~Player()
{ }

void Player::bindKey(sf::Keyboard::Key key, Action actionBinding)
{
	m_keybinds[key] = actionBinding;
}

void Player::removeBinding(sf::Keyboard::Key key)
{
	m_keybinds.erase(key);
}

void Player::handleLiveInput(float deltaTime)
{
	for (const auto& p : m_keybinds)
	{
		if (sf::Keyboard::isKeyPressed(p.first))
			p.second(deltaTime);
	}
}

