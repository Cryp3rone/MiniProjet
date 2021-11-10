#pragma once
#include <SFML/Graphics.hpp>


struct Ennemy {
	sf::CircleShape* circle;
	sf::RectangleShape* rectangle;
	float speed;
	sf::Vector2f position;
	bool canMoove;
	sf::Vector2f max;
	sf::Vector2f min;
	bool returnBack;
	sf::FloatRect collision;
};
