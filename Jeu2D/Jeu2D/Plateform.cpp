#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PlateformStr.h"
#include "LevelGenerator.h"
// Faire une map

void CreatePlateform(sf::RectangleShape form,int jumpDirection, PlateformType type,int x,int y,int width,int height,World* world) {
	Plateform* plateform = new Plateform;

	plateform->rectangle = form;
	plateform->jumpDirection = jumpDirection;
	plateform->type = type;
	//plateform->collision = sf::FloatRect(sf::Vector2f(x,y),sf::Vector2f(width,height));
	world->plateforms.push_back(plateform);

	if(type == WALL_JUMP)
		std::cout << &plateform->rectangle << std::endl;
	
	// NE PAS OUBLIER A delete
}