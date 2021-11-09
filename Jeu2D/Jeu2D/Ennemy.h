#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "EnnemyStr.h"

void CreateCircleEnnemy(World world,sf::CircleShape shape, float speed,sf::Vector2f position,bool canMoove);
//void CreateRectangleEnnemy(Level* level, sf::RectangleShape shape, float speed, sf::Vector2f position, bool canMoove);

void UpdateEnnemy(Ennemy& ennemy);

void MooveEnnemy();
	
void RefreshEnnemy(Ennemy& ennemy, sf::RenderWindow& window);