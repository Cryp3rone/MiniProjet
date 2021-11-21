#include <iostream>
#include <SFML/Graphics.hpp>
#include <List>
#include "Player.h"
#include "Shoot.h"

void Shoot(Player& player, sf::Vector2f mousePos, std::list<Bullet>& bullets,BulletType type, float& dt) {
	if (player.ammo > 0) {
		sf::Vector2f dir = mousePos - player.body.getPosition();
		sf::Vector2f dirNorm = dir / (float)sqrt(pow(dir.x, 2) + pow(dir.y, 2));

		Bullet bullet;
		bullet.body = sf::CircleShape(8.f);
		bullet.body.setFillColor(sf::Color::Black);
		bullet.body.setOutlineThickness(3);
		bullet.body.setOutlineColor(sf::Color::Green);
		bullet.body.setFillColor(sf::Color::Black);
		bullet.body.setPosition(player.body.getPosition());
		bullet.type = type;
		bullet.currVelocity = dirNorm * bulletSpeed * dt;
		bullets.push_back(bullet);

		player.ammo--;
	}
}

void Shoot(sf::Vector2f position,sf::Vector2f dir, std::list<Bullet>& bullets, BulletType type, float& dt) {
	sf::Vector2f dirNorm = dir / (float)sqrt(pow(dir.x, 2) + pow(dir.y, 2));
	Bullet bullet;
	bullet.body = sf::CircleShape(8.f);
	bullet.body.setFillColor(sf::Color::Black);
	bullet.body.setOutlineThickness(3);
	bullet.body.setOutlineColor(sf::Color::Green);
	bullet.body.setFillColor(sf::Color::Black);
	bullet.type = type;
	position.x -= 100;
	bullet.body.setPosition(position);
	bullet.currVelocity = dirNorm * bulletSpeed * dt;
	bullets.push_back(bullet);

	
}

void updateBullet(std::list<Bullet>& bullets, sf::View& camera) {
	auto it = bullets.begin();
	while (it != bullets.end()) {
		if ((*it).body.getPosition().x < camera.getCenter().x - camera.getSize().x ||
			(*it).body.getPosition().x > camera.getCenter().x + camera.getSize().x ||
			(*it).body.getPosition().y < camera.getCenter().y - camera.getSize().y ||
			(*it).body.getPosition().y > camera.getCenter().y + camera.getSize().y ) {
			it = bullets.erase(it);
		}
		else{
			it++;
		}
	}
}
