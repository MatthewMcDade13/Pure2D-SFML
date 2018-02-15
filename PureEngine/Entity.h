#pragma once

#include "declspec.h"

#include "SceneNode.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace pure
{
	class PUREENGINE_API Entity : public sf::Transformable, public sf::Drawable
	{
	public:
		Entity();
		virtual ~Entity();
		void setVelocity(sf::Vector2f velocity);
		void setVelocity(float velX, float velY);


		bool isActive() const;

		// Shorthand for setVelocity(getVelocity() + velocity);
		void addVelocity(sf::Vector2f velocity);

		virtual void update(float deltaTime) { };

		void activate();
		void deactivate();

		// Gets the normalized forward direction
		sf::Vector2f getForwardDirection() const;

		sf::Vector2f getVelocity() const;

	protected:
		virtual void onActivate() { }
		virtual void onDeactivate() { }

	private:
		bool m_bActive;
		sf::Vector2f m_velocity;
	};

}

