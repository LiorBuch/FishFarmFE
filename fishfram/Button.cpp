#include "Button.h"


Button::Button(float x, float y, float width, float height, sf::Texture texture, string hover)
{
	this->shape.setPosition(x, y);
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setTexture(&texture);
	this->hover.loadFromFile(hover);
	this->pressed = false;
}

Button::Button()
{
}

Button::~Button()
{
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Button::update(sf::Vector2f mousePos)
{
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->pressed = true;
		}
	}
}

bool Button::isPressed()
{
	return this->pressed;
}

void Button::resetPress()
{
	this->pressed = false;
}
