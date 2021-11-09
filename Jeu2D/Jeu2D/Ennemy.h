#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

struct Ennemy {
	sf::CircleShape* circle;
	sf::RectangleShape* rectangle;
	float speed;
	sf::Vector2f position;
	bool canMoove;
};

void CreateEnnemy(std::vector<Ennemy>& ennemiesList,sf::RectangleShape shape, float speed,sf::Vector2f position,bool canMoove);
void CreateEnnemy(std::vector<Ennemy>& ennemiesList, sf::CircleShape shape, float speed, sf::Vector2f position, bool canMoove);

void UpdateEnnemy(Ennemy& ennemy);

void MooveEnnemy();

void RefreshEnnemy(Ennemy& ennemy, sf::RenderWindow& window);