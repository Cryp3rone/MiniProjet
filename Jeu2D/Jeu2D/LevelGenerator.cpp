#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ennemy.h"
#include "Player.h"


World* GenerateLevel() {
	World* level = new World;

	// ATTENTION FAIRE SPAWN QUE DES sf::RectangleShape pour les plateformes

	int pFType;// si PF Volante ou non
	int pos = 100; //position par default
	int offset = 20;//décalage par default 
	int sizeL = 40;// taill par default d'une PF
	int jumpH = 50;// taill temporaire du saut du joueur
	//int randH;//futur var pour gestion du c
	int H;//taill final de la PF après gestion de la hauteur de saut de joueur (In proges)
	int preceH = 0;//contien la hauteur de la PF avant celle qui spawn
	int growsize = 0;
	srand(time(NULL));
	for (size_t i = 0; i < 20; i++) //entre le nombre de PF que tu veux faire spawn
	{
		
		pFType = rand() % 2;
		sizeL = rand() % 210 + 50;
		offset = rand() % 150 + 100;
		H = rand() % 330 + 200;
		switch (pFType)
		{
		case(0):

			//CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 1000)), sf::Color::Black, sf::Vector2f(pos, H), 3, sf::Color::Yellow, level);
			preceH = H;
			break;
		case(1):
			//CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 30)), sf::Color::Black, sf::Vector2f(pos, H), 3, sf::Color::Yellow, level);
			break;
		default:
			break;
		}
		pos += sizeL + offset;
		CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(100000000, 125)), sf::Color::Black, sf::Vector2f(0, 475), 3, sf::Color::Blue, false, level), 0, NORMAL, 100000000, 125,level);
	}

	
	CreateRectangleShape(sf::RectangleShape(sf::Vector2f(40, 20)), sf::Color::Black, sf::Vector2f(pos + 35, 200), 3, sf::Color::Green, false, level);
	level->endFlag = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(10, 300)), sf::Color::Black, sf::Vector2f(pos + 35, 200), 3, sf::Color::Green, false, level);
	CreateRectangleShape(sf::RectangleShape(sf::Vector2f(50, 30)), sf::Color::Black, sf::Vector2f(pos+15, 450), 3, sf::Color::Green, false, level);
	CreateRectangleShape(sf::RectangleShape(sf::Vector2f(80, 30)), sf::Color::Black, sf::Vector2f(pos, 475), 3, sf::Color::Green, false, level);
	
	// WALL JUMP
	
	//CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(50, 300)), sf::Color::Black, sf::Vector2f(400, 170), 3, sf::Color::Yellow, true, level),-1, WALL_JUMP,50,300,level);
	//CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(50, 300)), sf::Color::Black, sf::Vector2f(650,170), 3, sf::Color::Yellow, true, level),1,WALL_JUMP,50,300,level);

	CreateCircleShape(sf::CircleShape(20),sf::Color::Black,sf::Vector2f(600,170),3,sf::Color::Magenta,level);

	level->groundY = originalGroundY;
	//affiche le sol après comme ça il passe devant les autres platformes

	return level;
}

void RefreshWorld(World* level, sf::RenderWindow& window) {
	for (Plateform* plateform : level->plateforms) {
		window.draw(plateform->rectangle);
	}
}


sf::RectangleShape CreateRectangleShape(sf::RectangleShape shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor,bool createPlateform, World* level) {
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setOutlineThickness(thickness);
	shape.setOutlineColor(thicknessColor);

	//window.draw(shape);

	return shape;
}

sf::CircleShape CreateCircleShape(sf::CircleShape shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor, World* level) {
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setOutlineThickness(thickness);
	shape.setOutlineColor(thicknessColor);
	return shape;
	//window.draw(shape);
}

