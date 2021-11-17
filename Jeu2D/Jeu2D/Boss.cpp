#pragma once
#include "Boss.h"
#include <cmath>

void CreateBoss(World* world) {
	Boss* boss = new Boss;

/*	sf::CircleShape head = CreateCircleShape(sf::CircleShape(80), sf::Color::Black, sf::Vector2f(900, 200),3,sf::Color::Magenta,world);
	sf::RectangleShape leftarm_01 = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(120, 20)), sf::Color::Black, sf::Vector2f(900.f,200.f), 3, sf::Color::Magenta, false, world);
	
	sf::RectangleShape leftarm_02 = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(120, 15)), sf::Color::Black, sf::Vector2f(830.f, 410.f), 3, sf::Color::Magenta, false, world); //leftarm_01.setOrigin(sf::Vector2f(head.getPosition().x + head.getRadius(),head.getPosition().y + head.getRadius()));

	sf::RectangleShape rightarm_01 = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(120, 20)), sf::Color::Black, sf::Vector2f(1060.f, 315.f), 3, sf::Color::Magenta, false, world);
	sf::RectangleShape rightarm_02 = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(120, 15)), sf::Color::Black, sf::Vector2f(1150.f, 410.f), 3, sf::Color::Magenta, false, world);
	

	bool back = true;
	for (int i = 11;i < 20;i++) {
		sf::Vertex vertex(head.getPosition() + head.getPoint(i));
		vertex.color = sf::Color::Yellow;
		boss->weaknessArea.push_back(vertex);
		if (i != 11 && i != 19) {
			if (back)
				i--;

			back = !back;
		}
	}

	leftarm_01.setOrigin(-head.getRadius() ,leftarm_01.getSize().y / 2.f); // Je centre son origine au centre du rectangle
	leftarm_01.rotate(130);
	head.setOrigin(40, 40);
	leftarm_01.setPosition(head.getPosition().x + head.getOrigin().x, head.getPosition().y + head.getOrigin().y);

	leftarm_02.setOrigin(-head.getRadius(), leftarm_02.getSize().y / 2.f); // Je centre son origine au centre du rectangle
	leftarm_02.rotate(90);
	head.setOrigin(40, 40);
	leftarm_02.setPosition(head.getPosition().x + head.getOrigin().x - 130, head.getPosition().y + head.getOrigin().y + 80);

	rightarm_01.setOrigin(-head.getRadius(), rightarm_01.getSize().y / 2.f); // Je centre son origine au centre du rectangle
	rightarm_01.rotate(45);
	head.setOrigin(40, 40);
	rightarm_01.setPosition(head.getPosition().x + head.getOrigin().x, head.getPosition().y + head.getOrigin().y);

	rightarm_02.setOrigin(-head.getRadius(), rightarm_02.getSize().y / 2.f); // Je centre son origine au centre du rectangle
	rightarm_02.rotate(90);
	head.setOrigin(40, 40);
	rightarm_02.setPosition(head.getPosition().x + head.getOrigin().x + 140, head.getPosition().y + head.getOrigin().y + 70);

	boss->head = head;	
	boss->leftArm.push_back(leftarm_01);
	boss->leftArm.push_back(leftarm_02);
	boss->rightArm.push_back(rightarm_01);
	boss->rightArm.push_back(rightarm_02);
	*/
	world->boss = *boss;
	
}

void UpdateBoss(Boss* boss) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		boss->leftArm[0].rotate(boss->leftArm[0].getRotation() + 5.f);



}

void RefreshBoss(Boss* boss,sf::RenderWindow& window) {
	/*window.draw(boss->head);
	
	for (sf::RectangleShape rectangle : boss->rightArm) 
		window.draw(rectangle);
	for (sf::RectangleShape rectangle : boss->leftArm) 
		window.draw(rectangle);
	
	sf::Vertex lines[16];
	std::copy(boss->weaknessArea.begin(), boss->weaknessArea.end(), lines);
	window.draw(lines, boss->weaknessArea.size(), sf::Lines);
	*/
}
