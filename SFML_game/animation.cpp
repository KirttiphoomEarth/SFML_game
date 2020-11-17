#include "animation.h"


animation::animation(sf::Texture* texture, sf::Vector2u imageCount, float switchtime)
{
	this->imageCount = imageCount;
	this->switchtime = switchtime;
	totaltime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}


void animation::Update(int row , float deltaTime, bool faceRight)
{
	currentImage.y = row;
	totaltime += deltaTime;

	if (totaltime >= switchtime)
	{
		totaltime -= switchtime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	
	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else 
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}
