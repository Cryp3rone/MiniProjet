#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

struct Level {
	std::vector<sf::RectangleShape> rectangles;
};

Level* GenerateLevel();
void CreateRectangleShape(sf::RectangleShape shape, sf::Color color, sf::Vector2f position, float thickness, sf::Color thicknessColor,Level* level);
void UpdateLevel(sf::RenderWindow& window, Level* level);