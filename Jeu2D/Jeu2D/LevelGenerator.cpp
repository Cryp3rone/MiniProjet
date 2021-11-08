#include <iostream>
#include <SFML/Graphics.hpp>

void GenerateLevel(sf::RenderWindow& window) {
	sf::RectangleShape floor(sf::Vector2f(/*window.getSize().x*/ 1200, 125));

	floor.setFillColor(sf::Color::Black);
	floor.setPosition(0, 475);
	floor.setOutlineThickness(3);
	floor.setOutlineColor(sf::Color::Blue);
//	window.draw(floor);

	sf::RectangleShape firstObs(sf::Vector2f(50, 50));

	firstObs.setFillColor(sf::Color::Black);
	firstObs.setPosition(425,425);
	firstObs.setOutlineThickness(3);
	firstObs.setOutlineColor(sf::Color::Yellow);
	window.draw(firstObs);
}