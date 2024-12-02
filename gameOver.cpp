#include "gameOver.h"

#include <iostream>

#include "game.h"

gameOver::gameOver(std::shared_ptr<sf::RenderWindow> window) : state(std::move(window))
{

}

bool gameOver::getRunningStatus()
{
	return this->gameOverActive;
}

void gameOver::loadTexture(const std::string& name, const std::string& fileName)
{
	sf::Texture tex;
	if (!tex.loadFromFile(fileName))
	{
		std::cerr << "Error loading texture\n";
	}
	textures[name] = tex;
}


sf::Texture& gameOver::getTexture(const std::string& name)
{
	return this->textures[name];
}

void gameOver::init()
{
	this->loadTexture("background", "Resources/res/sky.png");
	this->loadTexture("gameOverTitle", "Resources/res/Game-Over-Title.png");
	gameOverSprite.setTexture(this->getTexture("gameOverTitle"));
	bg.setTexture(this->getTexture("background"));
	gameOverSprite.setPosition(window->getSize().x / 2 - gameOverSprite.getGlobalBounds().width / 2, window->getSize().y / 4);
	gameOverActive = true;
}

void gameOver::update(float dt)
{

}
void gameOver::render(float dt)
{
	window->clear();
	window->draw(bg);
	window->draw(gameOverSprite);
	window->display();
}
