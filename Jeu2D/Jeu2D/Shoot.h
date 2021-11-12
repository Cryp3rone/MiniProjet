#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <List>
#include "Player.h"

const float bulletSpeed = 400.f;

struct Bullet 
{
	sf::Vector2f currVelocity;
	sf::CircleShape body;
};

void Shoot(sf::Vector2f, sf::Vector2f, std::list<Bullet>&, float&);