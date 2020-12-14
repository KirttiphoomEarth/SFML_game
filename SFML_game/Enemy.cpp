#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, float speed) :
	Animation(texture, imageCount, switchTime)

{
	this->speed = speed;
	this->hp = 150.0f;
	body.setSize(sf::Vector2f(40.0f, 50.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setFillColor(sf::Color::White);
	body.setTexture(texture);
	row = 0;
	velocity.x = speed;
	
	
}


void Enemy::Update(float deltaTime)
{
	if (velocity.x == 0.0f)
	{
		row = 0;


	}
	else
	{
		row = 2;


		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	Animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(Animation.uvRect);
	body.move(velocity * deltaTime);
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
		velocity.x *=-1.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right.
		velocity.x *= -1.0f;
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
