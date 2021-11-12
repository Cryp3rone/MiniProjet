#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"
enum PF_TYPE
{
	NORM,
	FLY,
};
World* GenerateLevel(sf::RenderWindow& window) {
	World* level = new World;

	int pFType;// si PF Volante ou non
	int pos = 10; //position par default
	int offset = 20;//décalage par default 
	int sizeL = 40;// taill par default d'une PF
	int jumpH = 50;// taill temporaire du saut du joueur
	//int randH;//futur var pour gestion du c
	int H;//taill final de la PF après gestion de la hauteur de saut de joueur (In proges)
	int preceH = 0;//contien la hauteur de la PF avant celle qui spawn

	srand(time(NULL));
	
	for (size_t i = 0; i < 100; i++) //entre le nombre de PF que tu veux faire spawn
	{
		pFType = rand() % 2;
		sizeL = rand() % 210 + 50;
		offset = rand() % 150 + 50;
		H = rand() % 330 + 200;
		if (preceH < H) // a terme pemetre de pas creer des platrforme inategnable pour le joueur en géran la hauteur max du saut
		{
			
			int diff = (preceH - H);
			std::cout << "i = " << i << std::endl;
			std::cout << "--jumpH " << jumpH << std::endl;
			std::cout << "---- preceH " << preceH << std::endl;
			std::cout << "------- H " << H << std::endl;
			std::cout << "---------diff " << diff << std::endl;
			//H += (jumpH);
			std::cout << "reduction appliquer a cette hauteur" << std::endl;
			//CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 1000)), sf::Color::Red, sf::Vector2f(pos, H), 5, sf::Color::Yellow, level);
		}
		else
		{
			
		}
		switch (pFType)
		{
		case(0):
			CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 1000)), sf::Color::Black, sf::Vector2f(pos, H), 3, sf::Color::Yellow, level);
			preceH = H;
			break;
		case(1):
			CreateRectangleShape(sf::RectangleShape(sf::Vector2f(sizeL, 30)), sf::Color::Black, sf::Vector2f(pos, H), 3, sf::Color::Yellow, level);
			break;
		default:
			break;
		}
		pos += sizeL + offset;
		CreateRectangleShape(sf::RectangleShape(sf::Vector2f(100000000, 125)), sf::Color::Black, sf::Vector2f(0, 475), 3, sf::Color::Blue, level);
	}
	//affiche le sol après comme ça il passe devant les autres platformes
	


	//code du niveau pre set
	/*CreateRectangleShape(sf::RectangleShape(sf::Vector2f(100000000, 125)), sf::Color::Black, sf::Vector2f(0, 475), 3, sf::Color::Blue, level);
	* 80= w
	* 45=1000
	* 800= precedentW + maxJumpMax
	CreateRectangleShape(sf::RectangleShape(sf::Vector2f(80, 45)), sf::Color::Black, sf::Vector2f(800, 425), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(50, 45)), sf::Color::Black, sf::Vector2f(900, 425), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(50, 100)), sf::Color::Black, sf::Vector2f(1100, 375), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape(sf::Vector2f(80, 100)), sf::Color::Black, sf::Vector2f(1350, 375), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape(sf::Vector2f(250, 13)), sf::Color::Black, sf::Vector2f(1500, 350), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(250, 13)), sf::Color::Black, sf::Vector2f(2000, 375), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape (sf::Vector2f(250, 13)), sf::Color::Black, sf::Vector2f(2500, 375), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape(sf::Vector2f(100, 13)), sf::Color::Black, sf::Vector2f(2600, 300), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape(sf::Vector2f(80, 13)), sf::Color::Black, sf::Vector2f(2670, 200), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape(sf::Vector2f(90, 13)), sf::Color::Black, sf::Vector2f(2800, 270), 3, sf::Color::Yellow, level);
	CreateRectangleShape(sf::RectangleShape(sf::Vector2f(110, 40)), sf::Color::Black, sf::Vector2f(3000, 270), 3, sf::Color::Yellow, level);*/

	return level;
}
void RefreshWorld(World* level, sf::RenderWindow& window) {
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

