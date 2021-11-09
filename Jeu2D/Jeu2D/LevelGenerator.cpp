#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"

void CreateRectangleShape(sf::RectangleShape shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor, Level* level) {
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setOutlineThickness(thickness);
	shape.setOutlineColor(thicknessColor);
	level->rectangles.push_back(shape);

	//window.draw(shape);
}


Level* GenerateLevel() {
	Level* level = new Level;

	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(/*window.getSize().x*/ 3000, 125)),sf::Color::Black,sf::Vector2f(0,475),3,sf::Color::Blue,level);
	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(50, 50)), sf::Color::Black, sf::Vector2f(900, 425), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(50, 100)), sf::Color::Black, sf::Vector2f(1100, 375), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(250, 13)), sf::Color::Black, sf::Vector2f(2000, 375), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(250, 13)), sf::Color::Black, sf::Vector2f(2500, 375), 3, sf::Color::Yellow, level);

	//sf::CircleShape enn_01(15, 3);
	
	//CreateShape(enn_01, sf::Color::Black, sf::Vector2f(1500, 450), 3, sf::Color::Color(255,153,0), window);

	// Création des ennemis ici

	return level;
}

void UpdateLevel(sf::RenderWindow& window,Level* level) {
	for (sf::RectangleShape rectangle : (*level).rectangles) 
		window.draw(rectangle);
}
