#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "EnnemyStr.h"
#include "BossStr.h"
#include "PlayerStr.h"
#include "WorldStr.h"

World* GenerateLevel();
sf::CircleShape CreateCircleShape(sf::CircleShape shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor, World* level);
sf::RectangleShape CreateRectangleShape(sf::RectangleShape shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor,bool, World* level);
sf::RectangleShape* CreateRectangleShape(sf::RectangleShape* shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor, bool, World* level);

void RefreshWorld(World* level,sf::RenderWindow& window);
void ActualizeGroundY(Player&, World*);

void UnloadLevel(World*,Player&);
