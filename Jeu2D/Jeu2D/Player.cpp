#include "Player.h"
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Collision.h"

Player newPlayer()
{
	Player p;
	p.body = sf::CircleShape(20.f);
	p.body.setFillColor(sf::Color::Red);
	p.body.setOrigin(p.body.getPosition().x + p.body.getRadius(), p.body.getPosition().y + p.body.getRadius());
	p.collision = sf::FloatRect(p.body.getPosition().x, p.body.getPosition().y,p.body.getPosition().x + p.body.getScale().x,p.body.getPosition().y + p.body.getScale().y);
	p.health = 100.f;
	return p;
}

void MovePlayer(Player& player, float dt, sf::Vector2f& velocity, sf::View& view,World* world)
{
	// MOVEMENT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player.body.move(sf::Vector2f(0.f, -speed * dt));
		view.move(sf::Vector2f(0.f, -speed * dt));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player.body.move(sf::Vector2f(0.f, speed * dt));
		view.move(sf::Vector2f(0.f, speed * dt));
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player.direction = sf::Vector2f(-1.f, 0.f);

		if (player.direction.x != player.lastDirection.x || (player.direction.x == player.lastDirection.x && player.mooveX)) { // On regarde si le joueur change de direction ou si il est dans la même direction et qu'il peut se déplacer
			player.body.move(sf::Vector2f(-speed * dt, 0.f));
			view.move(sf::Vector2f(-speed * dt, 0.f));
			
			if (player.direction.x != player.lastDirection.x) {
				player.mooveX = true;
				player.lastDirection = player.direction;
			}
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player.direction = sf::Vector2f(1.f, 0.f);

		if (player.direction.x != player.lastDirection.x || (player.direction.x == player.lastDirection.x && player.mooveX))  { // On regarde si le joueur change de direction ou si il est dans la même direction et qu'il peut se déplacer
			player.body.move(sf::Vector2f(speed * dt, 0.f));
			view.move(sf::Vector2f(speed * dt, 0.f));
			
			if (player.direction.x != player.lastDirection.x) {
				player.mooveX = true;
				player.lastDirection = player.direction;
			}
		}
	}


	// JUMP

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


	// COLLISION
	for (sf::RectangleShape rectangle : world->rectangles) {
		if (rectangle.getGlobalBounds().intersects(player.body.getGlobalBounds())) 
			OnCollision(player, rectangle, false);

		for (Ennemy ennemy : world->ennemies) {
			if (ennemy.circle != nullptr) {
				if (ennemy.circle->getGlobalBounds().intersects(player.body.getGlobalBounds()))
					OnCollision(player, *(ennemy).circle, true);
			}
			else {
				if (ennemy.rectangle->getGlobalBounds().intersects(player.body.getGlobalBounds()))
					OnCollision(player, *(ennemy).rectangle, true);
			}
		}
	}

}

bool isGrounded(Player& p)
{
	return (p.body.getPosition().y + p.body.getRadius() >= groundY);
}