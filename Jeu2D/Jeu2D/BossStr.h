#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct Boss {
	sf::CircleShape head;
	std::vector<sf::RectangleShape> rightArm;
	std::vector<sf::RectangleShape> leftArm;
	std::vector<sf::Vertex> weaknessArea;
	int health;
	int damage;
	bool canMoove;
	float speed;
	bool wait;
	float waitTimer;
	float originalLeftAngle;
	float originalRightAngle;
	bool rotateLeftArm;
};