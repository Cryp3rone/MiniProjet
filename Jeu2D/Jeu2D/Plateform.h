#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum PlateformType {
	NORMAL,
	ENNEMI,
	WALL_JUMP
};

struct Plateform {
	sf::RectangleShape rectangle;
	int jumpDirection;
	PlateformType type;
};

void CreatePlateform(sf::RectangleShape,int, PlateformType,World*);