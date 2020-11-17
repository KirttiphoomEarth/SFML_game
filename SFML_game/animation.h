#pragma once
#include<SFML\Graphics.hpp>
class animation
{
public:
	animation(sf::Texture* texture, sf::Vector2u imageCount, float switchtime);

	void Update(int row , float deltaTime, bool faceRight);


public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totaltime;
	float switchtime;


};