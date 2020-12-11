#pragma once
#include<SFML/Graphics.hpp>
#include "animation.h"
#include "Collider.h"
class MeleeAttack
{
public :
	MeleeAttack(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, float speed);

	void Update(float switchTime);
	void Draw(sf::RenderWindow& window);
	void SetPosition(sf::Vector2f(position)) { body.setPosition(position); }
	void SetDestroy(bool isDestroy);

	float GetDmg() { return dmg; }
	bool isDestroy() { return isDestroyBool; }
	float speed;
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
	sf::RectangleShape texture;
	animation animation;
	unsigned int row;
	sf::Vector2f velocity;
	bool faceRight;
	bool isDestroyBool;
	float dmg;
};

