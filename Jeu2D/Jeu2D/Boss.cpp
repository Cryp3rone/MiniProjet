#pragma once
#include "Boss.h"
#include <cmath>

Boss* CreateBoss(World* world) {
	Boss* boss = new Boss;

	sf::CircleShape* head = CreateCircleShape(sf::CircleShape(80), sf::Color::Black, sf::Vector2f(900, 200),3,sf::Color::Magenta,world);
	sf::RectangleShape leftarm_01 = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(120, 20)), sf::Color::Black, sf::Vector2f(820.f,405.f), 3, sf::Color::Magenta, false, world);
	sf::RectangleShape leftarm_02 = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(120, 15)), sf::Color::Black, sf::Vector2f(830.f, 410.f), 3, sf::Color::Magenta, false, world); //leftarm_01.setOrigin(sf::Vector2f(head.getPosition().x + head.getRadius(),head.getPosition().y + head.getRadius()));

	sf::RectangleShape rightarm_01 = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(120, 20)), sf::Color::Black, sf::Vector2f(1060.f, 315.f), 3, sf::Color::Magenta, false, world);
	sf::RectangleShape rightarm_02 = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(120, 15)), sf::Color::Black, sf::Vector2f(1150.f, 410.f), 3, sf::Color::Magenta, false, world);

	// begin 225� = 3,92 to 315� = 5,5
	
	for (float i = 3.92;i < 5.5;i+=0.1f) {
		float angle = 3.14159265358979323846f * 2 * i / 360;
		float x = head->getPosition().x + (head->getRadius() * std::sin(angle));
		float y = head->getPosition().y + (head->getRadius() * std::cos(angle));
		std::cout << "x: " << x << " y: " << y << "radius: " << head->getRadius() << std::endl;
		
		//boss->weaknessArea.push_back(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(1.f, 1.f)),sf::Color::Yellow, sf::Vector2f(round(x * 100) / 100, round(y * 100) / 100),0,sf::Color::Black,false,world));
	}
	

	leftarm_01.rotate(-45);
	leftarm_02.rotate(90);
	rightarm_01.rotate(45);
	rightarm_02.rotate(90);

	
	boss->head = *head;	
	boss->leftArm.push_back(leftarm_01);
	//boss->leftArm.push_back(leftarm_02);
	//boss->rightArm.push_back(rightarm_01);
	//boss->rightArm.push_back(rightarm_02);
	
	return boss;
}

void UpdateBoss(Boss* boss) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		boss->leftArm[0].rotate(boss->leftArm[0].getRotation() + 5.f);
		
	//std::cout << "size: " << boss->leftArm[0].getPosition().x  << " rotate: " << boss->leftArm[0].getRotation() << std::endl;


}

void RefreshBoss(Boss* boss,sf::RenderWindow& window) {
	window.draw(boss->head);
	
	for (sf::RectangleShape rectangle : boss->rightArm) 
		window.draw(rectangle);
	for (sf::RectangleShape rectangle : boss->leftArm) 
		window.draw(rectangle);
	for (sf::RectangleShape rectangle : boss->weaknessArea)
		window.draw(rectangle);

}
