#pragma once
#include "EnnemyStr.h"
#include <SFML/Graphics.hpp>


void HorizontalBehaviour(Ennemy& ennemy, sf::Shape* shape,float deltaTime) {
	if (ennemy.min.y == ennemy.min.y) { // On fait un mouvement horizontal{
		if ((int)shape->getPosition().x < (int)ennemy.max.x && !ennemy.returnBack) {
			shape->move(sf::Vector2f(ennemy.speed * deltaTime, 0.f));
			ennemy.returnBack = (int)shape->getPosition().x >= (int)ennemy.max.x;
		}
		else if ((int)shape->getPosition().x >= (int)ennemy.min.x && ennemy.returnBack) {
			shape->move(sf::Vector2f(-ennemy.speed * deltaTime, 0.f));

			if ((int)shape->getPosition().x <= (int)ennemy.min.x)
				ennemy.returnBack = false;
		}

	}
	
}

void VerticalBehaviour(Ennemy& ennemy, sf::Shape* shape, float deltaTime) {
	if (ennemy.min.x == ennemy.min.x) { // On fait un mouvement horizontal{
		if ((int)shape->getPosition().y < (int)ennemy.max.y && !ennemy.returnBack) {
			shape->move(sf::Vector2f(0.f,ennemy.speed * deltaTime));
			ennemy.returnBack = (int)shape->getPosition().y >= (int)ennemy.max.y;
		}
		else if ((int)shape->getPosition().y >= (int)ennemy.min.y && ennemy.returnBack) {
			shape->move(sf::Vector2f(0.f,-ennemy.speed * deltaTime));

			if ((int)shape->getPosition().y <= (int)ennemy.min.y)
				ennemy.returnBack = false;
		}

	}

}