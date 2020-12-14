#include "boss.h"

boss::boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, float speed) :
	Animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->hp = 500.0f;
	body.setSize(sf::Vector2f(120.0f, 150.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setFillColor(sf::Color::White);
	body.setTexture(texture);
	bodyHitbox.setSize(sf::Vector2f(60.0f, 200.0f));
	bodyHitbox.setOrigin(body.getSize() / 2.0f);
	bodyHitbox.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y));
	bodyHitbox.setFillColor(sf::Color::White);
	row = 0;
	velocity.x = speed;
}

void boss::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void boss::Drawhitbox(sf::RenderWindow& window)
{
	window.draw(bodyHitbox);
}

void boss::Update(float deltaTime)
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
	bodyHitbox.setTextureRect(Animation.uvRect);
	bodyHitbox.move(velocity * deltaTime);
}

void boss::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left.
		velocity.x *= -1.0f;
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

void boss::setHp(float dmg)
{
	this->hp -= dmg;
}
