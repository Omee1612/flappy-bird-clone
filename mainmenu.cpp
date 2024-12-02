#include "mainmenu.h"

#include <iostream>

#include "game.h"

void mainmenu::loadTexture(const std::string& name, const std::string& fileName)
{
	sf::Texture temp;
	if (!temp.loadFromFile(fileName)) std::cerr << "Error loading texture";
	textures[name] = temp;
}

sf::Texture& mainmenu::getTexture(const std::string& name)
{
	return this->textures[name];
}


void mainmenu::init()
{
	this->loadTexture("playBtn", "Resources/res/PlayButton.png");
	this->loadTexture("Title", "Resources/res/title.png");
	this->loadTexture("Background", "Resources/res/sky.png");
	playbutton.setTexture(getTexture("playBtn"));
	bg.setTexture(getTexture("Background"));
	title.setTexture(getTexture("Title"));
	title.setPosition(window->getSize().x / 2 - title.getGlobalBounds().width / 2, title.getGlobalBounds().height);
	playbutton.setPosition(window->getSize().x / 2 - playbutton.getGlobalBounds().width / 2,
	                       window->getSize().y / 2 - playbutton.getGlobalBounds().height / 2);
}

bool mainmenu::isSpriteClicked(sf::Mouse::Button button, sf::Sprite object, sf::RenderWindow& window)
{
	if(sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect playRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
		if(playRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}

bool mainmenu::getRunningStatus()
{
	return this->menuActive;
}


void mainmenu::update(float dt)
{
	if (isSpriteClicked(sf::Mouse::Left, playbutton, *this->window))
	{
		menuActive = false;
	}
}

void mainmenu::render(float dt)
{
	window->clear();
	window->draw(bg);
	window->draw(title);
	window->draw(playbutton);
	window->display();
}


