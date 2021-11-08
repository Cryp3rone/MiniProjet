#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

	sf::Clock clock;
	float dt;

	sf::Vector2f velocity;

	float speed = 100.f;

	//Player
	sf::CircleShape player(100.f);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Jeu2D");
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			player.move(sf::Vector2f(0.f, -speed * dt));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			player.move(sf::Vector2f(0.f, speed * dt));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			player.move(sf::Vector2f(-speed * dt, 0.f));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			player.move(sf::Vector2f(speed * dt, 0.f));

		window.clear();

		// DRAW SECTION
		window.draw(player);

		window.display();
	}
}
