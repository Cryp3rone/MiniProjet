#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Player newPlayer()
{
	Player p;
	p.body = sf::CircleShape(50.f);
	p.body.setOrigin(p.body.getRadius(), p.body.getRadius());
	p.health = 100.f;
	return p;
}

void MovePlayer(Player& player, float& dt, sf::Vector2f& velocity)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player.body.move(sf::Vector2f(0.f, -speed * dt));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player.body.move(sf::Vector2f(0.f, speed * dt));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player.body.move(sf::Vector2f(-speed * dt, 0.f));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player.body.move(sf::Vector2f(speed * dt, 0.f));


	if (isGrounded(player))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			velocity.y = jumpForce;
			player.body.move(velocity);
		}
	}
	else
	{
		player.body.move(velocity);
		velocity += gravity * dt;
	}

	if (isGrounded(player))
	{
		player.body.setPosition(player.body.getPosition().x, groundY - player.body.getRadius());
	}
}

bool isGrounded(Player& p)
{
	return (p.body.getPosition().y + p.body.getRadius() >= groundY);
}