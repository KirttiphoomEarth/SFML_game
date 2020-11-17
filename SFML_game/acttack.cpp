#include "acttack.h"
acttack::acttack(sf::Texture* texture, sf::Vector2u imageCount, float switchtime, float speed) :
	Animation(texture, imageCount, switchtime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(90.0f, 100.0f));
	body.setPosition(100.0f, 450.0f);
	body.setTexture(texture);
}

void acttack::Update(float deltaTime)
{
	
	sf::Vector2f attack(0.0f, 0.0f);
if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		attack.x = speed * deltaTime;

	if (attack.x == 0.0f)
	{
		row = 0;


	}
	else
	{
		row = 3;
	}
	






	Animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(Animation.uvRect);
	body.move(attack);



}

void acttack::Draw(sf::RenderWindow& window)
{

	window.draw(body);


}