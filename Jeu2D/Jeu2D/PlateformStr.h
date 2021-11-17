#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum PlateformType {
	NORMAL,
	FLOOR,
	ENNEMI,
	WALL_JUMP
};

struct Plateform {
	sf::RectangleShape rectangle;
	int jumpDirection;
	PlateformType type;
	sf::FloatRect collision;
};