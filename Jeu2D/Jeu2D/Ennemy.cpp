#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"

void CreateEnnemies(World* world) {
	// Création des ennemis ici
	CreateCEnnemy(world, CreateCircleShape(sf::CircleShape(15, 3), sf::Color::Black, sf::Vector2f(1500, 450), 3, sf::Color::Yellow, world),5, sf::Vector2f(1500, 450),true);

}

void CreateCEnnemy(World* world, sf::CircleShape circle, float speed, sf::Vector2f position, bool canMoove) {

	Ennemy ennemy = CreateEnnemy(world,speed,position,canMoove);
	ennemy.circle = &circle;
	world->ennemies.push_back(ennemy);

}

void CreateREnnemy(World* world, sf::RectangleShape rectangle, float speed, sf::Vector2f position, bool canMoove) {

	Ennemy ennemy = CreateEnnemy(world, speed, position, canMoove);
	ennemy.rectangle = &rectangle;
	world->ennemies.push_back(ennemy);

}

Ennemy CreateEnnemy(World* world, float speed, sf::Vector2f position, bool canMoove) {
	Ennemy ennemy;
	ennemy.circle = nullptr;
	ennemy.rectangle = nullptr;
	ennemy.speed = speed;
	ennemy.position = position;
	ennemy.canMoove = canMoove;

	return ennemy;
}

void RefreshEnnemies(World* world, sf::RenderWindow& window) {
	for (Ennemy ennemy : (*world).ennemies) {
		if (ennemy.circle != nullptr)
			window.draw(*ennemy.circle);
		else
			window.draw(*ennemy.rectangle);
	}
	
}