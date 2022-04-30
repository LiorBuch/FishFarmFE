#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Animation.h"
#include "Fish.h"
#include <list>
#include <json.hpp>
#include <string>


class Tank
{
public:
	Tank(int numberDecoration , int numberFish, nlohmann::json json, float deltaTime);
	Tank();
	~Tank();

	void changeDecoration();
	void changeFish();
	void update(float delta);
	void initFish();
	void initDecoration();
	void draw(sf::RenderWindow& window);

private:
	string tankLoc;
	int numberOfFish;
	int numberOfDecorations;
	int maxSize;
	float deltaTime;
	nlohmann::json props;
	sf::Http tankHttp;
	std::list<std::shared_ptr<Fish>> fishList;
	//wallpaper
	sf::Texture wallPaperTexture;
	sf::Sprite tankWallpaper;
	//toolbar
	sf::Texture toolBarTexture;
	sf::Sprite toolBar;
	//gravel
	sf::Texture gravelTexture;
	sf::Sprite gravel;
	
};

