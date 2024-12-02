#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
class state
{
protected:
	std::shared_ptr<sf::RenderWindow> window;
public:
	state(std::shared_ptr<sf::RenderWindow> window) : window(std::move(window)) {  }
	virtual ~state() = default;
	virtual void init() = 0;
	virtual void render(float dt) = 0;
	virtual void update(float dt) = 0;
	virtual void pause() { }
	virtual void resume() { }
	virtual bool getRunningStatus() = 0;
	virtual sf::RenderWindow* getWindow() = 0;
};

