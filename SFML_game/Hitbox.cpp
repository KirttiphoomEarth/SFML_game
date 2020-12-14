#include "Hitbox.h"


Hitbox::Hitbox(sf::Vector2f position)
{
	body.setSize(sf::Vector2f(40.0f, 50.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setFillColor(sf::Color::White);
}

void Hitbox::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Hitbox::Update(float deltaTime)
{

}

void Hitbox::OnCollision(sf::Vector2f direction)
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
