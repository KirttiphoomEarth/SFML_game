#include "Playerr.h"
Playerr::Playerr(sf::Texture* texture, sf::Vector2u imageCount, float switchtime, float speed, float jumpHeight) :
	Animation(texture, imageCount, switchtime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	hp = 100;
	attckCheck = false;


	body.setSize(sf::Vector2f(40.0f, 50.0f));
	//body.setPosition(3800.0f, 200.0f);
	body.setPosition(200.0f, 200.0f);
	body.setOrigin(body.getSize()/2.0f);
	body.setTexture(texture);

	
}

void Playerr::Update(float deltaTime)
{
	
	//velocity.x *= 0.45f; // ใช้จริง
	velocity.x *= 0.7f;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x *= 1.0f;
		velocity.x += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x *= 1.0f;
		velocity.x -= speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrt(1.5f * 981.0f * jumpHeight);

	}
	

	//velocity.y += 981.0f * deltaTime;
	//velocity.y += 1450.0f * deltaTime; // ใช้จริง
	velocity.y += 800.0f * deltaTime;
	

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{

		row = 3;

	}
	
	//if (body.getPosition().x > 1410.0f && body.getPosition().x < 1475.0f && body.getPosition().y == 590.0f) { row = 4; body.setPosition(sf::Vector2f(8000.0f, 570.0f)); }
	//x == 2899 168
	
	/*if (body.getPosition().x > 2900.0f && body.getPosition().x < 3660.0f)
	{
		velocity.y += 1850.0f * deltaTime;
	}*/
	if (body.getPosition().x > 166.0f && body.getPosition().x < 169 && sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		body.setPosition(3800.0f,200.0f);
	}
	

	Animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(Animation.uvRect);
	body.move(velocity * deltaTime);

	//printf("x == %.2f   y === %.2f\n", body.getPosition().x, body.getPosition().y);


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