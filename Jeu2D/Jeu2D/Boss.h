#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "LevelGenerator.h"

void CreateBoss(World*);
void UpdateBoss(Boss*);
void RefreshBoss(Boss*,sf::RenderWindow&);