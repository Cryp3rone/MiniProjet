#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "Player.h"
#include "ShootStr.h"

const float bulletSpeed = 700.f;


void Shoot(Player&, sf::Vector2f, std::list<Bullet>&,BulletType, float&);
void Shoot(sf::Vector2f,sf::Vector2f, std::list<Bullet>&, BulletType, float&);

void updateBullet(std::list<Bullet>&, sf::View&);