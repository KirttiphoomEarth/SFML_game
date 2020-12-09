#pragma once
#include<SFML/Graphics.hpp>
#include "animation.h"
class Bullet
{
public :
	Bullet(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,sf::Vector2f position,float speed);

	void Update(float switchTime);
	void Draw(sf::RenderWindow& window);
	void SetPosition(sf::Vector2f(position)) { body.setPosition(position); }
	float speed;


private :
	sf::RectangleShape body;
	sf::RectangleShape texture;
	animation animation;
	unsigned int row;
	sf::Vector2f velocity;
	bool faceRight;
};

