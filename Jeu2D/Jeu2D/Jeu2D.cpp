#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"
#include "Player.h"

void Zoom(sf::View& view,sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) 
		view.zoom(1.05f);
}

int main() {

	sf::RenderWindow window(sf::VideoMode(1200, 600), "Jeu2D");
	window.setVerticalSyncEnabled(true); // Cap les fps au fps du pc

	sf::Clock clock;
	sf::View camera(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(window.getSize().x,window.getSize().y));
	
	World* world = nullptr;
	bool firstFrame = true;

	sf::Vector2f velocity(0.f, 0.f);
	float speed = 100.f;

	//Player
	Player player = newPlayer();

	// Inputs
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:

					window.close();
					break;
				
			}
		}


		//Logique
		
		sf::Time elapsedTime = clock.restart();
		if (firstFrame) {
			world = GenerateLevel();
			CreateEnnemies(world);
			firstFrame = false;
		}

		UpdateEnnemies(world, elapsedTime.asSeconds());
		MovePlayer(player, elapsedTime.asSeconds(), velocity,camera);


		//Rendu
		window.clear();
		
		RefreshWorld(world,window);
		RefreshEnnemies(world,window);

		Zoom(camera, window);
		window.setView(camera);

		window.draw(player.body);
		window.display();
	}
}

