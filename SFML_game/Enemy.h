#pragma once
#include<SFML/Graphics.hpp>
#include "Collider.h"
#include "animation.h"
class Enemy
{
public :
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, float speed);
	void Draw(sf::RenderWindow &window);
	void Drawhitbox(sf::RenderWindow& window);
	void Update(float deltaTime);
	void OnCollision(sf::Vector2f direction);
	void setHp(float dmg);
	
	
	unsigned int row;
	bool faceRight;
	float GetHp() { return hp; }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	Collider GetColliderHitbox() { return Collider(bodyHitbox); }
	

private :
	sf::RectangleShape body;
	sf::RectangleShape bodyHitbox;
	sf::Vector2f velocity;
	animation Animation;
	
	float speed;
	float hp;
};

