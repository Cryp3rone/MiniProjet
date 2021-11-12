#pragma once
#include "Player.h"
#include "LevelGenerator.h"
#include "Ennemy.h"


void OnCollisionEnter(Player& player,Collision& collision, bool isEnnemy,bool isBullet,World* world) {
	if (!isEnnemy) {
		player.collision.isOnCollision = true;

		if (player.isJumping) {
			if (collision.circleCol != nullptr) {
				world->groundY = collision.circleCol->getPosition().y - 5;
				if (world->groundY <= 0)
					world->groundY = originalGroundY;
			}
			else {
				world->groundY = collision.rectangleCol->getPosition().y - 5;
				if (world->groundY <= 0)
					world->groundY = originalGroundY;
			}

			player.mooveX = true;
		}
		else 
			player.mooveX = false;	
	}
	else
		player.health = 0;

	if (isBullet) {
		if (collision.circleCol != nullptr) {
			Ennemy& targetEnnemy = GetEnnemyWithShape(collision.circleCol,world);
			world->eraseEnnemies.push_back(&targetEnnemy);
		}
		else {
			Ennemy& targetEnnemy = GetEnnemyWithShape(collision.rectangleCol,world);
			world->eraseEnnemies.push_back(&targetEnnemy);
		}

	}

	if (player.isJumping) 
		player.isJumping = false;
	
}


void OnCollisionLeave(Player& player, Collision& collision, World* world) {
	player.collision.isOnCollision = false;
	player.collision.circleCol = nullptr;
	player.collision.rectangleCol = nullptr;

	world->groundY = originalGroundY;
}
