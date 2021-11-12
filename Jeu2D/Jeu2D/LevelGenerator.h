#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "EnnemyStr.h"

struct World {
	std::vector<sf::RectangleShape> rectangles;
	std::vector<Ennemy> ennemies;
	float groundY;
};

World* GenerateLevel();
sf::CircleShape* CreateCircleShape(sf::CircleShape* shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor, World* level);
void CreateRectangleShape(sf::RectangleShape shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor, World* level);

void RefreshWorld(World* level,sf::RenderWindow& window);