#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position)

{
	body.setSize(sf::Vector2f(40.0f, 50.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position);
	body.setFillColor(sf::Color::White);

}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
