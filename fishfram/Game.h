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
	//Window.
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	//Game OBJ
	
	//Tank Properties
		//wallpaper
	sf::Texture wallPaperTexture;
	sf::Sprite tankWallpaper;
		//toolbar
	sf::Texture toolBarTexture;
	sf::Sprite toolBar;
		//gravel
	sf::Texture gravelTexture;
	sf::Sprite gravel;

	//Fish
		//fish1
	sf::Texture fishTexture;
	Fish fish1;

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
};

