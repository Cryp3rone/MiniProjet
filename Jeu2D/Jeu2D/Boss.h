#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "LevelGenerator.h"

struct Boss {
	sf::CircleShape head;
	std::vector<sf::RectangleShape> rightArm;
	std::vector<sf::RectangleShape> leftArm;
	int health;
	int damage; 
};

Boss* CreateBoss(World*);
void UpdateBoss(Boss*);
void RefreshBoss(Boss*,sf::RenderWindow&);