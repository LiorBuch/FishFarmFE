#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Animation.h"

class Fish
{
public:
	Fish(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	Fish();
	~Fish();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	float speedAMP;
	bool faceLeft;

	void switchDirections(float pos);
	void randomAMP();

};

