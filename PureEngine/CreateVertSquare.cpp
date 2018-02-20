#include "stdafx.h"
#include "CreateVertSquare.h"

using namespace sf;

VertexArray pure::createVertSquare(const FloatRect& rect, const sf::Color& color)
{
	VertexArray vr;
	vr.setPrimitiveType(LineStrip);

	vr.append(Vertex(Vector2f(rect.left, rect.top), color));
	vr.append(Vertex(Vector2f(rect.left + rect.width, rect.top), color));
	vr.append(Vertex(Vector2f(rect.left + rect.width, rect.top + rect.height), color));
	vr.append(Vertex(Vector2f(rect.left, rect.top + rect.height), color));
	vr.append(Vertex(Vector2f(rect.left, rect.top), color));

	return vr;
}
