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
	p.body.setFillColor(sf::Color::Black);
	p.body.setOrigin(p.body.getRadius(), p.body.getRadius());
	p.body.setOutlineThickness(3.f);
	p.body.setOutlineColor(sf::Color::Red);

	p.health = 100.f;

	Collision coll;
	coll.isOnCollision = false;
	coll.rectangleCol = nullptr;
	coll.circleCol = nullptr;
	p.collision = coll;
	p.isJumping = false;

	p.maxAmmo = 3;
	p.ammo = p.maxAmmo;

	return p;
}

void UpdatePlayer(Player& player, float dt, sf::Vector2f& velocity, sf::View& view,World* world, std::list<Bullet> bullets,GameState& state) {
	MovePlayer(player, dt, view);
	JumpPlayer(player,dt,velocity,world);
	OnCollisionDetection(player, world,bullets,state);
	DestroyEnnemies(world);
}

void MovePlayer(Player& player, float dt, sf::View& view) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		player.direction = sf::Vector2f(-1.f, 0.f);

		if (player.direction.x != player.lastDirection.x || (player.direction.x == player.lastDirection.x && player.mooveX)) { // On regarde si le joueur change de direction ou si il est dans la m�me direction et qu'il peut se d�placer
			if (-speed * dt + player.body.getPosition().x >= 5.f) // On place une bordure a 5 pour empecher le joueur d'aller au dela du niveau
				player.body.move(sf::Vector2f(-speed * dt, 0.f));
			
			if ((-speed * dt) + view.getCenter().x >= 600.f)
				view.move(sf::Vector2f(-speed * dt, 0.f));

			if (player.direction.x != player.lastDirection.x) {
				player.mooveX = true;
				player.lastDirection = player.direction;
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.direction = sf::Vector2f(1.f, 0.f);

		if (player.direction.x != player.lastDirection.x || (player.direction.x == player.lastDirection.x && player.mooveX)) { // On regarde si le joueur change de direction ou si il est dans la m�me direction et qu'il peut se d�placer
			player.body.move(sf::Vector2f(speed * dt, 0.f));
			if ((-speed * dt) + player.body.getPosition().x >= 600.f)
				view.move(sf::Vector2f(speed * dt, 0.f));

			if (player.direction.x != player.lastDirection.x) {
				player.mooveX = true;
				player.lastDirection = player.direction;
			}
		}
	}
}

void JumpPlayer(Player& player,float dt, sf::Vector2f& velocity,World* world) {
	if (player.canJump) {
		if (isGrounded(player, world)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (velocity.x != 0)
					velocity.x = 0;

				velocity.y = jumpForce;
				player.body.move(velocity);
				player.isJumping = true;
			}


		}
		else {
			player.body.move(velocity);
			velocity += gravity * dt;
		}

		if (isGrounded(player, world) && player.isJumping)
			player.body.setPosition(player.body.getPosition().x, (*world).groundY - player.body.getRadius());

		if (isOnFloor(player)) {
			if (player.isJumping)
				player.isJumping = false;
		}
	}
}

bool isGrounded(Player& p,World* world) {
	return (p.body.getPosition().y + p.body.getRadius() >= (*world).groundY);
}

bool isOnFloor(Player& p) {
	return p.body.getPosition().y + p.body.getRadius() == originalGroundY;
}

bool CanStopJump(Player& player) {
	return player.isJumping && player.collision.isOnCollision/* && player.collision.plateform && player.collision.plateform->type == WALL_JUMP*/;
}

bool CanWallJump(Player& player) {
	return !player.canJump && player.isJumping && player.collision.isOnCollision /*&& player.collision.plateform && player.collision.plateform->type == WALL_JUMP*/;
}
