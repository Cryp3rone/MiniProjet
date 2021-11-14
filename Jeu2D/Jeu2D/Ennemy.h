#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "EnnemyStr.h"

void CreateEnnemies(World* world);
void CreateCEnnemy(World* world,sf::CircleShape* shape, float speed,sf::Vector2f position,bool canMoove, sf::Vector2f min, sf::Vector2f max,_EnnemyBehaviour);
void CreateREnnemy(World* world, sf::RectangleShape shape, float speed, sf::Vector2f position, bool canMoove, sf::Vector2f min, sf::Vector2f max,_EnnemyBehaviour);
Ennemy CreateEnnemy(World* world, float speed, sf::Vector2f position, bool canMoove, sf::Vector2f min, sf::Vector2f max, _EnnemyBehaviour);

void UpdateEnnemies(World* world,float deltaTime);

void MooveEnnemy(Ennemy& ennemy, float deltaTime);
	
void RefreshEnnemies(World* world, sf::RenderWindow& window);

void DestroyEnnemies(World* world);

Ennemy& GetEnnemyWithShape(sf::Shape* shape,World* world);