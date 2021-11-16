#pragma once

#include <SFML/Graphics.hpp>
#include "CollisionStr.h"


struct Player
{
	sf::CircleShape body;
	float health;
	bool mooveX;
	sf::Vector2f direction;
	sf::Vector2f lastDirection;
	bool canJump;
	bool isJumping;
	Collision collision;
	sf::Vector2f velocity;
	int lastJumpDirection;
	sf::Vector2f lastPosition;
};