#pragma once
#include <SFML/Graphics.hpp>
#include "Plateform.h"

struct Collision {
	bool isOnCollision;
	sf::RectangleShape* rectangleCol;
	sf::CircleShape* circleCol;
	Plateform* plateform;
};