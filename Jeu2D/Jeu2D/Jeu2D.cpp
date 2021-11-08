#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"

void Zoom(sf::View& view) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		//view.zoom(0.5f);
		view.setSize(1200, 800);
		std::cout << "zoom" << std::endl;
	}
}

int main() {

	sf::RenderWindow window(sf::VideoMode(1200, 600), "Jeu2D");
	window.setVerticalSyncEnabled(true); // Cap les fps au fps du pc

	sf::Clock clock;

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

		// DRAW SECTION

		//Logique
		sf::Time elapsedTime = clock.restart();



		//Rendu
		window.clear();
		sf::View camera(sf::Vector2f(window.getPosition().x / 2, window.getPosition().y / 2), sf::Vector2f(window.getPosition().x,window.getPosition().y));
		Zoom(camera);
		GenerateLevel(window);
		window.display();
	}
}

