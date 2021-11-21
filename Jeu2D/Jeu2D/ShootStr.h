#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum BulletType {
	PLAYER,
	BOSS
};

struct Bullet {
	sf::Vector2f currVelocity;
	sf::CircleShape body;
	int timer = 0;
	BulletType type;
};