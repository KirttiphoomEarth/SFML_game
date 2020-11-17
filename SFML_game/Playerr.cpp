#include "Playerr.h"
Playerr::Playerr(sf::Texture* texture, sf::Vector2u imageCount, float switchtime, float speed, float jumpHeight) :
	Animation(texture, imageCount, switchtime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	

	body.setSize(sf::Vector2f(90.0f, 100.0f));
	body.setPosition(100, 700.0f);
	body.setOrigin(45, 50);
	body.setTexture(texture);
}

void Playerr::Update(float deltaTime)
{

	velocity.x *= 0.0f;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);

	}

	velocity.y += 981.0f * deltaTime;
	
	

	if (velocity.x == 0.0f)
	{
		row = 0;
		
	
	}
	else
	{
		row = 2;
		

		if (velocity.x > 0.0f )
			faceRight = true;
		else
			faceRight = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
	
		row = 3;
	}

	
	
		
	
	

	

	Animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(Animation.uvRect);
	body.move(velocity * deltaTime);
	



}

void Playerr::Draw(sf::RenderWindow& window)
{
	
		window.draw(body);
	

}

void Playerr::OnCollision(sf::Vector2f direction)
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
	if (direction.y < 0.0f)
	{
		//Collision on the bottom.
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top.
		velocity.y = 0.0f;
	}
}
