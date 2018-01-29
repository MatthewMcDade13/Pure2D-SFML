#include "stdafx.h"
#include "Player.h"
#include "Entity.h"

using namespace pure;

pure::Player::Player():
	m_entity(nullptr)
{ }

pure::Player::~Player()
{ }

void pure::Player::removeEntity()
{
	m_entity = nullptr;
}

void Player::setEntity(std::unique_ptr<Entity>& entity)
{
	m_entity = std::move(entity);
}

const Entity* Player::getEntity() const
{
	return m_entity.get();
}

void pure::Player::bindKey(sf::Keyboard::Key key, Action actionBinding)
{
	m_keybinds[key] = actionBinding;
}

void pure::Player::removeBinding(sf::Keyboard::Key key)
{
	m_keybinds.erase(key);
}

void pure::Player::handleLiveInput(float deltaTime)
{
	for (const auto& p : m_keybinds)
	{
		if (sf::Keyboard::isKeyPressed(p.first))
			p.second(deltaTime);
	}
}

