#pragma once
#include <SFML/Graphics.hpp>
#include "animation.h"
#include "Collider.h"
class Playerr
{
public:
	Playerr(sf::Texture* texture, sf::Vector2u imageCount, float switchtime, float speed, float jumpHeight);

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
	animation Animation;
	unsigned int row;
	float speed;
	bool faceRight;
	
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};

