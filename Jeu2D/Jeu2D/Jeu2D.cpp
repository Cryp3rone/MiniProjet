#include <iostream>
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "Ennemy.h"

const float GROUND_Y = 400.f;

int main() {
	sf::Clock clock;
	float dt;

	sf::Vector2f velocity(0.f, 0.f);
	float speed = 100.f;

	//Player
	Player player = newPlayer();

	// Inputs
	sf::RectangleShape ground(sf::Vector2f(3000.f, 400.f));
	ground.setPosition(0.f, 400.f);


	sf::RenderWindow window(sf::VideoMode(1000, 800), "Jeu2D");
	window.setVerticalSyncEnabled(true); // Cap les fps au fps du pc
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

		// DRAW SECTION
		window.clear();
		window.draw(ground);
		window.draw(player.body);

		window.display();
	}
}

