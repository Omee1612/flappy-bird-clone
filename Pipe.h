#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <map>
#include <cstdlib>
class Pipe
{
private:
	std::vector<sf::Sprite> pipes;
	std::map<std::string,sf::Texture> textures;
	std::shared_ptr<sf::RenderWindow> window;
	int landheight;
	int randomOffset;
public:
	Pipe(std::shared_ptr<sf::RenderWindow> window);
	~Pipe() = default;
	void addTopPipe();
	void addBottomPipe();
	void addScoringPipe();
	void randomiseOffsetY();
	void movePipe();
	void drawPipes();
	std::vector<sf::Sprite>& getPipeSprites();
	void loadTexture(const std::string& name, const std::string& fileName);
	sf::Texture& getTexture(const std::string& name);
};

