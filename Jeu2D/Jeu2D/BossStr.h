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
	bool canRotate;
	float speed;
	bool wait;
	float originalLeftAngle;
	float originalRightAngle;
	bool rotateLeftArm;
	BossState state;

	Boss(sf::CircleShape head_, bool canRotate_, int speed_, float originalLeftAngle_, float originalRightAngle_, bool wait_, bool rotateLeftArm_, int health_, int maxHealth_, sf::CircleShape weaknessCollision_, sf::RectangleShape canon_, Timer* canonTimer_, Timer* rotateTimer_, HealthBar bar_, BossState state_) {
		head = head_;
		canRotate = canRotate_;
		speed = speed_;
		originalLeftAngle = originalLeftAngle_;
		originalRightAngle = originalRightAngle_;
		wait = wait_;
		rotateLeftArm = rotateLeftArm_;
		health = health_;
		maxHealth = maxHealth_;
		weaknessCollision = weaknessCollision_;
		canon = canon_;
		canonTimer = canonTimer_;
		rotateTimer = rotateTimer_;
		bar = bar_;
		state = state_;
	}
};