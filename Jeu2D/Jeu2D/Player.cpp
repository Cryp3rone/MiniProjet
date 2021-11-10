#include "Player.h"
#include <SFML/Graphics.hpp>

Player newPlayer()
{
	Player p;
	p.body = sf::CircleShape(100.f);
	p.body.setOrigin(p.body.getRadius(), p.body.getRadius());
	p.health = 100.f;
	return p;
}

void MovePlayer(Player& player, float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player.body.move(sf::Vector2f(0.f, -speed * dt));
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player.body.move(sf::Vector2f(0.f, speed * dt));
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player.body.move(sf::Vector2f(-speed * dt, 0.f));
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player.body.move(sf::Vector2f(speed * dt, 0.f));


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		player.body.move(sf::Vector2f(0.f, -speed * dt));


	if (player.body.getPosition().y + player.body.getRadius() >= groundY)    
	{
		player.body.setPosition(player.body.getPosition().x, groundY - player.body.getRadius());
	}
}

void applyGravity(Player& p, float& dt, sf::Vector2f& velocity)
{
	if (p.body.getPosition().y + p.body.getRadius() < groundY)
	{
		p.body.move(velocity);
		velocity += gravity * dt;
	}
	else
	{
		velocity.y = 0.f;
	}
}