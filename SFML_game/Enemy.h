#pragma once
#include<SFML/Graphics.hpp>
#include "Collider.h"
class Enemy
{
public :
	Enemy(sf::Vector2f position);
	void Draw(sf::RenderWindow &window);
	void OnCollision(sf::Vector2f direction);
	void setHp(float dmg);
	
	float GetHp() { return hp; }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

	

private :
	sf::RectangleShape body;
	sf::Vector2f velocity;
	float speed;
	float hp;
};

