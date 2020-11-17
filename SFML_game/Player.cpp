#include "Player.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchtime, float speed)
	Animation(texture, imageCount, switchtime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(90.0f, 100.0f));
	body.setPosition(100.0f, 450.0f);
	body.setTexture(texture);
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;

	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;

		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	Animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(Animation.uvRect);
	body.move(movement);
 }

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

