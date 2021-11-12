#pragma once
#include "Player.h"
#include "LevelGenerator.h"
#include "Ennemy.h"


void OnCollisionEnter(Player& player,Collision& collision, bool isEnnemy,bool isBullet,World* world) {
	if (!isEnnemy) {
		player.collision.isOnCollision = true;

		if (player.isJumping) {
			if (collision.circleCol != nullptr)
				world->groundY = collision.circleCol->getPosition().y - 5;
			else
				world->groundY = collision.rectangleCol->getPosition().y - 5;


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
			targetEnnemy.isAlive = false; // A CHANGER : Retirer l'ennemi de la liste des ennemis

		}
		else {
			Ennemy& targetEnnemy = GetEnnemyWithShape(collision.rectangleCol,world);
			targetEnnemy.isAlive = false; // A CHANGER : Retirer l'ennemi de la liste des ennemis
		}

	}

	if (player.isJumping) 
		player.isJumping = false;
	
}


void OnCollisionLeave(Player& player, Collision& collision, World* world) {
	player.collision.isOnCollision = false;
	player.collision.circleCol = nullptr;
	player.collision.rectangleCol = nullptr;
	std::cout << "leave" << std::endl;

	world->groundY = originalGroundY;
}
