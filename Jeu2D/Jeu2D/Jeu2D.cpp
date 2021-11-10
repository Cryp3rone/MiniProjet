#include <iostream>
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"

void Zoom(sf::View& view,sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) 
		view.zoom(1.05f);
}
const float GROUND_Y = 400.f;

int main() {

	sf::RenderWindow window(sf::VideoMode(1200, 600), "Jeu2D");
	window.setVerticalSyncEnabled(true); // Cap les fps au fps du pc

	sf::Clock clock;
	sf::View camera(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(window.getSize().x,window.getSize().y));
	
	World* world = nullptr;
	bool firstFrame = true;
	float dt;

	sf::Vector2f velocity(0.f, 0.f);
	float speed = 100.f;

	//Player
	Player player = newPlayer();

	// Inputs
	sf::RectangleShape ground(sf::Vector2f(3000.f, 400.f));
	ground.setPosition(0.f, 400.f);


	sf::RenderWindow window(sf::VideoMode(1000, 800), "Jeu2D");
	while (window.isOpen()) {
		dt = clock.restart().asSeconds();


		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:

					window.close();
					break;
				
			}
		}

		MovePlayer(player, dt, velocity);

		//Logique
		
		sf::Time elapsedTime = clock.restart();
		if (firstFrame) {
			world = GenerateLevel();
			CreateEnnemies(world);
			firstFrame = false;
		}

		UpdateEnnemies(world, elapsedTime.asSeconds());

		//Rendu
		window.clear();
		
		RefreshWorld(world,window);
		RefreshEnnemies(world,window);

		Zoom(camera, window);
		window.setView(camera);

		// DRAW SECTION
		window.draw(ground);
		window.draw(player.body);

		window.display();
	}
}

