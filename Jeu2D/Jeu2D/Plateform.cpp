#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PlateformStr.h"
#include "LevelGenerator.h"
// Faire une map

void CreatePlateform(sf::RectangleShape form,int jumpDirection, PlateformType type,int width,int height,World* world) {
	Plateform* plateform = new Plateform;

	plateform->rectangle = form;
	plateform->jumpDirection = jumpDirection;
	plateform->type = type;
	plateform->collision = sf::FloatRect(sf::Vector2f(form.getPosition().x,form.getPosition().y),sf::Vector2f(width,height));
	//plateform->collision.intersects();
	world->plateforms.push_back(plateform);

	// NE PAS OUBLIER A delete
}