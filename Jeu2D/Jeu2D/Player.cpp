#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Collision.h"
#include <list>
#include "GameState.h"

Player newPlayer()
{
	Player p;
	p.body = sf::CircleShape(20.f);
	p.body.setPosition(600.f, originalGroundY - 20);
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

void MovePlayer(Player& player, float dt, sf::Vector2f& velocity, sf::View& view,World* world, std::list<Bullet> bullets,GameState& state)
{
	// MOVEMENT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player.direction = sf::Vector2f(-1.f, 0.f);

		if (player.direction.x != player.lastDirection.x || (player.direction.x == player.lastDirection.x && player.mooveX)) { // On regarde si le joueur change de direction ou si il est dans la m�me direction et qu'il peut se d�placer
			if(-speed * dt + player.body.getPosition().x >= 5.f) // On place une bordure a 5 pour empecher le joueur d'aller au dela du niveau
				player.body.move(sf::Vector2f(-speed * dt, 0.f));
			if((-speed * dt) + view.getCenter().x >= 600.f)
				view.move(sf::Vector2f(-speed * dt, 0.f));

			if (player.direction.x != player.lastDirection.x) {
				player.mooveX = true;
				player.lastDirection = player.direction;
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player.direction = sf::Vector2f(1.f, 0.f);

		if (player.direction.x != player.lastDirection.x || (player.direction.x == player.lastDirection.x && player.mooveX))  { // On regarde si le joueur change de direction ou si il est dans la m�me direction et qu'il peut se d�placer
			player.body.move(sf::Vector2f(speed * dt, 0.f));
			if ((-speed * dt) + player.body.getPosition().x >= 600.f)
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
	if ( world->endFlag.getGlobalBounds().intersects(player.body.getGlobalBounds())) 
		state = WIN;
	
	for (sf::RectangleShape& rectangle : world->rectangles) {
		if (rectangle.getOutlineColor() != sf::Color::Blue) { // On skip la collision du bas
			if (rectangle.getGlobalBounds().intersects(player.body.getGlobalBounds())) {
				if (!player.collision.isOnCollision) {
					CreateCollision(player, &rectangle, nullptr);
					OnCollisionEnter(player, player.collision, false,false, world);
				}
				OnCollisionStay(player, player.collision, false, false, world);
			}
			else {
				if (player.collision.isOnCollision && player.collision.rectangleCol != nullptr && player.collision.rectangleCol == &rectangle)
					OnCollisionLeave(player, player.collision, world);
			}
		}
	}

	for (Ennemy& ennemy : world->ennemies) {
		for (Bullet& bullet : bullets) {
			sf::FloatRect checkRect = ennemy.circle ? ennemy.circle->getGlobalBounds() : ennemy.rectangle->getGlobalBounds();
			if (bullet.body.getGlobalBounds().intersects(checkRect)) {
				if (!player.collision.isOnCollision) {
					CreateCollision(player, ennemy.circle ? nullptr : ennemy.rectangle, ennemy.circle ? ennemy.circle : nullptr); // Modifier 
					OnCollisionEnter(player, player.collision, false, true, world);
				}
				OnCollisionStay(player, player.collision, false, true, world);
			}
			else {
				if (player.collision.isOnCollision) {
					if((player.collision.circleCol != nullptr && player.collision.circleCol == &bullet.body))
						OnCollisionLeave(player, player.collision, world);
				}
			}
		}

		sf::FloatRect checkRect = ennemy.circle ? ennemy.circle->getGlobalBounds() : ennemy.rectangle->getGlobalBounds();
		if (checkRect.intersects(player.body.getGlobalBounds())) {
			if (!player.collision.isOnCollision) {
				CreateCollision(player, ennemy.circle ? nullptr : ennemy.rectangle, ennemy.circle ? ennemy.circle : nullptr); // Modifier 
				OnCollisionEnter(player, player.collision, true, false, world);
			}
			OnCollisionStay(player, player.collision, true, false, world);
		}
		else {
			if (player.collision.isOnCollision) {
				if ((player.collision.circleCol && player.collision.circleCol == ennemy.circle) || (player.collision.rectangleCol && player.collision.rectangleCol == ennemy.rectangle)) 
					OnCollisionLeave(player, player.collision, world);	
			}
		}
	}

	DestroyEnnemies(world);
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
