#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"
#include "EnnemyBehaviour.h"

void CreateEnnemies(World* world) {
	// Création des ennemis ici
	CreateCEnnemy(world, CreateCircleShape(new sf::CircleShape(15, 3), sf::Color::Black, sf::Vector2f(1500, 450), 3, sf::Color::Color(255,204,0), world),
		50, sf::Vector2f(1500, 450),true,sf::Vector2f(1500,450),sf::Vector2f(1700,450),HORIZONTAL);

	CreateCEnnemy(world, CreateCircleShape(new sf::CircleShape(15, 3), sf::Color::Black, sf::Vector2f(650, 300), 3, sf::Color::Color(255, 204, 0), world),
		150, sf::Vector2f(650, 300), true, sf::Vector2f(650, 300), sf::Vector2f(650, 450), VERTICAL);
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
	Ennemy ennemy;
	ennemy.circle = nullptr;
	ennemy.rectangle = nullptr;
	ennemy.speed = speed;
	ennemy.position = position;
	ennemy.canMoove = canMoove;
	ennemy.min = min;
	ennemy.max = max;
	ennemy.returnBack = false;
	ennemy.behaviour = behaviour;

	

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
	switch (ennemy.behaviour) {
		case HORIZONTAL:
			if(ennemy.circle != nullptr)
				HorizontalBehaviour(ennemy, ennemy.circle,deltaTime);
			else
				HorizontalBehaviour(ennemy, ennemy.rectangle, deltaTime);
			break;

		case VERTICAL:
			if (ennemy.circle != nullptr)
				VerticalBehaviour(ennemy, ennemy.circle, deltaTime);
			else
				VerticalBehaviour(ennemy, ennemy.rectangle, deltaTime);
			break;
	}
}