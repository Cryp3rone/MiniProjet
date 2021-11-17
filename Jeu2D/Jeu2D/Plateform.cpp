#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PlateformStr.h"
#include "LevelGenerator.h"

void CreatePlateform(sf::RectangleShape form,int jumpDirection, PlateformType type,int width,int height,World* world) {
	Plateform* plateform = new Plateform;

	plateform->rectangle = form;
	plateform->jumpDirection = jumpDirection;
	plateform->type = type;
	plateform->collision = sf::FloatRect(form.getPosition(),sf::Vector2f(width,height));

	world->plateforms.push_back(plateform);

	// NE PAS OUBLIER A delete
}