#pragma once
#include<SFML/Graphics.hpp>
#include "Collider.h"
class Hitbox
{
public :
	Hitbox(sf::Vector2f position);
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
	void OnCollision(sf::Vector2f direction);
	
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

private :
	sf::RectangleShape body;
	sf::Vector2f velocity;
	float speed;
	float hp;
};

