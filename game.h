#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <map>
#include <vector>
#include "state.h"
#include "statemachine.h"
#include "Pipe.h"

class game : public state
{
	enum birdState
	{
		BIRD_STATE_FALLING,
		BIRD_STATE_FLYING
	};
public:
	game(std::shared_ptr<sf::RenderWindow> window);
	~game() override = default;
	void loadTextures(std::string name, std::string fileName);
	sf::Texture& getTexture(std::string name);
	 void update(float dt) override;
	 void render(float dt) override;
	bool getRunningStatus() override;
	void init() override;
	void Fly();
	void birdFalling();
	sf::RenderWindow* getWindow() override
	{
		return this->window.get();
	}
	void animate();
private:
	sf::Sprite bird;
	float rotation;
	float dt = 1.f/60.f;
	sf::Clock birdStateClock;
	sf::Clock pipeClock;
	sf::Clock clock;
	bool flyingPressed=false;
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	std::vector<sf::Texture> frames;
	bool gameActive;
	std::vector<sf::Sprite> lands;
	statemachine machine;
	int birdState;
	sf::Sprite background;
	unsigned int iterator;
	std::shared_ptr<Pipe> pipe;
};

