#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include <windows.h>
#include "LevelGenerator.h"
#include "Ennemy.h"
#include "Player.h"
#include "Shoot.h"
#include "GameState.h"

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
	text.setPosition(camera.getCenter().x  - 180, camera.getCenter().y  - 130);
	text.setString("GAME \n OVER ");
	text.setFillColor(sf::Color::Yellow);
	text.setScale(4.f, 4.f);

	World* world = nullptr;
	bool firstFrame = true;

	//Player
	sf::Vector2f velocity(0.f,  5.f);
	float speed = 100.f;
	Player player = newPlayer();

	std::list<Bullet> bullets;
	GameState game = PLAY;

	// Inputs
	while (window.isOpen()) {
		sf::Event event;
		sf::Time elapsedTime = clock.restart();
		float dt = elapsedTime.asSeconds();

		if (CanWallJump(player)) {
			Plateform& collisionPlateform = *(player.collision.plateform);
			velocity.x = jumpForce * collisionPlateform.jumpDirection;
			velocity.y = jumpForce;
			player.canJump = true;
			JumpPlayer(player,dt,velocity,world);
		}

		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonPressed:
					Shoot(player.body.getPosition(), window.mapPixelToCoords(sf::Mouse::getPosition(window)), bullets, dt);
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Space && CanStopJump(player)) 
						player.canJump = false;
					break;
			}
		}
		//Logique

		if (firstFrame) {
			world = GenerateLevel();
			CreateEnnemies(world);
			firstFrame = false;
		}

		if (game == PLAY) {
			UpdateEnnemies(world, elapsedTime.asSeconds());
			UpdatePlayer(player, elapsedTime.asSeconds(), velocity, camera, world,bullets,game);

			for (Bullet& bullet : bullets)
				bullet.body.move(bullet.currVelocity);
			
			if (player.health == 0)
				game = LOOSE;
		}
		updateBullet(bullets, camera);

		//Rendu
		window.clear();

		if (game == PLAY) {
			RefreshWorld(world, window);
			RefreshEnnemies(world, window);

			window.setView(camera);
			window.draw(player.body);

			for (Bullet& bullet: bullets)
			{
				window.draw(bullet.body);
			}

		}
		else if(game == LOOSE)
			window.draw(text);	
		else {
			text.setString("VICTOIRE");
			text.setFillColor(sf::Color::Green);
			text.setPosition(camera.getCenter().x - 50, camera.getCenter().y - 50);
			window.draw(text);
		}
		window.display();
	}
}
