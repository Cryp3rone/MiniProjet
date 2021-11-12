#include <iostream>
#include <SFML/Graphics.hpp>
#include <List>
#include "Player.h"
#include "Shoot.h"

void Shoot(sf::Vector2f playerPos, sf::Vector2f mousePos, std::list<Bullet>& bullets)
{
	sf::Vector2f dir = mousePos - playerPos;
	sf::Vector2f dirNorm = dir / (float)sqrt(pow(dir.x, 2) + pow(dir.y, 2));

	Bullet bullet;
	bullet.body = sf::CircleShape(8.f);
	bullet.body.setFillColor(sf::Color::Green);
	bullet.body.setPosition(playerPos);
	bullets.push_back(bullet);

	bullet.currVelocity = dirNorm * bulletSpeed;
}
