#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cassert>
#include <vector>
#include"Playerr.h"
#include "Platform.h"
#include "Collider.h"

static const float View_HEIGHT = 700.0f;
bool Retry(false);

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize((View_HEIGHT)*aspectRatio, View_HEIGHT);
}
void background()
{
	///////////////////////////////////////////// * BACKGROUND * /////////////////////////////////////////////
	/*sf::Texture backgroundTexture;
	sf::Sprite background;
	sf::Vector2u TextureSize(2048, 720);  //Added to store texture size.
	sf::Vector2u WindowSize(1024, 786);   //Added to store window size.
	backgroundTexture.loadFromFile("zzzzzzmap.png");                                      // 69 - 12 = 57// 57 - 12 = 45
	if (!backgroundTexture.loadFromFile("zzzzzzmap.png"))
	{
		return -1;
	}
	else
	{
		TextureSize = backgroundTexture.getSize(); //Get size of texture.
		WindowSize = window.getSize();             //Get size of window.k

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

		background.setTexture(backgroundTexture);
		background.setScale(ScaleX, ScaleY);      //Set scale.
	}*/
	///////////////////////////////////////////// * BACKGROUND * /////////////////////////////////////////////
}
void platforms()
{

}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 786), "Game Start!");
	sf::Texture playerTexture;
	playerTexture.loadFromFile("warrior spritesheet calciumtrice.png");
	Playerr player(&playerTexture, sf::Vector2u(10, 10), 0.1f, 100.0f, 200.0f);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(View_HEIGHT, View_HEIGHT));

	sf::Texture tex;
	sf::Sprite Backgroundack;
	assert(tex.loadFromFile("zmapeiei.png"));
	Backgroundack.setTexture(tex);

	///////////////////////////////////////////// พื้น platforms ปกติ //////////////////////////////////////////////////////
	std::vector<Platform> platforms;

	platforms.push_back(Platform(nullptr, sf::Vector2f(15.0f, 257.0f), sf::Vector2f(140.5f, 261.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(180.0f, 10.0f), sf::Vector2f(190.0f, 390.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(160.0f, 10.0f), sf::Vector2f(240.0f, 420.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(250.0f, 10.0f), sf::Vector2f(230.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(790.0f, 10.0f), sf::Vector2f(575.0f, 460.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 13.0f), sf::Vector2f(970.0f, 490.0f)));			// + 15 px
	platforms.push_back(Platform(nullptr, sf::Vector2f(380.0f, 21.0f), sf::Vector2f(1210.0f, 528.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(269.0f, 19.0f), sf::Vector2f(1238.5f, 405.5f)));			//เพดานอุโมงแรก
	platforms.push_back(Platform(nullptr, sf::Vector2f(88.0f, 10.0f), sf::Vector2f(1443.0f, 620.0f)));			//หนาม 1 
	//Platform platformY(nullptr, sf::Vector2f(200.0f, 3000.0f), sf::Vector2f(1990.0f,1000.0f));

	///////////////////////////////////////////// พื้น platforms ปกติ //////////////////////////////////////////////////////
	
	
	float deltaTime = 0.0f;
	sf::Clock clock;


	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 30.0f)
			deltaTime = 1.0f / 30.0f;
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			
			}
		}
			
		
	
		
		player.Update(deltaTime);
		//Collider playerGetCollider = player.GetCollider();
		view.setCenter(player.GetPosition());
		Collider playerCollision = player.GetCollider(); 
		sf::Vector2f direction;

		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
				player.OnCollision(direction);




				//platformY.GetCollider().CheckCollision(playerGetCollider, direction, 1.0f);

	window.clear(sf::Color(40, 37, 56));
	window.draw(Backgroundack);
	window.setView(view);
	player.Draw(window);
	for (Platform& platform : platforms)
		 platform.Draw(window);
	window.display();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) 
		{
			Retry = true;
		}
	if (Retry) 
		{
			window.close();
		}


	}

	
	return 0;
}