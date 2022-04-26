#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class Animation
{
public:
	Animation(sf::Texture* texture,sf::Vector2u imageCount , float switchTime);
	Animation();
	~Animation();

	void update(int row, float deltaTime, bool faceRight);

	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

