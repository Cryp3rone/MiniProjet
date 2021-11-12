#include <iostream>
#include <SFML/Graphics.hpp>
#include <List>
#include "LevelGenerator.h"
#include "Ennemy.h"
#include "Player.h"
#include "Shoot.h"

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

	//Player
	sf::Vector2f velocity(0.f, 0.f);
	float speed = 100.f;
	Player player = newPlayer();

	std::list<Bullet> bullets;

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
		MovePlayer(player, elapsedTime.asSeconds(), velocity,camera,world);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Shoot(player.body.getPosition(), (sf::Vector2f)sf::Mouse::getPosition(window), bullets);
		}

		for (Bullet bullet : bullets)
		{
			bullet.body.move(bullet.currVelocity);
		}

		//Rendu
		window.clear();
		
		RefreshWorld(world,window);
		RefreshEnnemies(world,window);

		Zoom(camera, window);
		window.setView(camera);

		window.draw(player.body);
		for (Bullet bullet: bullets)
		{
			window.draw(bullet.body);
		}

		window.display();
	}
}

