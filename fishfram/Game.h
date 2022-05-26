#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <SFML/Network.hpp>
#include <sstream>
#include <string>
#include <json.hpp>
#include "Fish.h"
#include "Tank.h"
#include "Player.h"
#include "Button.h"
#include "FoodChunk.h"

/*
	Class for Game Engine.
	Wrapper Class.
*/

class Game
{
private:
	//Vars.
	string TOKEN = "59704ed4-d6c3-4e21-b69e-0d5865179603";

	sf::Http http;
	nlohmann::json json;
	sf::Clock clock;
	sf::Clock clickCooldown;
	float deltaTime;
	std::list<std::shared_ptr<FoodChunk>> foodList;

	sf::Texture foodButtonTexture;
	sf::Texture foodButtonTextureHover;
	Button foodButton;
	sf::Texture defaultButtonTexture;
	sf::Texture defaultButtonTextureHover;
	Button defaultCursor;
	
	Player currentPlayer;
	//Window.
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	Tank currentTank;

	sf::Texture toolBarTexture;
	sf::Sprite toolBar;
	//cursors
	string cursorStatus;
	sf::Texture mouseCursor;
	sf::Sprite cursor;

	//Private functions.
	void initVars();
	void initWindow();
	void initFish();
	void initTank();
	


public:
	//constructos and destructors.
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	
	//Functions.
	void pollEvents();
	void update();
	void render();
	void updateCursor();
};

