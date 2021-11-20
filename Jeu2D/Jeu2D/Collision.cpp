#pragma once
#include "Player.h"
#include "LevelGenerator.h"
#include "Ennemy.h"
#include "PlateformStr.h"
#include "Collision.h"

Plateform* GetPlateformByShape(sf::RectangleShape compare,World* world) {
	for (std::pair<sf::RectangleShape*,Plateform*> pair : world->plateforms) {
		if (pair.first == &compare) 
			return pair.second;	
	}

	return nullptr;
}

bool HasCollision(sf::Shape* shapeCollision,Player& player,Collision& collision) {
	for (std::pair<sf::Shape*, Collision*> pair : player.collisions) {
		if (pair.first == shapeCollision) {
			collision = *pair.second;
			return true;
		}
	}

	return false;
}

void CreateCollision(Player& player,Collision& coll, sf::RectangleShape* rectangleCol, sf::CircleShape* circleCol,World* world) {
	
	coll.rectangleCol = rectangleCol;
	coll.circleCol = circleCol;
	coll.isOnCollision = true;
	coll.plateform = nullptr;

	if (coll.rectangleCol) {
		if (GetPlateformByShape(*coll.rectangleCol, world)) 
			coll.plateform = GetPlateformByShape(*coll.rectangleCol, world);	
	}

	if (coll.rectangleCol)
		player.collisions[coll.rectangleCol] = &coll;
	else
		player.collisions[coll.circleCol] = &coll;

}

void OnCollisionDetection(Player& player, World* world, std::list<Bullet>& bullets, GameState& state) {
	if (world->endFlag.getGlobalBounds().intersects(player.body.getGlobalBounds()) && !world->boss)
		state = WIN;

	std::vector<Bullet*> eraseBullets;

	for (std::pair<sf::RectangleShape*, Plateform*> pair : world->plateforms) {
		Plateform* plateform = pair.second;
		sf::RectangleShape& rectangle = plateform->rectangle;
		if (plateform->type != FLOOR) { // On skip la collision du bas
			if (rectangle.getGlobalBounds().intersects(player.body.getGlobalBounds())) { // Il est en collision avec une plateforme
				Collision* coll = new Collision;
				if (!HasCollision(&rectangle,player,*coll)) {
					CreateCollision(player,*coll, &rectangle, nullptr,world);
					OnCollisionEnter(player, *coll, false, false, world);
				}
				else 
					OnCollisionStay(player, *coll, false, false, world);
			}
			else {
				Collision* coll = new Collision;
				if (HasCollision(&rectangle, player, *coll) && coll->isOnCollision && coll->rectangleCol != nullptr && coll->rectangleCol == &rectangle)
					OnCollisionLeave(player, *coll, world);
			}

			for (Bullet& bullet : bullets) {
				if (bullet.body.getGlobalBounds().intersects(plateform->rectangle.getGlobalBounds()))
					eraseBullets.push_back(&bullet);
			}
		}
	}

	for (Ennemy& ennemy : world->ennemies) {
		for (Bullet& bullet : bullets) {
			sf::FloatRect checkRect = ennemy.circle ? ennemy.circle->getGlobalBounds() : ennemy.rectangle->getGlobalBounds();
			if (bullet.body.getGlobalBounds().intersects(checkRect)) {
				Collision* coll = new Collision;
				if ((ennemy.circle && !HasCollision(ennemy.circle, player, *coll)) || (ennemy.rectangle && !HasCollision(ennemy.rectangle,player,*coll))) {
					eraseBullets.push_back(&bullet);
					CreateCollision(player, *coll,!ennemy.circle ? nullptr : ennemy.rectangle, ennemy.circle ? ennemy.circle : nullptr,world); // Modifier 
					OnCollisionEnter(player, *coll, false, true, world);
				}
				else 
					OnCollisionStay(player, *coll, false, true, world);
			}
			else {
				Collision* coll = new Collision;
				if (HasCollision(ennemy.circle,player,*coll) || HasCollision(ennemy.rectangle,player,*coll)) {
					if ((coll->circleCol && coll->circleCol == &bullet.body))
						OnCollisionLeave(player, *coll, world);
				}
			}
		}

		sf::FloatRect checkRect = ennemy.circle ? ennemy.circle->getGlobalBounds() : ennemy.rectangle->getGlobalBounds();
		if (checkRect.intersects(player.body.getGlobalBounds())) {
			Collision* coll = new Collision;
			if ((ennemy.circle && !HasCollision(ennemy.circle, player, *coll)) || (ennemy.rectangle && !HasCollision(ennemy.rectangle, player,*coll))) {
				CreateCollision(player,*coll, !ennemy.circle ? nullptr : ennemy.rectangle, ennemy.circle ? ennemy.circle : nullptr,world); // Modifier 
				OnCollisionEnter(player, *coll, true, false, world);
			}
			else 
				OnCollisionStay(player, *coll, true, false, world);
		}
		else {
			Collision* coll = new Collision;
			if ((HasCollision(ennemy.circle,player,*coll) && coll->circleCol && coll->circleCol == ennemy.circle) || (HasCollision(ennemy.rectangle,player,*coll) && coll->rectangleCol && coll->rectangleCol == ennemy.rectangle))
				OnCollisionLeave(player, *coll, world);
		}
	}

	for (sf::FloatRect& voidCollision : world->voidArea) {
		sf::FloatRect body = player.body.getGlobalBounds();
		if (voidCollision.intersects(player.body.getGlobalBounds())) 
			world->groundY = 1000;
	}

	for (Bullet& bullet : bullets) {
		if (bullet.type == BOSS && bullet.body.getGlobalBounds().intersects(player.body.getGlobalBounds())) 
			player.health -= 100;	

		if (world->boss && bullet.body.getGlobalBounds().intersects(world->boss->weaknessCollision.getGlobalBounds())) {
			if (world->boss->health > 0) {
				world->boss->health -= 1;
				eraseBullets.push_back(&bullet);
				break;
			}
		}
		
		if (bullet.type == PLAYER &&  bullet.body.getGlobalBounds().intersects(world->boss->head.getGlobalBounds()))
			eraseBullets.push_back(&bullet);

		for (sf::RectangleShape& rectangle : world->boss->leftArm) {
			if (bullet.type == PLAYER &&  bullet.body.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
				eraseBullets.push_back(&bullet);
		}
		
		for (sf::RectangleShape& rectangle : world->boss->rightArm) {
			if (bullet.type == PLAYER && bullet.body.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
				eraseBullets.push_back(&bullet);
		}
		
	}

	DestroyBullets(eraseBullets,bullets);
}

void OnCollisionEnter(Player& player,Collision& collision, bool isEnnemy,bool isBullet,World* world) {
	if (!isEnnemy) {
		collision.isOnCollision = true;

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
		if (collision.rectangleCol) {
			Plateform* plateform = GetPlateformByShape(*collision.rectangleCol,world);
			if(plateform && plateform->type != WALL_JUMP) // Permet de faire le resaut lors d'un walljump
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
	collision.isOnCollision = false;

	if (collision.rectangleCol) {
		for (auto it = player.collisions.begin(); it != player.collisions.end();) {
			if ((*it).first == collision.rectangleCol)
				it = player.collisions.erase(it);
			else
				it++;
		}
		
	}
	else {
		for (auto it = player.collisions.begin(); it != player.collisions.end();) {
			if ((*it).first == collision.circleCol)
				it = player.collisions.erase(it);
			else
				it++;
		}

	}
	
	//delete collision.circleCol;
	//delete collision.rectangleCol;

	world->groundY = originalGroundY;
}

void DestroyBullets(std::vector<Bullet*>& eraseBullets, std::list<Bullet>& bullets) {
	for (Bullet* bullet : eraseBullets) {
		std::cout << "size: " << eraseBullets.size() << std::endl;
		auto it = bullets.begin();

		while (it != bullets.end()) {
			if (&(*it) == bullet)
				it = bullets.erase(it);
			else
				it++;
		}
	}

	eraseBullets.clear();
}
