#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"

World* GenerateLevel() {
	World* level = new World;

	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(/*window.getSize().x*/ 3000, 125)),sf::Color::Black,sf::Vector2f(0,475),3,sf::Color::Blue,level);
	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(50, 50)), sf::Color::Black, sf::Vector2f(900, 425), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(50, 100)), sf::Color::Black, sf::Vector2f(1100, 375), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(250, 13)), sf::Color::Black, sf::Vector2f(2000, 375), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(250, 13)), sf::Color::Black, sf::Vector2f(2500, 375), 3, sf::Color::Yellow, level);
	
	return level;
}

void RefreshWorld(World* level,sf::RenderWindow& window) {
	for (sf::RectangleShape rectangle : (*level).rectangles) 
		window.draw(rectangle);
}

void CreateRectangleShape(sf::RectangleShape* shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor, World* level) {
	shape->setPosition(position);
	shape->setFillColor(color);
	shape->setOutlineThickness(thickness);
	shape->setOutlineColor(thicknessColor);
	level->rectangles.push_back(*shape);

	

	//window.draw(shape);
}
void CreateRectangleShape(sf::RectangleShape shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor, World* level) {
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setOutlineThickness(thickness);
	shape.setOutlineColor(thicknessColor);
	level->rectangles.push_back(shape);

	//window.draw(shape);
}


sf::CircleShape* CreateCircleShape(sf::CircleShape* shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor, World* level) {
	shape->setPosition(position);
	shape->setFillColor(color);
	shape->setOutlineThickness(thickness);
	shape->setOutlineColor(thicknessColor);
	return shape;
	//window.draw(shape);
}

