#pragma once
#include <SFML/Graphics.hpp>

#include "state.h"

class gameOver : public state
{
public:
	gameOver(std::shared_ptr<sf::RenderWindow> window);
	~gameOver() override = default;
	bool getRunningStatus() override;
	sf::RenderWindow* getWindow() override
	{
		return this->window.get();
	}
	void init() override;
	void render(float dt) override;
	void loadTexture(const std::string& name,const std::string& fileName);
	sf::Texture& getTexture(const std::string& name);
	void update(float dt) override;
private:
	std::map<std::string,sf::Texture> textures;
	sf::Sprite gameOverSprite;
	sf::Sprite bg;
	bool gameOverActive = false;
};

