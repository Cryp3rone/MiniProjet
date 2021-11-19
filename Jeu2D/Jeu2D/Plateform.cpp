#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PlateformStr.h"
#include "LevelGenerator.h"
// Faire une map

void CreatePlateform(sf::RectangleShape* form,int jumpDirection, PlateformType type,World* world) {
	Plateform* plateform = new Plateform;

	plateform->rectangle = form;
	plateform->jumpDirection = jumpDirection;
	plateform->type = type;
	world->plateforms[form] = plateform;
	

}
