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

	::Boss& operator=(Boss boss);

	Boss();
	Boss(sf::CircleShape head,bool canRotate,int speed,float originalLeftAngle,float originalRightAngle,bool wait,bool rotateLeftArm,int health,int maxHealth,sf::CircleShape weaknessCollision,sf::RectangleShape canon,Timer* canonTimer,Timer* rotateTimer,HealthBar bar,BossState state);
};