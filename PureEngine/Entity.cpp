#include "stdafx.h"
#include "Conversions.h"
#include "Entity.h"

using namespace pure; using namespace sf;

Entity::Entity(): m_velocity({0.f,0.f})
{
}


Entity::~Entity()
{
}

void Entity::setVelocity(Vector2f velocity)
{
	m_velocity = velocity;
}

Vector2f Entity::getForwardDirection() const
{
	const float rotation = radians(getRotation());
	const float dx = sinf(rotation);
	const float dy = -cosf(rotation);

	return Vector2f(dx, dy);

}

void Entity::setVelocity(float velX, float velY)
{
	m_velocity = Vector2f(velX, velY);
}

void pure::Entity::addVelocity(Vector2f velocity)
{
	m_velocity += velocity;
}

Vector2f Entity::getVelocity() const
{
	return m_velocity;
}

