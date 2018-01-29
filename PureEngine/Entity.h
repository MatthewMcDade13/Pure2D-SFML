#pragma once

#ifdef PUREENGINE_EXPORTS
#define PUREENGINE_API __declspec(dllexport)
#else
#define PUREENGINE_API __declspec(dllimport)
#endif

#include "SceneNode.h"

namespace sf
{
	typedef Vector2f Vector2f;
}

namespace pure
{
	class PUREENGINE_API Entity : public SceneNode
	{
	public:
		Entity();
		virtual ~Entity();
		void setVelocity(sf::Vector2f velocity);
		void setVelocity(float velX, float velY);

		sf::Vector2f getVelocity() const;

	protected:
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	private:
		sf::Vector2f m_velocity;
	};

}

