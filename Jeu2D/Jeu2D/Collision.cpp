#pragma once
#include "Player.h"


void OnCollision(Player& player, sf::Shape& shape, bool isEnnemy) {
	if (!isEnnemy) {
		player.mooveX = false;
	}
}