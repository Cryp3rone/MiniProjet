#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Collision.h"

Player newPlayer()
{
	Player p;
	p.body = sf::CircleShape(20.f);
	p.body.setPosition(600.f, originalGroundY);
	p.body.setFillColor(sf::Color::Red);
	p.body.setOrigin(p.body.getRadius(), p.body.getRadius());
	p.health = 100.f;
	Collision coll;
	coll.isOnCollision = false;
	coll.rectangleCol = nullptr;
	coll.circleCol = nullptr;
	p.collision = coll;
	p.isJumping = false;
	return p;
}

void MovePlayer(Player& player, float dt, sf::Vector2f& velocity, sf::View& view,World* world)
{
	// MOVEMENT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player.direction = sf::Vector2f(-1.f, 0.f);

		if (player.direction.x != player.lastDirection.x || (player.direction.x == player.lastDirection.x && player.mooveX)) { // On regarde si le joueur change de direction ou si il est dans la m�me direction et qu'il peut se d�placer
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
		//std::cout << "mooveX: " << player.mooveX << std::endl;

		if (player.direction.x != player.lastDirection.x || (player.direction.x == player.lastDirection.x && player.mooveX))  { // On regarde si le joueur change de direction ou si il est dans la m�me direction et qu'il peut se d�placer
			player.body.move(sf::Vector2f(speed * dt, 0.f));
			view.move(sf::Vector2f(speed * dt, 0.f));

			if (player.direction.x != player.lastDirection.x) {
				player.mooveX = true;
				player.lastDirection = player.direction;
			}
		}
	}


	// JUMP


	if (isGrounded(player,world))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			velocity.y = jumpForce;
			player.body.move(velocity);
			player.isJumping = true;
			player.mooveX = true;
		}

	}
	else
	{
		player.body.move(velocity);
		velocity += gravity * dt;	
	}

	if (isGrounded(player,world) && player.isJumping) {
		player.body.setPosition(player.body.getPosition().x, (*world).groundY - player.body.getRadius());
	}

	if (isOnFloor(player)) {
		if (player.isJumping)
			player.isJumping = false;
	}


	// COLLISION
	for (sf::RectangleShape& rectangle : world->rectangles) {
		if (rectangle.getOutlineColor() != sf::Color::Blue) { // On skip la collision du bas
			if (rectangle.getGlobalBounds().intersects(player.body.getGlobalBounds())) {
				if (!player.collision.isOnCollision) {
					CreateCollision(player, &rectangle, nullptr);
					OnCollisionEnter(player, player.collision, false, world);
				}
			}
			else {
				if (player.collision.isOnCollision && player.collision.rectangleCol != nullptr && player.collision.rectangleCol == &rectangle)
					OnCollisionLeave(player, player.collision, world);
			}
		}
	}

	for (Ennemy ennemy : world->ennemies) {
		if (ennemy.circle != nullptr) {
			if (ennemy.circle->getGlobalBounds().intersects(player.body.getGlobalBounds())) {
				if (!player.collision.isOnCollision) {
					CreateCollision(player, nullptr, ennemy.circle);
					OnCollisionEnter(player, player.collision, true, world);
				}
			}
			else {
				if (player.collision.isOnCollision && player.collision.circleCol != nullptr && player.collision.circleCol == ennemy.circle) 
					OnCollisionLeave(player, player.collision, world);
			}


		}
		else {
			if (ennemy.rectangle->getGlobalBounds().intersects(player.body.getGlobalBounds())) {
				if (!player.collision.isOnCollision) {
					CreateCollision(player, ennemy.rectangle, nullptr);
					OnCollisionEnter(player, player.collision, true, world);
				}
			}
			else {
				if (player.collision.isOnCollision && player.collision.rectangleCol != nullptr && player.collision.rectangleCol == ennemy.rectangle) 
					OnCollisionLeave(player, player.collision, world);
			}
		}
	}
	

}

bool isGrounded(Player& p,World* world)
{
	return (p.body.getPosition().y + p.body.getRadius() >= (*world).groundY);
}

bool isOnFloor(Player& p) {
	return p.body.getPosition().y + p.body.getRadius() == originalGroundY;
}

void CreateCollision(Player& player,sf::RectangleShape* rectangleCol, sf::CircleShape* circleCol) {
	Collision coll;
	coll.rectangleCol = rectangleCol;
	coll.circleCol = circleCol;
	coll.isOnCollision = true;
	player.collision = coll;
}