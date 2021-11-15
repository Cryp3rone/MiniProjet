#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "EnnemyStr.h"
#include "PlateformStr.h"

struct World {
	std::vector<Plateform*> plateforms;
	std::list<Ennemy> ennemies;
	std::vector<Ennemy*> eraseEnnemies;
	sf::RectangleShape endFlag;
	float groundY;
};

World* GenerateLevel();
sf::CircleShape CreateCircleShape(sf::CircleShape shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor, World* level);
sf::RectangleShape CreateRectangleShape(sf::RectangleShape shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor,bool, World* level);

void RefreshWorld(World* level,sf::RenderWindow& window);