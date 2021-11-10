#pragma once
#include <SFML/Graphics.hpp>

const float groundY = 400.f;
const float speed = 400.f;
const float jumpForce = 400.f;
const sf::Vector2f gravity(0.f, 0.2f);

struct Player
{
	sf::CircleShape body;
	float health;
};

Player newPlayer();

void MovePlayer(Player&, float&, sf::Vector2f&);

bool isGrounded(Player&);