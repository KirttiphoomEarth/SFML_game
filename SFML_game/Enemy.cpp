#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position)

{
	this->hp = 150.0f;
	body.setSize(sf::Vector2f(40.0f, 50.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setFillColor(sf::Color::White);
	
	
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Enemy::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left.
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right.
		velocity.x = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top.
		velocity.y = 0.0f;
	}
}

void Enemy::setHp(float dmg)
{
	this->hp -= dmg;
}
