#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"

/*void CreateEnnemy(std::vector<Ennemy*>& ennemiesList,sf::RectangleShape& rectangle, float speed, sf::Vector2f position, bool canMoove) {
	//CreateShape(rect)
	Ennemy* ennemy = new Ennemy;
	ennemy->circle = nullptr;
	ennemy->rectangle = CreateRectangleShape();
	ennemy->speed = speed;
	ennemy->position = position;
	ennemy->canMoove = canMoove;

	ennemiesList.push_back(ennemy);

}

void CreateEnnemy(std::vector<Ennemy*>& ennemiesList, sf::CircleShape& circle, float speed, sf::Vector2f position, bool canMoove) {

	Ennemy* ennemy = new Ennemy;
	ennemy->circle = &circle;
	ennemy->rectangle = nullptr;
	ennemy->speed = speed;
	ennemy->position = position;
	ennemy->canMoove = canMoove;

	ennemiesList.push_back(ennemy);

}

*/