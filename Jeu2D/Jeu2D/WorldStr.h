#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

struct World {
	std::vector<Plateform*> plateforms;
	std::list<Ennemy> ennemies;
	std::vector<Ennemy*> eraseEnnemies;
	sf::RectangleShape endFlag;
	float groundY;
	Boss boss;
};