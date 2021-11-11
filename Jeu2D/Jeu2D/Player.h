#pragma once
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"

const float groundY = 400.f;
const float speed = 400.f;
const float jumpForce = -8.f;
const sf::Vector2f gravity(0.f, 9.8f);

struct Player
{
	sf::CircleShape body;
	float health;
	sf::FloatRect collision;
	bool mooveX;
	sf::Vector2f direction;
	sf::Vector2f lastDirection;
};

Player newPlayer();

void MovePlayer(Player&, float, sf::Vector2f&,sf::View& view,World* world);

bool isGrounded(Player&);