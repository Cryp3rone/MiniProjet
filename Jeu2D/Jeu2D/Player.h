#pragma once
#include <SFML/Graphics.hpp>
#include "LevelGenerator.h"
#include "PlayerStr.h"
#include <list>
#include "Shoot.h"
#include "GameState.h"

const float originalGroundY = 475.f;
const float speed = 400.f;
const float jumpForce = -8.f;
const sf::Vector2f gravity(0.f, 9.8f);

Player newPlayer();

void MovePlayer(Player&, float, sf::Vector2f&,sf::View& view,World* world, std::list<Bullet> bullets, GameState& state);

bool isGrounded(Player&,World*);
bool isOnFloor(Player&);