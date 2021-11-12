#pragma once
#include "Player.h"
#include "LevelGenerator.h"


void OnCollisionEnter(Player& player,Collision& collision, bool isEnnemy,World* world) {

	std::cout << "jumpValue" << player.isJumping << std::endl;

	if (!isEnnemy) {
		player.collision.isOnCollision = true;
		

		if (player.isJumping) {
			if (collision.circleCol != nullptr)
				world->groundY = collision.circleCol->getPosition().y - 5;
			else
				world->groundY = collision.rectangleCol->getPosition().y - 5;


			player.mooveX = true;
		}
		else {
			player.mooveX = false;
		}
	}


	if (player.isJumping) {
		player.isJumping = false;
	}
	
}


void OnCollisionLeave(Player& player, Collision& collision, World* world) {
	player.collision.isOnCollision = false;
	player.collision.circleCol = nullptr;
	player.collision.rectangleCol = nullptr;
	std::cout << "leave" << std::endl;

	world->groundY = originalGroundY;
}
