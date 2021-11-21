#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum PlateformType {
	FLOOR,
	NORMAL,
	ENNEMI,
	WALL_JUMP
};

struct Plateform {
	sf::RectangleShape rectangle;
	int jumpDirection;
	PlateformType type;
};