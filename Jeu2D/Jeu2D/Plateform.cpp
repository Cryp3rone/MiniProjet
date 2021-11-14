#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Plateform.h"
#include "LevelGenerator.h"

void CreatePlateform(sf::RectangleShape form,int jumpDirection, PlateformType type,World* world) {
	Plateform plateform {form,jumpDirection,type};

	world->plateforms.push_back(&plateform);
}