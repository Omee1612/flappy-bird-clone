#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "state.h"

class mainmenu : public state
{
private:
	sf::Sprite playbutton;
	sf::Sprite title;
	sf::Sprite bg;
	std::map<std::string,sf::Texture> textures;
	bool menuActive = true;
public:
	mainmenu(std::shared_ptr<sf::RenderWindow> window) : state(std::move(window)) { } 
	void loadTexture(const std::string& name, const std::string& fileName);
	sf::Texture& getTexture(const std::string& name);
	~mainmenu() override = default;
	bool isSpriteClicked(sf::Mouse::Button button, sf::Sprite object, sf::RenderWindow& window);
	void render(float dt) override;
	void update(float dt) override;
	sf::RenderWindow* getWindow() override
	{
		return this->window.get();
	}
	bool getRunningStatus() override;
	void init() override;
};

