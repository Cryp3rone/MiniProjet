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
		sf::Time elapsedTime = clock.restart();
		float dt = elapsedTime.asSeconds();
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:

					window.close();
					break;
				case sf::Event::MouseButtonPressed:
					sf::Vector2i pos = sf::Mouse::getPosition(window);
					Shoot(player.body.getPosition(), window.mapPixelToCoords(pos), bullets, dt);
			}
		}
		//Logique	

		if (firstFrame) {
			world = GenerateLevel();
			CreateEnnemies(world);
			firstFrame = false;
		}

		UpdateEnnemies(world, dt);
		MovePlayer(player, dt, velocity,camera,world);
		
		for (Bullet& bullet : bullets)
		{
			bullet.body.move(bullet.currVelocity);
		}
		updateBullet(bullets, camera);
		std::cout << bullets.size() << std::endl;

		//Rendu
		window.clear();
		
		RefreshWorld(world,window);
		RefreshEnnemies(world,window);

		Zoom(camera, window);
		window.setView(camera);

		window.draw(player.body);
		for (Bullet& bullet: bullets)
		{
			window.draw(bullet.body);
		}

		window.display();
	}
}

