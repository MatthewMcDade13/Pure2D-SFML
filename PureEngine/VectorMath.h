#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

template <typename T>
float dot(sf::Vector2<T> lv, sf::Vector2<T> rv)
{
	return lv.x * rv.x + lv.y * rv.y;
}

template <typename T>
float dot(sf::Vector3<T> lv, sf::Vector3<T> rv)
{
	return lv.x * rv.x + lv.y * rv.y + lv.z * rv.z;
}

