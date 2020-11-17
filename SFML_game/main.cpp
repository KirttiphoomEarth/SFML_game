#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include"Playerr.h"
#include "Platform.h"
#include "Collider.h"

static const float View_HEIGHT = 720.0f;
bool Retry(false);

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize((View_HEIGHT)*aspectRatio, View_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game Start!");
	//sf::RectangleShape background(sf::Vector2f(90.0f, 100.0f));
	//layer.setFillColor(sf::Color::Blue);
	//background.setPosition(100.0f, 450.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("warrior spritesheet calciumtrice.png");

	sf::Texture backgroundTexture;
	sf::Sprite background;
	sf::Vector2u TextureSize(1080, 720);  //Added to store texture size.
	sf::Vector2u WindowSize(1920, 1080);   //Added to store window size.
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(View_HEIGHT, View_HEIGHT));
	backgroundTexture.loadFromFile("zzbackground.png");
	if (!backgroundTexture.loadFromFile("zzbackground.png"))
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
	}



	Playerr player(&playerTexture, sf::Vector2u(10, 10), 0.1f, 100.0f, 200.0f);

	std::vector<Platform> platforms;

	platforms.push_back(Platform(nullptr, sf::Vector2f(3000.0f, 160.0f), sf::Vector2f(500.0f, 900.0f)));

	//Platform platformY(nullptr, sf::Vector2f(200.0f, 3000.0f), sf::Vector2f(1990.0f,1000.0f));

	float deltaTime = 0.0f;
	sf::Clock clock;


	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;
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
				break;
			
			}

			


		}
	
	
		
		player.Update(deltaTime);
		//Collider playerGetCollider = player.GetCollider();
		view.setCenter(player.GetPosition());
		Collider playerCollision = player.GetCollider(); // Dammit!!!!
		sf::Vector2f direction;

		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
				player.OnCollision(direction);




				//platformY.GetCollider().CheckCollision(playerGetCollider, direction, 1.0f);


	window.clear();
	window.draw(background);
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