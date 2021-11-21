#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "Bonus.h"

struct World {
	std::map<sf::RectangleShape*,Plateform*> plateforms;
	std::list<Ennemy> ennemies;
	std::list<Bonus> listBonus;
	std::vector<Ennemy*> eraseEnnemies;
	std::vector<sf::FloatRect> voidArea;
	sf::RectangleShape endFlag;
	float groundY;
	Boss* boss;
};