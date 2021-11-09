#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"

void CreateCircleEnnemy(World* level, sf::CircleShape circle, float speed, sf::Vector2f position, bool canMoove) {

	Ennemy* ennemy = new Ennemy;

	ennemy->circle = nullptr;
	ennemy->rectangle = nullptr;
	ennemy->speed = speed;
	ennemy->position = position;
	ennemy->canMoove = canMoove;

	level->ennemies.push_back(ennemy);

}