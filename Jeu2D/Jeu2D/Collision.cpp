#pragma once
#include "Player.h"
#include "LevelGenerator.h"
#include "Ennemy.h"


void OnCollisionEnter(Player& player,Collision& collision, bool isEnnemy,bool isBullet,World* world) {
	if (!isEnnemy) {
		player.collision.isOnCollision = true;

		if (player.isJumping) {
			float checkY = collision.circleCol ? collision.circleCol->getPosition().y : collision.rectangleCol->getPosition().y;
			if (player.body.getPosition().y <= checkY) {
				world->groundY = checkY - 5;
				if (world->groundY <= 0)
					world->groundY = originalGroundY;

				player.mooveX = true;
			}
		}
		else 
			player.mooveX = false;	
	}
	else
		player.health = 0;

	if (isBullet) 
		world->eraseEnnemies.push_back(collision.circleCol ? &GetEnnemyWithShape(collision.circleCol, world) : &GetEnnemyWithShape(collision.rectangleCol, world));

	if (player.isJumping) 
		player.isJumping = false;
	
}

void OnCollisionStay(Player& player, Collision& collision, bool isEnnemy, bool isBullet, World* world) {
	float checkY = collision.circleCol ? collision.circleCol->getPosition().y : collision.rectangleCol->getPosition().y;
	sf::FloatRect checkRect = collision.circleCol ? collision.circleCol->getGlobalBounds() : collision.rectangleCol->getGlobalBounds();

	if (player.body.getGlobalBounds().top <= checkRect.top) { // On check si le joueur est au dessus de la collision
		if (!player.mooveX)
			player.mooveX = true;
	}
	else {
		if (world->groundY != checkRect.top && (int)player.body.getPosition().y != (int)checkY)
			player.mooveX = false;
	}

}


void OnCollisionLeave(Player& player, Collision& collision, World* world) {
	player.collision.isOnCollision = false;
	player.collision.circleCol = nullptr;
	player.collision.rectangleCol = nullptr;

	world->groundY = originalGroundY;
}
