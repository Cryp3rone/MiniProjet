#pragma once
#include "Player.h"
#include "LevelGenerator.h"
#include "Ennemy.h"
#include "PlateformStr.h"
#include "Collision.h"

Plateform* GetPlateformByShape(sf::RectangleShape compare,World* world) {
	for (Plateform* plateformPtr : world->plateforms) {
		if (plateformPtr->rectangle.getPosition().x == compare.getPosition().x && plateformPtr->rectangle.getPosition().y == compare.getPosition().y) 
			return plateformPtr;	
	}

	return nullptr;
}

void CreateCollision(Player& player, sf::RectangleShape* rectangleCol, sf::CircleShape* circleCol,World* world) {
	Collision coll;
	coll.rectangleCol = rectangleCol;
	coll.circleCol = circleCol;
	coll.isOnCollision = true;
	coll.plateform = nullptr;

	if (coll.rectangleCol != nullptr) {
		if (GetPlateformByShape(*coll.rectangleCol, world)) 
			coll.plateform = GetPlateformByShape(*coll.rectangleCol, world);	
	}

	player.collision = coll;
}

void OnCollisionDetection(Player& player, World* world, std::list<Bullet>& bullets, GameState& state) {
	//if (world->endFlag.getGlobalBounds().intersects(player.body.getGlobalBounds()))
		//state = WIN;

	for (Plateform* plateform : world->plateforms) {
		sf::RectangleShape& rectangle = plateform->rectangle;
		if (rectangle.getOutlineColor() != sf::Color::Blue) { // On skip la collision du bas
			if (rectangle.getGlobalBounds().intersects(player.body.getGlobalBounds())) {
				if (!player.collision.isOnCollision) {
					CreateCollision(player, &rectangle, nullptr,world);
					OnCollisionEnter(player, player.collision, false, false, world);
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
					CreateCollision(player, !ennemy.circle ? nullptr : ennemy.rectangle, ennemy.circle ? ennemy.circle : nullptr,world); // Modifier 
					OnCollisionEnter(player, player.collision, false, true, world);
				}
				OnCollisionStay(player, player.collision, false, true, world);
			}
			else {
				if (player.collision.isOnCollision) {
					if ((player.collision.circleCol != nullptr && player.collision.circleCol == &bullet.body))
						OnCollisionLeave(player, player.collision, world);
				}
			}
		}

		sf::FloatRect checkRect = ennemy.circle ? ennemy.circle->getGlobalBounds() : ennemy.rectangle->getGlobalBounds();
		if (checkRect.intersects(player.body.getGlobalBounds())) {
			if (!player.collision.isOnCollision) {
				CreateCollision(player, ennemy.circle ? nullptr : ennemy.rectangle, ennemy.circle ? ennemy.circle : nullptr,world); // Modifier 
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

	for (sf::FloatRect& voidCollision : world->voidArea) {
		if (voidCollision.intersects(player.body.getGlobalBounds())) 
			world->groundY = 1000;
	}
}

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

	if (player.isJumping) {
		if (player.collision.rectangleCol) {
			Plateform* plateform = GetPlateformByShape(*player.collision.rectangleCol,world);
			if(plateform->type != WALL_JUMP) // Permet de faire le resaut lors d'un walljump
				player.isJumping = false;
		}
		else
			player.isJumping = false;
	}
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
