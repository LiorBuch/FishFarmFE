#include "Fish.h"

Fish::Fish(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture,imageCount,switchTime)
{
	this->speed = speed;
	this->speedAMP = 1.f;
	row = 0;
	this->faceLeft = true;
	body.setSize(sf::Vector2f(470.f, 280.f));
	body.setPosition(300.f, 300.f);
	body.setScale(sf::Vector2f(0.5f, 0.5f));
	body.setTexture(texture);
}

Fish::Fish()
{
}

Fish::~Fish()
{
}

void Fish::update(float deltaTime)
{
	sf::Vector2f movment(0.0f, 0.0f);
	switchDirections(this->body.getPosition().x);

	if (this->faceLeft)
	{
		movment.x -= speed * deltaTime *speedAMP;
	}
	else
	{
		movment.x += speed * deltaTime *speedAMP;
	}

	if (movment.x < 0.0f)
	{
		this->faceLeft = true;
	}
	if(movment.x > 0.0f)
	{
		this->faceLeft = false;
	}
	animation.update(row, deltaTime, this->faceLeft);
	body.setTextureRect(animation.uvRect);
	body.move(movment);
}

void Fish::draw(sf::RenderWindow& window)
{
	window.draw(this->body);
}

void Fish::switchDirections(float pos)
{
	if (pos < -30)
	{
		randomAMP();
		this->faceLeft = false;
	}
	if (pos > 1100)
	{
		randomAMP();
		this->faceLeft = true;
	}
	
	
}

void Fish::randomAMP()
{
	float tmp = (rand() % 11) + 15;
	tmp = tmp / 22;
	this->speedAMP = tmp;
}
