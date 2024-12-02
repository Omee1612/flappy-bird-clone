#include "Pipe.h"

#include <iostream>

void Pipe::addBottomPipe()
{
	sf::Sprite sprite(this->getTexture("Pipeup"));
	sprite.setPosition(window->getSize().x, this->window->getSize().y - sprite.getGlobalBounds().height - randomOffset);
	pipes.push_back(sprite);
}

void Pipe::loadTexture(const std::string& name, const std::string& fileName)
{
	sf::Texture temp;
	if (!temp.loadFromFile(fileName)) std::cerr << "Error loading texture";
	textures[name] = temp;
}

sf::Texture& Pipe::getTexture(const std::string& name)
{
	return this->textures[name];
}

Pipe::Pipe(std::shared_ptr<sf::RenderWindow> window) : window(window)
{
	this->loadTexture("Pipeup", "Resources/res/PipeUp.png");
	this->loadTexture("Pipedown", "Resources/res/PipeDown.png");
	this->loadTexture("land", "Resources/res/Land.png");
	sf::Sprite land(this->getTexture("land"));
	landheight = this->getTexture("land").getSize().y;
}
void Pipe::randomiseOffsetY()
{
	randomOffset = rand() % (landheight + 1);
}

void Pipe::addTopPipe()
{
	sf::Sprite sprite(this->getTexture("Pipedown"));
	sprite.setPosition(window->getSize().x, -randomOffset);
	pipes.push_back(sprite);
}

void Pipe::addScoringPipe()
{

}

void Pipe::movePipe()
{
	for (int i = 0; i < pipes.size(); i++)
	{
		if (pipes.at(i).getPosition().x < 0 - pipes.at(i).getGlobalBounds().width)
		{
			pipes.erase(pipes.begin() + i);
		}
		else
		{
			float movement = 150.f * 1.f / 60.f;
			pipes.at(i).move(-movement, 0);
		}
	}
}

void Pipe::drawPipes()
{
	for (const auto& pipe : pipes)
	{
		window->draw(pipe);
	}
}

std::vector<sf::Sprite>& Pipe::getPipeSprites()
{
	return this->pipes;
}


