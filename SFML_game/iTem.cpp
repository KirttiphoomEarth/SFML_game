#include "iTem.h"

iTem::iTem(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position, float speed):
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	body.setSize(sf::Vector2f(25.0f, 25.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
	faceRight = true;
	row = 0;
}

void iTem::Update(float deltaTime)
{
	velocity.x = speed;

	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void iTem::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void iTem::SetDestroy(bool isDestroy)
{
	this->isDestroyBool = isDestroy;
}
