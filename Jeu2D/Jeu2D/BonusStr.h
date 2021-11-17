#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum enumBonus {
	AMMO,
	SPEED,
	JUMP
};

struct Bonus
{
	enumBonus type;
	sf::CircleShape body;
	float effect;
};