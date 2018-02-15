#pragma once

#include "declspec.h"

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <memory>
#include <vector>

/******************************************************************************************/
/******************************************************************************************/
/*************************************D E P R E C A T E D**********************************/
/******************************************************************************************/
/******************************************************************************************/

namespace pure
{
	class PUREENGINE_API SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
	{
	public:
		typedef std::unique_ptr<SceneNode> SceneNodePtr;

		SceneNode();
		virtual ~SceneNode();

		void attachChild(SceneNodePtr childNode);

		SceneNodePtr removeChild(const SceneNode& node);

		void update(float deltaTime);

		// Gets transform of enitre scene node - current node as well as children
		sf::Transform getWorldTransform() const;

		// Gets position of enitre scene node - current node as well as children
		sf::Vector2f getWorldPosition() const;

	protected:
		// Draws the current Scene Node.
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const = 0;

		// Updates the current Scene Node
		virtual void updateCurrent(float deltaTime) { };

	private:
		SceneNode * m_parent;
		std::vector<SceneNodePtr> m_children;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;
		void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

		void updateChildren(float deltaTime);
	};
}


