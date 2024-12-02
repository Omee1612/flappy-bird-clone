#include "Collision.h"
bool Collision::isCollided(const sf::Sprite& object, const std::vector<sf::Sprite>& lands)
{
	for (const auto& land : lands)
		if (object.getGlobalBounds().intersects(land.getGlobalBounds()))
			return true;
	return false;
}