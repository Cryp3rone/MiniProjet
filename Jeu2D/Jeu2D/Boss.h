#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "LevelGenerator.h"
#include "ShootStr.h"
#include <list>

void CreateBoss(World*,int);
void UpdateBoss(World*,Boss*,Player&, std::list<Bullet>&, float);
void RefreshBoss(Boss*,sf::RenderWindow&,sf::View&);
void RotateArms(Boss*, float,float,float,bool,std::vector<sf::RectangleShape>&);

void DestroyBoss(World* world);