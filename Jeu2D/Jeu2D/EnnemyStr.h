#pragma once
#include <SFML/Graphics.hpp>

struct Ennemy {
	sf::CircleShape* circle;
	sf::RectangleShape* rectangle;
	float speed;
	sf::Vector2f position;
	bool canMoove;
};
