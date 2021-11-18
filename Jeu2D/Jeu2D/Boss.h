#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "LevelGenerator.h"

void CreateBoss(World*);
void UpdateBoss(Boss*,Player&,float);
void RefreshBoss(Boss*,sf::RenderWindow&);
void RotateArms(Boss*, float,float,float,bool,std::vector<sf::RectangleShape>&);