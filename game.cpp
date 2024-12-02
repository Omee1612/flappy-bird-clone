#include "game.h"

#include <iostream>
#include <memory>

#include "Collision.h"

void game::loadTextures(std::string name, std::string fileName)
{
	sf::Texture tex;
	if (!tex.loadFromFile(fileName)) std::cerr << "Error loading texture";
	textures[name] = tex;
}

sf::Texture& game::getTexture(std::string name)
{
	return this->textures.at(name);
}

bool game::getRunningStatus()
{
	return this->gameActive;
}


void game::init()
{
	iterator = 0;
	this->loadTextures("bird1", "Resources/res/bird-01.png");
	this->loadTextures("bird2", "Resources/res/bird-02.png");
	this->loadTextures("bird3", "Resources/res/bird-03.png");
	this->loadTextures("bird4", "Resources/res/bird-04.png");
	this->loadTextures("land", "Resources/res/land.png");
	this->loadTextures("background", "Resources/res/sky.png");
	background.setTexture(this->getTexture("background"));
	frames.push_back(this->getTexture("bird1"));
	frames.push_back(this->getTexture("bird2"));
	frames.push_back(this->getTexture("bird3"));
	frames.push_back(this->getTexture("bird4"));
	sf::Sprite land;
	land.setTexture(this->getTexture("land"));
	land.setPosition(0, window->getSize().y - land.getGlobalBounds().height);
	sf::Sprite land2 = land;
	land2.setTexture(this->getTexture("land"));
	land2.setPosition(land.getGlobalBounds().width, window->getSize().y - land.getGlobalBounds().height);
	lands.push_back(land);
	lands.push_back(land2);
	gameActive = true;
	bird.setPosition(window->getSize().x / 4, window->getSize().y / 2 - bird.getLocalBounds().height);
	birdState = BIRD_STATE_FALLING;
	pipe = std::make_shared<Pipe>(window);
}


game::game(std::shared_ptr<sf::RenderWindow> window) : state(std::move(window))
{
	game::init();
}
void game::birdFalling()
{
	if (birdState == BIRD_STATE_FALLING)
	{
		sf::Vector2f fallSpeed(0, 8.f);
		bird.move(fallSpeed);
		rotation += 100.f * dt;
		if (rotation > 45.f) rotation = 45.f;
		bird.setRotation(rotation);
	}
	else if (birdState == BIRD_STATE_FLYING)
	{
		bird.move(0, -6.f);
		rotation -= 100.f * dt;
		if (rotation < -45.f) rotation = -45.f;
		bird.setRotation(rotation);
	}
	if (birdStateClock.getElapsedTime().asSeconds() > 0.25f)
	{
		birdStateClock.restart();
		birdState = BIRD_STATE_FALLING;
	}
}
void game::Fly()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (!flyingPressed)
		{
			birdState = BIRD_STATE_FLYING;
			flyingPressed = true;
			birdStateClock.restart();
		}
	}
	else
	{
		flyingPressed = false;
	}
}
void game::animate()
{
	if (clock.getElapsedTime().asSeconds() > 0.4f / frames.size())
	{
		if (iterator < frames.size() - 1)
		{
			iterator++;
		}
		else iterator = 0;
		bird.setTexture(frames.at(iterator));
		clock.restart();
	}
}

void game::update(float dt)
{
	animate();
	birdFalling();
	Fly();
	if(pipeClock.getElapsedTime().asSeconds() > 1.1f)
	{
		pipe->addBottomPipe();
		pipe->addTopPipe();
		pipe->randomiseOffsetY();
		pipeClock.restart();
	}
	pipe->movePipe();
	Collision colChecker;
	if (colChecker.isCollided(bird, lands) || colChecker.isCollided(bird,pipe->getPipeSprites()))
	{
		gameActive = false;
	}
}

void game::render(float dt)
{
	window->clear();
	window->draw(background);
	window->draw(bird);
	for (auto& sprite : lands) window->draw(sprite);
	pipe->drawPipes();
	window->display();
}




