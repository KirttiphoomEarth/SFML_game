#pragma once
#include<SFML/Graphics.hpp>
#include "Collider.h"
class Enemy
{
public :
	Enemy(sf::Vector2f position);
	void Draw(sf::RenderWindow &window);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

	

private :
	sf::RectangleShape body;
	float speed;
};

