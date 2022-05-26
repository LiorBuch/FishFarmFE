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
class Button
{
public:
	Button(float x,float y ,float width , float height,sf::Texture texture, string hover);
	Button();
	~Button();

	void render(sf::RenderTarget* target);
	void update(sf::Vector2f mousePos);
	bool isPressed();
	void resetPress();

private:
	bool pressed;
	sf::RectangleShape shape;
	sf::Texture hover;
};

