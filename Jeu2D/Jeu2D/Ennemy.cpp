#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"
#include "EnnemyBehaviour.h"

void CreateEnnemies(World* world) {
	// Création des ennemis ici
//	CreateCEnnemy(world, CreateCircleShape(new sf::CircleShape(15, 3), sf::Color::Black, sf::Vector2f(1500, 450), 3, sf::Color::Color(255,204,0), world),
	//	50, sf::Vector2f(1500, 450),true,sf::Vector2f(1500,450),sf::Vector2f(1700,450),HORIZONTAL);

//	CreateCEnnemy(world, CreateCircleShape(new sf::CircleShape(15, 3), sf::Color::Black, sf::Vector2f(650, 300), 3, sf::Color::Color(255, 204, 0), world),
	//	150, sf::Vector2f(650, 300), true, sf::Vector2f(650, 300), sf::Vector2f(650, 450), VERTICAL);
}

void CreateCEnnemy(World* world, sf::CircleShape* circle, float speed, sf::Vector2f position, bool canMoove, sf::Vector2f min, sf::Vector2f max, _EnnemyBehaviour behaviour) {

	Ennemy ennemy = CreateEnnemy(world,speed,position,canMoove,min,max,behaviour);
	ennemy.circle = circle;
	world->ennemies.push_back(ennemy);

}

void CreateREnnemy(World* world, sf::RectangleShape rectangle, float speed, sf::Vector2f position, bool canMoove, sf::Vector2f min, sf::Vector2f max, _EnnemyBehaviour behaviour) {

	Ennemy ennemy = CreateEnnemy(world, speed, position, canMoove,min,max,behaviour);
	ennemy.rectangle = &rectangle;
	world->ennemies.push_back(ennemy);

}

Ennemy CreateEnnemy(World* world, float speed, sf::Vector2f position, bool canMoove,sf::Vector2f min,sf::Vector2f max, _EnnemyBehaviour behaviour) {
	return {nullptr,nullptr,speed,position,canMoove,min,max,false,behaviour};
}

void RefreshEnnemies(World* world, sf::RenderWindow& window) {
	for (Ennemy& ennemy : (*world).ennemies) {
		if (ennemy.circle)
			window.draw(*ennemy.circle);
		else
			window.draw(*ennemy.rectangle);
	}
}

void UpdateEnnemies(World* world, float deltaTime) {
	for (Ennemy& ennemy : world->ennemies) {
		if (ennemy.canMoove) 
			MooveEnnemy(ennemy, deltaTime);
	}
}

void MooveEnnemy(Ennemy& ennemy, float deltaTime) {
	switch (ennemy.behaviour) {
		case HORIZONTAL:
			if(ennemy.circle)
				HorizontalBehaviour(ennemy,ennemy.circle,deltaTime);
			else
				HorizontalBehaviour(ennemy, ennemy.rectangle, deltaTime);
			break;

		case VERTICAL:
			if (ennemy.circle)
				VerticalBehaviour(ennemy, ennemy.circle, deltaTime);
			else
				VerticalBehaviour(ennemy, ennemy.rectangle, deltaTime);
			break;
	}
}


Ennemy& GetEnnemyWithShape(sf::Shape* shape,World* world) {
	for (Ennemy& ennemy : world->ennemies) {
		sf::Vector2f checkPos = ennemy.circle != nullptr ? ennemy.circle->getPosition() : ennemy.rectangle->getPosition();
		if (checkPos.x == shape->getPosition().x && checkPos.y == shape->getPosition().y)
			return ennemy;
	}

}

void DestroyEnnemies(World* world) {
	for (Ennemy* ennemy : world->eraseEnnemies) {
		auto it = world->ennemies.begin();

		while (it != world->ennemies.end()) {
			if (&(*it) == ennemy) 
				it = world->ennemies.erase(it);	
			else 
				it++;
		}
	}

	world->eraseEnnemies.clear();
}