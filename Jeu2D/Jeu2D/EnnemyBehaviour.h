#pragma once
#include "EnnemyStr.h"
#include <SFML/Graphics.hpp>

void HorizontalBehaviour(Ennemy& ennemy, sf::Shape* shape,float deltaTime);
void VerticalBehaviour(Ennemy& ennemy, sf::Shape* shape, float deltaTime);