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

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 786), "Game Start!");
	sf::Texture playerTexture;
	playerTexture.loadFromFile("warrior spritesheet calciumtrice.png");
	Playerr player(&playerTexture, sf::Vector2u(10, 10), 0.1f, 100.0f, 200.0f);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(View_HEIGHT, View_HEIGHT));

	sf::Texture tex;
	sf::Sprite Backgroundack;
	assert(tex.loadFromFile("zzzzzzmap.png"));
	Backgroundack.setTexture(tex);

	
	std::vector<Platform> platforms;

	platforms.push_back(Platform(nullptr, sf::Vector2f(3000.0f, 160.0f), sf::Vector2f(500.0f, 635.0f)));

	//Platform platformY(nullptr, sf::Vector2f(200.0f, 3000.0f), sf::Vector2f(1990.0f,1000.0f));

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
				//window size
				//std::cout<<"NEw window width:"<< evnt.size.width << "New window height" << evnt.size.height << std::endl;
				
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
	/*for (Platform& platform : platforms)
		 platform.Draw(window);*/
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