#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "HealthBar.h"
#include "Timer.h"


enum BossState {
	NONE,
	ANGRY
};

struct Boss {
	sf::CircleShape head;
	std::vector<sf::RectangleShape> rightArm;
	std::vector<sf::RectangleShape> leftArm;
	std::vector<sf::Vertex> weaknessArea;
	sf::CircleShape weaknessCollision;
	sf::RectangleShape canon;
	Timer* canonTimer;
	Timer* rotateTimer;
	HealthBar bar;
	int health;
	int maxHealth;
	int damage;
	bool canMoove;
	float speed;
	bool wait;
	float originalLeftAngle;
	float originalRightAngle;
	bool rotateLeftArm;
	BossState state;
};