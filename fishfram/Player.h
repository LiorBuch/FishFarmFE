#pragma once
#include <SFML/Network.hpp>
#include <sstream>
#include <string>
#include <json.hpp>

class Player
{
public:
	Player();
	Player(std::string playerTOKEN);
	~Player();
	void loadPlayer();

private:
	std::string TOKEN;
	int numberOFTanks;
	int xp;
	sf::Http http;
	sf::Http::Request request;
};

