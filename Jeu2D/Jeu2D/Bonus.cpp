#include <iostream>
#include "BonusStr.h"

Bonus CreateBonus(enumBonus type, float effect)
{
	Bonus bonus;
	bonus.body = sf::CircleShape(15.f, 6);
	bonus.body.setPosition(sf::Vector2f(150.f, 360.f));//TEMPORAIRE

	bonus.type = type;
	bonus.effect = effect;
	 
	return bonus;
}

