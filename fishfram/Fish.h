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
	Fish(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float xPos, float yPos, float sizeWidth, float sizeHeight);
	Fish();
	~Fish();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body;
	sf::Clock cooldown;
	Animation animation;
	unsigned int row;
	float speed;
	float speedAMP;
	float speedYAMP;
	bool faceLeft;
	int faceUp;
	bool flip;
	float switchTime;

	void switchDirections(sf::Vector2f pos, float deltaTime);
	void randomAMP();
	void randomAngel();

};

