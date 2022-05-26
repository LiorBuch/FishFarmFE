#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <SFML/Network.hpp>
class FoodChunk
{
public:
	FoodChunk(sf::Vector2f pos);
	~FoodChunk();

	void update();
	void draw(sf::RenderWindow& window);
	bool delThis();
private:
	sf::RectangleShape shape;
	sf::Texture texture;
	bool del = false;
};

