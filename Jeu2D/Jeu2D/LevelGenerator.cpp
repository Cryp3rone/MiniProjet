#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"


World* GenerateLevel() {
	World* level = new World;

	// ATTENTION FAIRE SPAWN QUE DES sf::RectangleShape pour les plateformes

	int pFType;// si PF Volante ou non
	int pos = 800; //position par default
	int offset = 20;//d�calage par default
	int sizeL = 40;// taill par default d'une PF
	int jumpH = 50;// taill temporaire du saut du joueur
	//int randH;//futur var pour gestion du c
	int H = 400;//taill final de la PF apr�s gestion de la hauteur de saut de joueur (In proges)
	int preceH = 0;//contien la hauteur de la PF avant celle qui spawn
	int growsize = 0;

	int floorSize = 0;
	int floorPos = 500;
	int holeSize = 0;
	int holePos = 0;
	int holeOfset = 20;
	bool mustChange = false;
	//H si la taill de la plateform avant est a hauteur de saut alors ont peut sauter plus haut
	//et si la tail de la plateform d'avant est sup�rieur a la hauteur de saut alors la plateform seras plus bas et a hauter de saut

	srand(time(NULL));

	for (size_t i = 0; i < 1; i++) { //entre le nombre de PF que tu veux faire spawn

		pFType = /*rand() % 9*/8;
		sizeL = rand() % 210 + 50;
		offset = rand() % 150 + 100;
		bool spawn = false;
		int wallJumpOffSett = rand() % 180 + 120;

		if ((pos+jumpH) >=H) {
			std::cout << "__________________tkt mec" << i << " "<< abs(H - preceH) << std::endl;
			H += jumpH;
		}
		switch (pFType) {
			case(0):
				CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 500)), sf::Color::Black, sf::Vector2f(pos, H), 3, sf::Color::Yellow, true, level), 0, NORMAL, level);
				H = 300 + (rand() % (350 - 300 + 1));
				pos += sizeL + offset;
				break;
			case(1):
				CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 30)), sf::Color::Black, sf::Vector2f(pos, H), 3, sf::Color::Yellow, true, level), 0, NORMAL, level);
				pos += sizeL + offset;
				H = 300 + (rand() % (350 - 300 + 1));
				break;
			case(2):
				CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 1000)), sf::Color::Black, sf::Vector2f(pos, H), 3, sf::Color::Yellow, true, level), 0, ENNEMI, level);
				H = 300 + (rand() % (350 - 300 + 1));
				preceH = H;
				pos += sizeL + offset;
				break;
			case(3):
				CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 30)), sf::Color::Black, sf::Vector2f(pos, H), 3, sf::Color::Yellow, true, level), 0, ENNEMI, level);
				pos += sizeL + offset;
				H = 300 + (rand() % (350 - 300 + 1));
				break;
			case(4):
				CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 500)), sf::Color::Black, sf::Vector2f(pos, H), 3, sf::Color::Yellow, true, level), 0, NORMAL, level);
				H = 300 + (rand() % (350 - 300 + 1));
				pos += sizeL + offset;
				break;
			case(5):
				CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 30)), sf::Color::Black, sf::Vector2f(pos, H), 3, sf::Color::Yellow, true, level), 0, NORMAL, level);
				pos += sizeL + offset;
				H = 300 + (rand() % (350 - 300 + 1));
				break;
			case(6):
				CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 1000)), sf::Color::Black, sf::Vector2f(pos, H), 3, sf::Color::Yellow, true, level), 0, ENNEMI, level);
				H = 300 + (rand() % (350 - 300 + 1));
				preceH = H;
				pos += sizeL + offset;
				break;
			case(7): // Faire surcharge fonction
				CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 30)), sf::Color::Black, sf::Vector2f(pos, H), 3, sf::Color::Yellow, true, level), 0, NORMAL, level);
				pos += sizeL + offset;
				H = 300 + (rand() % (350 - 300 + 1));
				break;
			case(8):
				if (!spawn) {
					H = 300 + (rand() % (350 - 300 + 1));
					//CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(30, 200)), sf::Color::Black, sf::Vector2f(pos, 170), 3, sf::Color::Yellow, true, level), -1, WALL_JUMP,level); // Partie Gauche
					int randomY = rand() % 300 + 200;
					//CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(30, randomY)), sf::Color::Black, sf::Vector2f(pos + wallJumpOffSett, 170), 3, sf::Color::Magenta, true, level), 1, WALL_JUMP,level); // Partie Droite
					pos += sizeL + offset + wallJumpOffSett;
					spawn = true;
				}
				break;
		}

		//CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(100000000, 125)), sf::Color::Black, sf::Vector2f(0, 475), 3, sf::Color::Blue, false, level),0,NORMAL,level);
	}

	for (size_t i = 0; i < 10; i++) {
		pFType = rand() % 5;
		floorSize = rand() % 600 + 400;

		holeSize = rand() % 100 + 50;
		offset = rand() % 200 + 100;

		CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(floorSize, 125)), sf::Color::Black, sf::Vector2f(floorPos, 475), 3, sf::Color::Blue, false, level), 0, FLOOR, level);

		floorPos += holeSize + offset + floorSize;
	}


//	CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(40, 20)), sf::Color::Black, sf::Vector2f(pos + 35, 200), 3, sf::Color::Green, false, level), 0, NORMAL,40,20, level);
	
	
//	level->endFlag = CreateRectangleShape(sf::RectangleShape(sf::Vector2f(10, 300)), sf::Color::Black, sf::Vector2f(pos + 35, 200), 3, sf::Color::Green, false, level);
//	CreatePlateform(level->endFlag, 0, NORMAL,15,300, level);
	
	
	
//	CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(10, 300)), sf::Color::Black, sf::Vector2f(pos + 35, 200), 3, sf::Color::Green, false, level), 0, NORMAL,10,300, level);
//	CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(50, 30)), sf::Color::Black, sf::Vector2f(pos + 15, 450), 3, sf::Color::Green, false, level), 0, NORMAL,50,30,level);
//	CreatePlateform(CreateRectangleShape(sf::RectangleShape(sf::Vector2f(80, 30)), sf::Color::Black, sf::Vector2f(pos, 475), 3, sf::Color::Green, false, level), 0, NORMAL,80,30, level);

	sf::RectangleShape* lastShape = nullptr;
	for (Plateform* plateform : level->plateforms) {
		if (plateform->type == FLOOR) {

			if (lastShape) {
				sf::FloatRect collision = sf::FloatRect(lastShape->getPosition().x + lastShape->getSize().x,lastShape->getPosition().y,plateform->rectangle.getPosition().x - (lastShape->getPosition().x + lastShape->getSize().x),1000);
				level->voidArea.push_back(collision);
			}

			lastShape = &plateform->rectangle;
		}
	}
	level->groundY = originalGroundY;

	return level;
}

void RefreshWorld(World* level, sf::RenderWindow& window) {
	for (Plateform* plateform : level->plateforms)
		window.draw(plateform->rectangle);
}

void ActualizeGroundY(Player& player, World* world) {
	bool isOnFloor = true;

	for (Plateform* plateform : world->plateforms) {
		if (plateform->type == FLOOR) {
			isOnFloor = player.body.getPosition().x >= plateform->rectangle.getPosition().x && player.body.getPosition().x <= plateform->rectangle.getPosition().x + plateform->rectangle.getSize().x /*&& world->groundY == originalGroundY*/;
			
			if (isOnFloor)
				break;
		}
	}

	//if (!isOnFloor && !player.collision.isOnCollision) 
		//world->groundY = 1000.f;
}

sf::RectangleShape CreateRectangleShape(sf::RectangleShape shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor,bool createPlateform, World* level) {
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setOutlineThickness(thickness);
	shape.setOutlineColor(thicknessColor);

	return shape;
}

sf::CircleShape CreateCircleShape(sf::CircleShape shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor, World* level) {
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setOutlineThickness(thickness);
	shape.setOutlineColor(thicknessColor);

	return shape;
}
