#include <iostream>
#include "BonusStr.h"

Bonus CreateBonus(enumBonus type, float effect, sf::Vector2f position)
{
	Bonus bonus;
	bonus.body = sf::CircleShape(15.f, 6);
	bonus.body.setPosition(position);
	switch(type)
	{
		case enumBonus::AMMO:
			bonus.body.setFillColor(sf::Color::Green);
			break;
		case enumBonus::JUMP:
			bonus.body.setFillColor(sf::Color::Yellow);
			break;
		case enumBonus::SPEED:
			bonus.body.setFillColor(sf::Color::Blue);
			break;

	};

	bonus.type = type;
	bonus.effect = effect;

	return bonus;
}

