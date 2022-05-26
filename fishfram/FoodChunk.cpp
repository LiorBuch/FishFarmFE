#include "FoodChunk.h"

FoodChunk::FoodChunk(sf::Vector2f pos)
{
	this->shape.setPosition(pos);
	this->shape.setSize(sf::Vector2f(20.f, 20.f));
	this->texture.loadFromFile("assets/foodChunk.png");
	this->shape.setTexture(&this->texture);
}

FoodChunk::~FoodChunk()
{
}

void FoodChunk::update()
{
	this->shape.move(0, 0.3f);
	if (this->shape.getPosition().y > 630)
	{
		std::cout << "Kill" << std::endl;
		this->del = true;
	}
	
}

void FoodChunk::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
}

bool FoodChunk::delThis()
{
	return this->del;
}
