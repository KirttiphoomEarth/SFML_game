#pragma once
#include <SFML/Graphics.hpp>
#include "animation.h"
class acttack
{
public:
	acttack(sf::Texture* texture, sf::Vector2u imageCount, float switchtime, float speed);

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body;
	animation Animation;
	unsigned int row;
	float speed;
	bool faceRight;
};

