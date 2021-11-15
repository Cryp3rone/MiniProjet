#pragma once
#include "Player.h"
#include "LevelGenerator.h"
#include "Ennemy.h"


void OnCollisionEnter(Player& player,Collision& collision, bool isEnnemy,bool isBullet,World* world) {
	if (!isEnnemy) {
		player.collision.isOnCollision = true;

		if (player.isJumping) {
			if (collision.circleCol != nullptr) {
				player.mooveX = true;
				world->groundY = collision.circleCol->getPosition().y - 5;
				if (world->groundY <= 0)
					world->groundY = originalGroundY;
			}
			else {
				player.mooveX = true;
				world->groundY = collision.rectangleCol->getPosition().y - 5;
				if (world->groundY <= 0)
					world->groundY = originalGroundY;
			}

			//player.mooveX = true;
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

void OnCollisionStay(Player& player, Collision& collision, bool isEnnemy, bool isBullet, World* world) {
	if (collision.circleCol != nullptr) {
		if (player.body.getGlobalBounds().top <= collision.circleCol->getGlobalBounds().top) { // On check si le joueur est au dessus de la collision
			if (!player.mooveX)
				player.mooveX = true;
		}
	}
	else {
		if (player.body.getGlobalBounds().top <= collision.rectangleCol->getGlobalBounds().top) { // On check si le joueur est au dessus de la collision
			if (!player.mooveX)
				player.mooveX = true;
		}
	}
}


void OnCollisionLeave(Player& player, Collision& collision, World* world) {
	player.collision.isOnCollision = false;
	player.collision.circleCol = nullptr;
	player.collision.rectangleCol = nullptr;

	world->groundY = originalGroundY;
}
