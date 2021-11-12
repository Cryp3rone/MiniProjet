#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "LevelGenerator.h"
#include "Ennemy.h"
#include "Player.h"

enum GameState {
	PLAY,
	LOOSE,
	WIN
};


std::string getAppPath() {
	char cExeFilePath[256];
	GetModuleFileNameA(NULL, cExeFilePath, 256);
	std::string exeFilePath = cExeFilePath;
	int exeNamePos = exeFilePath.find_last_of("\\/");
	return exeFilePath.substr(0, exeNamePos + 1);
}

std::string getAssetsPath() {
	return getAppPath() + "\\Assets";
}

int main() {

	sf::RenderWindow window(sf::VideoMode(1200, 600), "Jeu2D");
	window.setVerticalSyncEnabled(true); // Cap les fps au fps du pc

	sf::Clock clock;
	sf::View camera(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), sf::Vector2f(window.getSize().x,window.getSize().y));
	sf::Font font;
	font.loadFromFile(getAssetsPath() + "\\GeometricBlack.ttf");

	sf::Text text;
	text.setFont(font);
	text.setPosition(window.getSize().x / 2 - 180,window.getSize().y / 2 - 130);
	text.setString("GAME \n OVER ");
	text.setFillColor(sf::Color::Yellow);
	text.setScale(4.f, 4.f);

	World* world = nullptr;
	bool firstFrame = true;

	sf::Vector2f velocity(0.f, 0.f);
	float speed = 100.f;

	//Player
	Player player = newPlayer();

	GameState game = PLAY;

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

		if (game == PLAY) {
			UpdateEnnemies(world, elapsedTime.asSeconds());
			MovePlayer(player, elapsedTime.asSeconds(), velocity, camera, world);

			if (player.health == 0)
				game = LOOSE;
		}

		//Rendu
		window.clear();
		
		if (game == PLAY) {
			RefreshWorld(world, window);
			RefreshEnnemies(world, window);

			window.setView(camera);
			window.draw(player.body);
		}
		else if(game == LOOSE){
			window.draw(text);
		}
		else {
			text.setString("VICTOIRE");
			text.setFillColor(sf::Color::Green);
			text.setPosition(window.getSize().x / 2 - 325, window.getSize().y / 2 - 130);
			window.draw(text);
		}
		window.display();
	}
}

