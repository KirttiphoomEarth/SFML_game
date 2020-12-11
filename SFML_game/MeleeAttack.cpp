#include "MeleeAttack.h"

MeleeAttack::MeleeAttack(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	this->dmg = 50.0f;
	body.setSize(sf::Vector2f(20.0f, 20.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setTexture(texture);
	faceRight = true;
}

void MeleeAttack::Update(float deltaTime)
{
	velocity.x = 0;

	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void MeleeAttack::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void MeleeAttack::SetDestroy(bool isDestroy)
{
	this->isDestroyBool = isDestroy;
}
