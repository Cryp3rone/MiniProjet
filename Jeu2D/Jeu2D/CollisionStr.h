#pragma once
#include <SFML/Graphics.hpp>

struct Collision {
	bool isOnCollision;
	sf::RectangleShape* rectangleCol;
	sf::CircleShape* circleCol;
};