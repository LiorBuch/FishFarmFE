#include "Fish.h"
using namespace std;

Fish::Fish(string texturePath, sf::Vector2u imageCount, float switchTime, float speed,float xPos,float yPos,float sizeWidth, float sizeHeight, unsigned int num) :
	animation(texturePath,imageCount,switchTime)
{
	this->fishTexture.loadFromFile("assets/" + texturePath);
	this->speed = speed;
	this->speedAMP = 1.f;
	this->speedYAMP = 1.f;
	this->switchTime = switchTime;
	this->row = 0;
	this->faceUp = 1;
	this->faceLeft = true;
	this->flip = false;
	body.setSize(sf::Vector2f(sizeWidth,sizeHeight));
	body.setPosition(xPos, yPos);
	body.setScale(sf::Vector2f(0.5f, 0.5f));
	body.setTexture(&fishTexture);
	this->body.setOrigin(20.f, 20.f);
	this->cooldown.getElapsedTime().asSeconds() + 2;
}

Fish::Fish()
{
}

Fish::~Fish()
{
}

void Fish::update(float deltaTime)
{
	sf::Vector2f movment(0.0f,0.0f);
	switchDirections(this->body.getPosition(),deltaTime);
	if(!this->flip)
	{
		if (this->faceLeft)
		{
			movment.x -= speed * deltaTime *speedAMP;
			movment.y = speed * deltaTime *speedYAMP * faceUp * 0.1f;
		}
		else
		{
			movment.x += speed * deltaTime *speedAMP;
			movment.y = speed * deltaTime * speedYAMP * faceUp * 0.1f;
		}
		if (movment.x < 0.0f)
		{
			this->faceLeft = true;
		}
		if(movment.x > 0.0f)
		{
			this->faceLeft = false;
		}
		if (movment.y ==0)
		{
			body.setRotation(0);
		}
		else
		{
			body.setRotation(atan(movment.x / movment.y)*2.f);
		}
		
		animation.update(row, deltaTime, this->faceLeft);
	}
	else
	{
		animation.flipAnim(this->row, deltaTime, this->faceLeft, this->flip);
	}
	body.setTextureRect(animation.uvRect);
	body.move(movment);

}

void Fish::draw(sf::RenderWindow& window)
{
	window.draw(this->body);
}

void Fish::switchDirections(sf::Vector2f pos, float deltaTime)
{
	if (this->cooldown.getElapsedTime().asSeconds() >=2)
	{
		
		if (pos.x < -30)
		{
			randomAMP();
			randomAngel();
			this->faceLeft = false;
			this->flip = true;
			this->row = 2;
			this->cooldown.restart().asSeconds();
		}
		if (pos.x > 1100)
		{
			randomAMP();
			randomAngel();
			this->faceLeft = true;
			this->flip = true;
			this->row = 1;
			this->cooldown.restart().asSeconds();
		}
	}
	if (pos.y <40)
	{
		faceUp = 1;
	}
	if (pos.y >630)
	{
		faceUp = -1;
	}
}

void Fish::randomAMP()
{
	float tmp = (rand() % 11) + 15;
	tmp = tmp / 22;
	this->speedAMP = tmp;
}

void Fish::randomAngel()
{
	float tmp = (rand() % 30) -15;
	tmp = tmp / 10;
	this->speedYAMP = tmp;
}
