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

/*
	Class for Game Engine.
	Wrapper Class.
*/

class Game
{
private:
	//Vars.
	sf::Http http;
	nlohmann::json json;
	sf::Clock clock;
	float deltaTime;
	//Player currentPlayer;
	//Window.
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	Tank currentTank;
	//Game OBJ
	
	//Tank Properties
		//toolbar
	sf::Texture toolBarTexture;
	sf::Sprite toolBar;
		//cursor
	sf::Texture mouseCursor;
	sf::Sprite cursor;

	//Private functions.
	void initVars();
	void initWindow();
	void initFish();
	void initTank();
	void updateCuesor();


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
};

