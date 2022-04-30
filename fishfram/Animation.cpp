#include "Animation.h"

Animation::Animation(string texturePath, sf::Vector2u imageCount, float switchTime)
{
	this->texture.loadFromFile("assets/" + texturePath);
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	currentImage.x = 0;
	this->flipImage.x = 0;
	this->flipSwitch = switchTime / 6.f;
	uvRect.width =  this->texture.getSize().x / float(imageCount.x);
	uvRect.height = this->texture.getSize().y / float(imageCount.y);
	this->totalTime = 0;
}

Animation::Animation() {

}

Animation::~Animation()
{
}

void Animation::update(int row, float deltaTime, bool faceLeft)
{
	this->currentImage.y = row;
	this->totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >=imageCount.x)
		{
			currentImage.x = 0;
		}
	}

	uvRect.top = currentImage.y * uvRect.height;
	if (faceLeft)
	{
		uvRect.width = abs(uvRect.width);
		uvRect.left = currentImage.x * uvRect.width;
	}
	else
	{
		uvRect.left = (currentImage.x+1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}

void Animation::flipAnim(unsigned int& row, float deltaTime, bool faceLeft, bool& flip)
{
	this->currentImage.y = row;
	this->totalTime += deltaTime;

	if (totalTime >= flipSwitch)
	{
		totalTime -= flipSwitch;
		flipImage.x++;

		if (flipImage.x >= imageCount.x)
		{
			flipImage.x = 0;
			flip = false;
			row = 0;
		}
	}

	uvRect.top = currentImage.y * uvRect.height;
	if (faceLeft)
	{
		uvRect.width = abs(uvRect.width);
		uvRect.left = currentImage.x * uvRect.width;
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}
