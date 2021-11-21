#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <windows.h>
#include "LevelGenerator.h"
#include "Ennemy.h"
#include "Player.h"
#include "Shoot.h"
#include "GameState.h"
#include "Boss.h"
#include "Bonus.h"

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

	sf::SoundBuffer buffer;
	buffer.loadFromFile(getAssetsPath() + "\\music.ogg");

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setLoop(true);
	sound.setVolume(20.f);
	//sound.play();

	// Inputs
	while (window.isOpen()) {
		sf::Event event;
		sf::Time elapsedTime = clock.restart();
		float dt = elapsedTime.asSeconds();

		if (CanWallJump(player)) {
			Plateform* plateform = nullptr;

			for (std::pair<sf::Shape*,Collision*> collisionPair : player.collisions) {
				for (std::pair<sf::RectangleShape*, Plateform*> plateformPair : world->plateforms) {
					if (collisionPair.first == &plateformPair.second->rectangle) {
						plateform = plateformPair.second;
					}
				}
			}

			std::cout << "enterWall: " << plateform << std::endl;

			if (plateform) {
				sf::RectangleShape& shape = plateform->rectangle;
				sf::FloatRect playerCollision = player.body.getGlobalBounds();

				float left, top, width, height;
				if (plateform->jumpDirection == 1) { // Partie droite
					left = shape.getPosition().x - 5;
					top = shape.getPosition().y;
					width = 15;
					height = shape.getSize().y;
				}
				else {
					left = shape.getPosition().x + shape.getSize().x - 10;
					top = shape.getPosition().y;
					width = 25;
					height = shape.getSize().y;
				}

				sf::FloatRect check = sf::FloatRect(left, top, width, height);

				if (check.intersects(playerCollision)) {
					velocity.x = jumpForce * plateform->jumpDirection;
					velocity.y = jumpForce;
					player.lastDirection.x = plateform->jumpDirection * -1;
					player.canJump = true;
					JumpPlayer(player, dt, velocity, world);
				}
				else
					player.canJump = true;
			}
		}

		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
				//	UnloadLevel(world,player);
					window.close();
					return 0;
					break;
				case sf::Event::MouseButtonPressed:
					Shoot(player, window.mapPixelToCoords(sf::Mouse::getPosition(window)), bullets,PLAYER, dt);
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
			for (Bullet& bullet : bullets)
				bullet.body.move(bullet.currVelocity);

			ActualizeGroundY(player,world);
			UpdateEnnemies(world, elapsedTime.asSeconds());
			UpdatePlayer(player, elapsedTime.asSeconds(), velocity, camera, world,bullets,game);
			if(world->boss)
				UpdateBoss(world,world->boss,player,bullets,dt);

			
			if (player.health == 0)
				game = LOOSE;
		}
		updateBullet(bullets, camera);

		//Rendu
		window.clear();

		if (game == PLAY) {
			RefreshWorld(world, window);
			RefreshEnnemies(world, window);
			if(world->boss)
				RefreshBoss(world->boss,window,camera);

			window.setView(camera);
			window.draw(player.body);

			for (int i = 1; i <= player.ammo; i++) {
				sf::CircleShape ammo = sf::CircleShape(12.f);
				ammo.setFillColor(sf::Color::Green);
				ammo.setPosition(sf::Vector2f(30.f * i, 20.f));
				window.draw(ammo);
			}

			for (Bullet& bullet: bullets)
				window.draw(bullet.body);

			for (Bonus& bonus : world->listBonus)
				window.draw(bonus.body);
			

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
