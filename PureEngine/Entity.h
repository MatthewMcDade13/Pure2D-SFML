#pragma once

#include "declspec.h"

#include "SceneNode.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace pure
{
	class PUREENGINE_API Entity : public SceneNode
	{
	public:
		Entity();
		virtual ~Entity();
		void setVelocity(sf::Vector2f velocity);
		void setVelocity(float velX, float velY);

		// Shorthand for setVelocity(getVelocity() + velocity);
		void addVelocity(sf::Vector2f velocity);

		sf::Vector2f getVelocity() const;

	protected:
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	private:
		sf::Vector2f m_velocity;
	};

}

