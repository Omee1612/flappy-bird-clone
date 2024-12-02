#pragma once
#include "game.h"

class Collision
{
public:
	Collision() = default;
	~Collision() = default;
	bool isCollided(const sf::Sprite& object, const std::vector<sf::Sprite>& lands);
};

