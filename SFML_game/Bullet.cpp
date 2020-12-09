#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	body.setSize(sf::Vector2f(10.0f,10.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
	faceRight = true;

}

void Bullet::Update(float deltaTime)
{
	
	velocity.x = speed;

	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);

	
	
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
