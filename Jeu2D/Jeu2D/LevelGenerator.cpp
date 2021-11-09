#include <iostream>
#include <SFML/Graphics.hpp>

void CreateShape(sf::Shape& shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor, sf::RenderWindow& window) {
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setOutlineThickness(thickness);
	shape.setOutlineColor(thicknessColor);

	window.draw(shape);
}

void GenerateLevel(sf::RenderWindow& window) {
	sf::RectangleShape floor(sf::Vector2f(/*window.getSize().x*/ 3000, 125));
	CreateShape(floor,sf::Color::Black,sf::Vector2f(0,475),3,sf::Color::Blue,window);

	sf::RectangleShape obs_01(sf::Vector2f(50, 50));
	CreateShape(obs_01, sf::Color::Black, sf::Vector2f(900, 425), 3, sf::Color::Yellow, window);

	sf::RectangleShape obs_02(sf::Vector2f(50, 100));
	CreateShape(obs_02, sf::Color::Black, sf::Vector2f(1100, 375), 3, sf::Color::Yellow, window);

	sf::RectangleShape plat_01(sf::Vector2f(250, 13));
	CreateShape(plat_01, sf::Color::Black, sf::Vector2f(2000, 375), 3, sf::Color::Yellow, window);

	sf::RectangleShape plat_02(sf::Vector2f(250, 13));
	CreateShape(plat_02, sf::Color::Black, sf::Vector2f(2500, 375), 3, sf::Color::Yellow, window);

	sf::CircleShape enn_01(15, 3);
	enn_01.setOrigin(7.5f, 1.5f);
	CreateShape(enn_01, sf::Color::Black, sf::Vector2f(1500, 450), 3, sf::Color::Color(255,153,0), window);
}

