#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

struct World {
	std::vector<Plateform*> plateforms;
	std::list<Ennemy> ennemies;
	std::vector<Ennemy*> eraseEnnemies;
	std::vector<sf::FloatRect> voidArea;
	sf::RectangleShape endFlag;
	float groundY;
	Boss boss;
};