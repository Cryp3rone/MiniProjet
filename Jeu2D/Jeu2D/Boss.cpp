#pragma once
#include "Boss.h"
//#include "LevelGenerator.h"

Boss* CreateBoss(World* world) {
	Boss* boss = new Boss;

	sf::CircleShape head = CreateCircleShape(sf::CircleShape(80), sf::Color::Black, sf::Vector2f(900, 200),3,sf::Color::Magenta,world);
	sf::RectangleShape leftarm_01 = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(120, 20)), sf::Color::Black, sf::Vector2f(820.f,405.f), 3, sf::Color::Magenta, false, world);
	sf::RectangleShape leftarm_02 = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(120, 15)), sf::Color::Black, sf::Vector2f(830.f, 410.f), 3, sf::Color::Magenta, false, world); //leftarm_01.setOrigin(sf::Vector2f(head.getPosition().x + head.getRadius(),head.getPosition().y + head.getRadius()));

	sf::RectangleShape rightarm_01 = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(120, 20)), sf::Color::Black, sf::Vector2f(1060.f, 315.f), 3, sf::Color::Magenta, false, world);
	sf::RectangleShape rightarm_02 = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(120, 15)), sf::Color::Black, sf::Vector2f(1150.f, 410.f), 3, sf::Color::Magenta, false, world);

	leftarm_01.rotate(-45);
	leftarm_02.rotate(90);
	rightarm_01.rotate(45);
	rightarm_02.rotate(90);

	boss->head = head;
	boss->leftArm.push_back(leftarm_01);
	boss->leftArm.push_back(leftarm_02);
	boss->rightArm.push_back(rightarm_01);
	boss->rightArm.push_back(rightarm_02);
	
	return boss;
}

void UpdateBoss(Boss* boss) {
	

}

void RefreshBoss(Boss* boss,sf::RenderWindow& window) {
	window.draw(boss->head);
	
	for (sf::RectangleShape rectangle : boss->rightArm) 
		window.draw(rectangle);
	for (sf::RectangleShape rectangle : boss->leftArm) {
		window.draw(rectangle);
	}

}
