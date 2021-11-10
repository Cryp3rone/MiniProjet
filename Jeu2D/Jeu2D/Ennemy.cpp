#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"

void CreateEnnemies(World* world) {
	// Création des ennemis ici
	CreateCEnnemy(world, CreateCircleShape(new sf::CircleShape(15, 3), sf::Color::Black, sf::Vector2f(1500, 450), 3, sf::Color::Color(255,204,0), world),
		50, sf::Vector2f(1500, 450),true,sf::Vector2f(1500,450),sf::Vector2f(1700,450));

}

void CreateCEnnemy(World* world, sf::CircleShape* circle, float speed, sf::Vector2f position, bool canMoove, sf::Vector2f min, sf::Vector2f max) {

	Ennemy ennemy = CreateEnnemy(world,speed,position,canMoove,min,max);
	ennemy.circle = circle;
	world->ennemies.push_back(ennemy);

}

void CreateREnnemy(World* world, sf::RectangleShape rectangle, float speed, sf::Vector2f position, bool canMoove, sf::Vector2f min, sf::Vector2f max) {

	Ennemy ennemy = CreateEnnemy(world, speed, position, canMoove,min,max);
	ennemy.rectangle = &rectangle;
	world->ennemies.push_back(ennemy);

}

Ennemy CreateEnnemy(World* world, float speed, sf::Vector2f position, bool canMoove,sf::Vector2f min,sf::Vector2f max) {
	Ennemy ennemy;
	ennemy.circle = nullptr;
	ennemy.rectangle = nullptr;
	ennemy.speed = speed;
	ennemy.position = position;
	ennemy.canMoove = canMoove;
	ennemy.min = min;
	ennemy.max = max;
	ennemy.returnBack = false;

	return ennemy;
}

void RefreshEnnemies(World* world, sf::RenderWindow& window) {
	for (Ennemy& ennemy : (*world).ennemies) {
		if (ennemy.circle != nullptr)
			window.draw(*(ennemy).circle);
		else
			window.draw(*(ennemy).rectangle);
	}
	
}

void UpdateEnnemies(World* world, float deltaTime) {
	for (Ennemy& ennemy : world->ennemies) {
		if (ennemy.canMoove) 
			MooveEnnemy(ennemy, deltaTime);
	}
}

void MooveEnnemy(Ennemy& ennemy, float deltaTime) {
	if (ennemy.circle != nullptr) {
		sf::CircleShape& circle = *(ennemy).circle;

		//if (ennemy.min.y == ennemy.min.y) { // On fait un mouvement horizontal{
			std::cout << "posX: " << (int)circle.getPosition().x << " maxX: " << (int)ennemy.max.x << std::endl;
			std::cout << "value: " << ennemy.returnBack << std::endl;

			if ((int)circle.getPosition().x < (int)ennemy.max.x && !ennemy.returnBack) {
				circle.move(sf::Vector2f(ennemy.speed * deltaTime, 0.f));
				ennemy.returnBack = (int)circle.getPosition().x >= (int)ennemy.max.x;
			}
			else if ((int)circle.getPosition().x >= (int)ennemy.min.x && ennemy.returnBack) {
				circle.move(sf::Vector2f(-ennemy.speed * deltaTime, 0.f));
				
				ennemy.returnBack = (int)circle.getPosition().x <= (int)ennemy.min.x;
			}
			
		//}
	}
	else {
		sf::RectangleShape rectangle = *(ennemy).rectangle;
		rectangle.move(sf::Vector2f(ennemy.speed * deltaTime, 0.f));
	}
}