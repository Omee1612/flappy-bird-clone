#include <iostream>

#include "game.h"
#include "gameOver.h"
#include "mainmenu.h"
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(static_cast<unsigned>(std::time(0)));
    statemachine sm;
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(
	    sf::VideoMode(768, 1024), "Hi", sf::Style::Close | sf::Style::Titlebar);
    // Add the initial state
    window->setFramerateLimit(60);
    sm.addState(std::make_unique<mainmenu>(window));

    // Process the state to push it onto the stack
    sm.processState();

    // Ensure there is an active state before proceeding
    while (sm.getActiveState() && sm.getActiveState()->getWindow()->isOpen())
    {
        sm.processState();
        sf::Event event;
        while (sm.getActiveState()->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                sm.getActiveState()->getWindow()->close();
        }
        if(dynamic_cast<mainmenu*>(sm.getActiveState().get()) && !sm.getActiveState()->getRunningStatus())
        {
            sm.addState(std::make_unique<game>(window), true);
        }
        if (dynamic_cast<game*>(sm.getActiveState().get()) && !sm.getActiveState()->getRunningStatus())
        {
            std::cout << "Transitioning to gameOver state" << std::endl;
            sm.addState(std::make_unique<gameOver>(window), true);
        }

        float dt = 1.f / 60.f;
        sm.getActiveState()->update(dt);
        sm.getActiveState()->render(dt);
    }
}