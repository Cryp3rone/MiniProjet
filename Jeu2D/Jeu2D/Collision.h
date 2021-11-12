#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"
#include "PlayerStr.h"
#include "CollisionStr.h"

void OnCollisionEnter(Player&,Collision&,bool,World* );
void OnCollisionLeave(Player&,Collision&,World* );
void CreateCollision(Player&,sf::RectangleShape*,sf::CircleShape*);