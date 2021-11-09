#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "EnnemyStr.h"

void CreateEnnemies(World* world);
void CreateCEnnemy(World* world,sf::CircleShape shape, float speed,sf::Vector2f position,bool canMoove);
void CreateREnnemy(World* world, sf::RectangleShape shape, float speed, sf::Vector2f position, bool canMoove);
Ennemy CreateEnnemy(World* world, float speed, sf::Vector2f position, bool canMoove);

void UpdateEnnemies(World* world);

void MooveEnnemy();
	
void RefreshEnnemies(World* world, sf::RenderWindow& window);