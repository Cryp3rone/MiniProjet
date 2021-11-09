#include <iostream>
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"

void Zoom(sf::View& view,sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) 
		view.zoom(1.05f);
}

int main() {

	sf::RenderWindow window(sf::VideoMode(1200, 600), "Jeu2D");
	window.setVerticalSyncEnabled(true); // Cap les fps au fps du pc

	sf::Clock clock;
	sf::View camera(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(window.getSize().x,window.getSize().y));
	

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
		Zoom(camera, window);
		window.setView(camera);
		GenerateLevel(window);
		window.display();
	}
}

