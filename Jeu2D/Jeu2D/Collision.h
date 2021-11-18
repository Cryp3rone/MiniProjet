#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"
#include "PlayerStr.h"
#include "CollisionStr.h"

void OnCollisionDetection(Player&, World*,std::list<Bullet>&, GameState&);
void OnCollisionEnter(Player&, Collision&, bool, bool,World*);
void OnCollisionStay(Player&, Collision&, bool, bool, World*);
void OnCollisionLeave(Player&,Collision&,World* );
void CreateCollision(Player&,sf::RectangleShape*,sf::CircleShape*,World*);

void DestroyBullets(std::vector<Bullet*>&,std::list<Bullet>&);

Plateform* GetPlateformByShape(sf::RectangleShape, World*);