#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cassert>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "Playerr.h"
#include "Platform.h"
#include "Collider.h"
#include "Enemy.h"
#include "Bullet.h" 
#include "MeleeAttack.h"
#include "Hitbox.h"
#include "boss.h"
#include "iTem.h"

static const float View_HEIGHT = 550.0f;
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
	srand(time(NULL));
	int playerHP = 3;
	int skill = 5;
	int scocr = 0;
	int i;
	int j;
	int Checkitem = 5;
	int enemiesSpeed = 50;
	int item_random;
	bool enemiesdid = false;
	bool item_drop;
	float enemiesX;
	float enemiesY;
	
	std::vector<Platform> platforms;
	std::vector<Platform> platformsEnemiesCheck;
	std::vector<Bullet> bullets;
	std::vector<MeleeAttack> meleeattacks;
	std::vector<Enemy> enemies;
	std::vector<Playerr> players;
	std::vector<boss> bosse;
	std::vector<iTem> items;
	std::vector<iTem> items1;
	std::vector<iTem> items2;
	//std::vector<Hitbox> enemiesHitbox;
	//std::vector<Hitbox> hitbox;
	
	sf::RenderWindow window(sf::VideoMode(1024, 786), "Game Start!");
	sf::Texture playerTexture;
	sf::Texture enemiesTexture;
	sf::Texture bosseTexture;
	sf::Texture bulletTextureLeft;
	sf::Texture bulletTextureRight;
	sf::Texture meleeattacksTexture;
	sf::Texture itemTexture;
	sf::Texture Heart;
	sf::Texture skillswords;
	sf::Font font;

	font.loadFromFile("Icey_3dpixel.ttf");
	playerTexture.loadFromFile("warrior spritesheet calciumtrice.png");
	enemiesTexture.loadFromFile("zrogue spritesheet calciumtrice.png");
	bulletTextureLeft.loadFromFile("zzsword.png");
	bulletTextureRight.loadFromFile("skillsword.png");
	itemTexture.loadFromFile("zzzcoine.png");
	Heart.loadFromFile("zheart.png");
	skillswords.loadFromFile("sword.png");
	
	Playerr player(&playerTexture, sf::Vector2u(10, 10), 0.09f, 100.0f, 200.0f);
	sf::RectangleShape hitboxBody;

	sf::RectangleShape heart;
	heart.setTexture(&Heart);
	heart.setSize(sf::Vector2f(30.0f, 35.0f));

	sf::RectangleShape skillsword;
	skillsword.setTexture(&skillswords);
	skillsword.setSize(sf::Vector2f(35,40));

	sf::Texture tex;
	sf::Sprite Backgroundack;
	assert(tex.loadFromFile("zmapeiei.png"));
	Backgroundack.setTexture(tex);


	sf::Text playerhp;
	playerhp.setFont(font);
	playerhp.setCharacterSize(42);

	sf::Text skills;
	skills.setFont(font);
	skills.setCharacterSize(42);

	sf::Text scors;
	scors.setFont(font);
	scors.setCharacterSize(42);

	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(View_HEIGHT, View_HEIGHT));
	

	///////////////////////////////////////////// พื้น platforms ปกติ //////////////////////////////////////////////////////
	platforms.push_back(Platform(nullptr, sf::Vector2f(15.0f, 257.0f), sf::Vector2f(140.5f, 261.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(180.0f, 10.0f), sf::Vector2f(190.0f, 390.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(160.0f, 10.0f), sf::Vector2f(240.0f, 420.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(250.0f, 10.0f), sf::Vector2f(230.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(790.0f, 10.0f), sf::Vector2f(575.0f, 460.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 13.0f), sf::Vector2f(970.0f, 490.0f)));			// + 15 px
	platforms.push_back(Platform(nullptr, sf::Vector2f(380.0f, 21.0f), sf::Vector2f(1210.0f, 528.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(36.0f, 18.0f), sf::Vector2f(944.0f, 207.0f)));           //มุด
	platforms.push_back(Platform(nullptr, sf::Vector2f(36.0f, 18.0f), sf::Vector2f(962.0f, 233.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(36.0f, 18.0f), sf::Vector2f(981.0f, 257.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(36.0f, 18.0f), sf::Vector2f(1004.0f, 282.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(36.0f, 18.0f), sf::Vector2f(1029.0f, 307.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(36.0f, 18.0f), sf::Vector2f(1053.0f, 332.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(36.0f, 18.0f), sf::Vector2f(1100.0f, 384.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(36.0f, 18.0f), sf::Vector2f(1076.0f, 357.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(177.0f, 25.0f), sf::Vector2f(285.0f, 125.0f)));			//เพดานเกิด
	platforms.push_back(Platform(nullptr, sf::Vector2f(105.0f, 22.0f), sf::Vector2f(399.0f, 155.0f)));			//เพดานเกิด
	platforms.push_back(Platform(nullptr, sf::Vector2f(541.0f, 22.0f), sf::Vector2f(640.0f, 180.0f)));			//เพดานเกิด
	platforms.push_back(Platform(nullptr, sf::Vector2f(269.0f, 19.0f), sf::Vector2f(1238.5f, 405.5f)));			//เพดานอุโมงแรก
	platforms.push_back(Platform(nullptr, sf::Vector2f(88.0f, 10.0f), sf::Vector2f(1443.0f, 620.0f)));			//หนาม 1 
	platforms.push_back(Platform(nullptr, sf::Vector2f(74.0f, 9.0f), sf::Vector2f(1549.0f, 622.5f)));			//หนาม 2 
	platforms.push_back(Platform(nullptr, sf::Vector2f(74.0f, 9.0f), sf::Vector2f(1660.0f, 622.5f)));			//หนาม 3
	platforms.push_back(Platform(nullptr, sf::Vector2f(74.0f, 9.0f), sf::Vector2f(1765.0f, 622.5f)));			//หนาม 4
	platforms.push_back(Platform(nullptr, sf::Vector2f(74.0f, 9.0f), sf::Vector2f(1877.0f, 622.5f)));			//หนาม 5
	platforms.push_back(Platform(nullptr, sf::Vector2f(74.0f, 9.0f), sf::Vector2f(1985.0f, 622.5f)));			//หนาม 6
	platforms.push_back(Platform(nullptr, sf::Vector2f(74.0f, 9.0f), sf::Vector2f(2096.0f, 622.5f)));			//หนาม 7
	platforms.push_back(Platform(nullptr, sf::Vector2f(1750.62f, 9.0f), sf::Vector2f(2903.0f, 622.5f)));		//หนาม 8
	platforms.push_back(Platform(nullptr, sf::Vector2f(47.0f, 21.0f), sf::Vector2f(1493.5f, 522.5f)));			// พื้นบนเสา 1
	platforms.push_back(Platform(nullptr, sf::Vector2f(47.0f, 21.0f), sf::Vector2f(1714.5f, 525.5f)));			// พื้นบนเสา 2
	platforms.push_back(Platform(nullptr, sf::Vector2f(47.0f, 21.0f), sf::Vector2f(1932.5f, 525.5f)));			// พื้นบนเสา 3
	platforms.push_back(Platform(nullptr, sf::Vector2f(47.0f, 21.0f), sf::Vector2f(2150.5f, 522.5f)));			// พื้นบนเสา 4
	platforms.push_back(Platform(nullptr, sf::Vector2f(47.0f, 21.0f), sf::Vector2f(2370.5f, 522.5f)));			// พื้นบนเสา 5
	platforms.push_back(Platform(nullptr, sf::Vector2f(47.0f, 21.0f), sf::Vector2f(2590.5f, 522.5f)));			// พื้นบนเสา 6
	platforms.push_back(Platform(nullptr, sf::Vector2f(2.0f, 30.0f), sf::Vector2f(2785.5f, 555.5f)));			// พื้นบนเสา 7
	platforms.push_back(Platform(nullptr, sf::Vector2f(2.5f, 84.0f), sf::Vector2f(1494.5f, 579.5f)));			// เสาตั้ง1
	platforms.push_back(Platform(nullptr, sf::Vector2f(2.5f, 84.0f), sf::Vector2f(1713.5f, 579.5f)));			// เสาตั้ง2
	platforms.push_back(Platform(nullptr, sf::Vector2f(2.5f, 84.0f), sf::Vector2f(1931.5f, 585.5f)));			// เสาตั้ง3
	platforms.push_back(Platform(nullptr, sf::Vector2f(2.5f, 84.0f), sf::Vector2f(2150.5f, 582.5f)));			// เสาตั้ง4
	platforms.push_back(Platform(nullptr, sf::Vector2f(2.5f, 84.0f), sf::Vector2f(2371.5f, 582.5f)));			// เสาตั้ง5
	platforms.push_back(Platform(nullptr, sf::Vector2f(2.5f, 84.0f), sf::Vector2f(2589.5f, 582.5f)));			// เสาตั้ง6
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.2f, 15.0f), sf::Vector2f(1603.0f, 454.0f)));			//หนาม เสา 1 
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.2f, 15.0f), sf::Vector2f(1826.0f, 454.0f)));			//หนาม เสา 2
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.2f, 15.0f), sf::Vector2f(2044.0f, 454.0f)));			//หนาม เสา 3
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.2f, 15.0f), sf::Vector2f(2263.0f, 454.0f)));			//หนาม เสา 4 
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.2f, 15.0f), sf::Vector2f(2482.0f, 454.0f)));			//หนาม เสา 5	
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.2f, 15.0f), sf::Vector2f(2704.0f, 450.0f)));			//หนาม เสา 6
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.2f, 157.0f), sf::Vector2f(1605.0f, 545.5f)));			//เสาตั้งหนาม 1
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.2f, 157.0f), sf::Vector2f(1824.0f, 545.5f)));			//เสาตั้งหนาม 2
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.2f, 157.0f), sf::Vector2f(2043.0f, 545.5f)));			//เสาตั้งหนาม 3
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.2f, 157.0f), sf::Vector2f(2262.0f, 545.5f)));			//เสาตั้งหนาม 4
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.2f, 157.0f), sf::Vector2f(2481.0f, 545.5f)));			//เสาตั้งหนาม 5
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.2f, 157.0f), sf::Vector2f(2703.0f, 545.5f)));			//เสาตั้งหนาม 6
	platforms.push_back(Platform(nullptr, sf::Vector2f(5.0f, 21.0f), sf::Vector2f(2869.5f, 527.5f)));			// ลอย 1
	platforms.push_back(Platform(nullptr, sf::Vector2f(2.0f, 15.0f), sf::Vector2f(2945.5f, 570.5f)));			// ลอย 2 แตก
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3020.5f, 577.5f)));			// ลอย 3
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3104.5f, 577.5f)));			// ลอย 4
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3165.5f, 577.5f)));			// ลอย 5 แตก
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3234.5f, 578.5f)));			// ลอย 6
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3317.5f, 578.5f)));			// ลอย 7
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3391.5f, 578.5f)));			// ลอย 8
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3475.5f, 578.5f)));			// ลอย 9
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3533.5f, 573.5f)));			// ลอย 10
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3584.5f, 577.5f)));			// ลอย 11
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3645.5f, 555.5f)));			// ลอย 12
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3695.5f, 512.5f)));			// ลอย 13
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3750.5f, 443.5f)));			// ลอย 14
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3685.5f, 395.5f)));			// ลอย 15
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3750.5f, 346.5f)));			// ลอย 16
	platforms.push_back(Platform(nullptr, sf::Vector2f(1.5f, 15.0f), sf::Vector2f(3685.5f, 297.5f)));			// ลอย 15
	platforms.push_back(Platform(nullptr, sf::Vector2f(20.0f, 18.0f), sf::Vector2f(1370.0f, 394.0f)));			// เพดานเสากระโดด
	platforms.push_back(Platform(nullptr, sf::Vector2f(1390.0f, 12.0f), sf::Vector2f(2146.0f, 315.0f)));		// เพดานเสากระโดด
	platforms.push_back(Platform(nullptr, sf::Vector2f(42.0f, 12.0f), sf::Vector2f(2863.0f, 311.0f)));		// อุโมงก่อนหนาม
	platforms.push_back(Platform(nullptr, sf::Vector2f(42.0f, 12.0f), sf::Vector2f(2897.0f, 343.0f)));		// อุโมงก่อนหนาม
	platforms.push_back(Platform(nullptr, sf::Vector2f(42.0f, 12.0f), sf::Vector2f(2920.0f, 368.0f)));		// อุโมงก่อนหนาม
	platforms.push_back(Platform(nullptr, sf::Vector2f(42.0f, 12.0f), sf::Vector2f(2943.0f, 392.0f)));		// อุโมงก่อนหนาม
	platforms.push_back(Platform(nullptr, sf::Vector2f(42.0f, 12.0f), sf::Vector2f(2963.0f, 417.0f)));		// อุโมงก่อนหนาม
	platforms.push_back(Platform(nullptr, sf::Vector2f(272.0f, 29.0f), sf::Vector2f(3098.0f, 460.0f)));		// อุโมหนาม1
	platforms.push_back(Platform(nullptr, sf::Vector2f(371.0f, 36.0f), sf::Vector2f(3427.0f, 458.0f)));		// อุโมหนาม1
	platforms.push_back(Platform(nullptr, sf::Vector2f(8.0f, 218.0f), sf::Vector2f(3655.0f, 321.0f)));		// กำแพงกระโดดซ้าย
	platforms.push_back(Platform(nullptr, sf::Vector2f(33.0f, 24.0f), sf::Vector2f(3683.0f, 207.0f)));		// 
	platforms.push_back(Platform(nullptr, sf::Vector2f(22.0f, 250.0f), sf::Vector2f(3786.0f, 436.5f)));		// กำแพงกระโดดขว้า
	platforms.push_back(Platform(nullptr, sf::Vector2f(119.0f, 35.0f), sf::Vector2f(3786.0f, 198.5f)));		// หนามบน
	platforms.push_back(Platform(nullptr, sf::Vector2f(40.0f, 325.0f), sf::Vector2f(3900.0f, 384.5f)));		// หนามขว้า
	platforms.push_back(Platform(nullptr, sf::Vector2f(14.0f, 20.0f), sf::Vector2f(3810.0f, 615.5)));		// หนามล่าง
	platforms.push_back(Platform(nullptr, sf::Vector2f(147.0f, 13.0f), sf::Vector2f(3959.0f, 535.0f)));		// พื้นบนหลังกำแพง
	platforms.push_back(Platform(nullptr, sf::Vector2f(65.0f, 16.0f), sf::Vector2f(4015.0f, 514.0f)));		//
	platforms.push_back(Platform(nullptr, sf::Vector2f(49.0f, 12.0f), sf::Vector2f(4049.0f, 496.0f)));		//
	platforms.push_back(Platform(nullptr, sf::Vector2f(49.0f, 12.0f), sf::Vector2f(4057.0f, 483.0f)));		//
	platforms.push_back(Platform(nullptr, sf::Vector2f(49.0f, 12.0f), sf::Vector2f(4062.0f, 471.0f)));		//
	platforms.push_back(Platform(nullptr, sf::Vector2f(49.0f, 12.0f), sf::Vector2f(4076.0f, 458.0f)));		//
	platforms.push_back(Platform(nullptr, sf::Vector2f(528.0f, 19.0f), sf::Vector2f(4060.0f, 636.0f)));		// พื้นหลังกำแพง
	platforms.push_back(Platform(nullptr, sf::Vector2f(28.0f, 8.0f), sf::Vector2f(4168.0f, 616.0f)));		//บันได้
	platforms.push_back(Platform(nullptr, sf::Vector2f(28.0f, 8.0f), sf::Vector2f(4204.0f, 605.0f)));		//บันได้
	platforms.push_back(Platform(nullptr, sf::Vector2f(28.0f, 8.0f), sf::Vector2f(4234.0f, 593.0f)));		//บันได้
	platforms.push_back(Platform(nullptr, sf::Vector2f(397.0f, 11.0f), sf::Vector2f(4456.5f, 583.5f)));		//พื้นยาว 1 
	platforms.push_back(Platform(nullptr, sf::Vector2f(132.0f, 10.0f), sf::Vector2f(4712.0f, 596.0f)));		//พื้นยาว โล่ง  1 
	platforms.push_back(Platform(nullptr, sf::Vector2f(397.0f, 11.0f), sf::Vector2f(4955.5f, 583.5f)));		//พื้นยาว 2 
	platforms.push_back(Platform(nullptr, sf::Vector2f(132.0f, 10.0f), sf::Vector2f(5201.0f, 595.0f)));		//พื้นยาว โล่ง  2
	platforms.push_back(Platform(nullptr, sf::Vector2f(607.0f, 11.0f), sf::Vector2f(5560.0f, 583.5f)));		//พื้นยาว 3
	platforms.push_back(Platform(nullptr, sf::Vector2f(132.0f, 10.0f), sf::Vector2f(5942.0f, 596.0f)));		//พื้นยาว โล่ง  3
	platforms.push_back(Platform(nullptr, sf::Vector2f(15.0f, 11.0f), sf::Vector2f(5948.5f, 582.5f)));		//
	platforms.push_back(Platform(nullptr, sf::Vector2f(1247.0f, 11.0f), sf::Vector2f(6653.5f, 582.5f)));	//พื้นยาว 4
	platforms.push_back(Platform(nullptr, sf::Vector2f(1483.0f, 11.0f), sf::Vector2f(8019.5f, 586.0f)));	//พื้นยาว 5
	platforms.push_back(Platform(nullptr, sf::Vector2f(51.0f, 8.0f), sf::Vector2f(8695.0f, 573.0f)));		//
	platforms.push_back(Platform(nullptr, sf::Vector2f(48.0f, 22.0f), sf::Vector2f(8728.0f, 557.0f)));		//
	platforms.push_back(Platform(nullptr, sf::Vector2f(48.0f, 22.0f), sf::Vector2f(8764.0f, 532.0f)));		//
	platforms.push_back(Platform(nullptr, sf::Vector2f(48.0f, 22.0f), sf::Vector2f(8802.0f, 507.0f)));		//
	platforms.push_back(Platform(nullptr, sf::Vector2f(475.0f, 24.0f), sf::Vector2f(9023.5f, 507.0f)));		//พื้นยาว 9
	platforms.push_back(Platform(nullptr, sf::Vector2f(38.0f, 21.0f), sf::Vector2f(9094.0f, 481.0f)));		//
	platforms.push_back(Platform(nullptr, sf::Vector2f(44.0f, 266.0f), sf::Vector2f(9255.0f, 400.0f)));		// กำแแพง
	platforms.push_back(Platform(nullptr, sf::Vector2f(4477.0f, 16.0f), sf::Vector2f(6394.4f, 362.0f)));		// เพดาน
	platforms.push_back(Platform(nullptr, sf::Vector2f(617.0f, 23.0f), sf::Vector2f(8998.4f, 295.0f)));		// เพดาน
	//Platform platformY(nullptr, sf::Vector2f(200.0f, 3000.0f), sf::Vector2f(1990.0f,1000.0f));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(4277.0f, 543.0f)));	
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(4413.0f, 543.0f)));	
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(4541.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(4667.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(4764.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(4898.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(5026.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(5152.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(5247.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(5401.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(5545.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(5713.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(5867.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(6029.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(6383.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(6737.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(7009.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(7281.0f, 543.0f)));
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(7537.0f, 543.0f)));//
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(8062.0f, 543.0f)));//
	platformsEnemiesCheck.push_back(Platform(nullptr, sf::Vector2f(4.0f, 60.0f), sf::Vector2f(8651.0f, 543.0f)));//
	///////////////////////////////////////////// พื้น platforms ปกติ //////////////////////////////////////////////////////
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.9f, sf::Vector2f(4280.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(4420.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(4545.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(4770.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(4905.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(5030.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(5260.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(5410.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(5555.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(5720.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(6040.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(6340.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(6740.0f, 553.0f), enemiesSpeed));
	enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(7014.0f, 553.0f), enemiesSpeed));

	bosse.push_back(boss(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(7600.0f, 553.0f), enemiesSpeed));
	bosse.push_back(boss(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(8100.0f, 553.0f), enemiesSpeed));

	float deltaTime = 0.0f;
	sf::Clock clock;
	sf::Clock bulletTime;
	sf::Clock meleettackTime;
	sf::Clock hitboxTime;
	sf::Clock delay;
	sf::Clock enemiesTimeSpon1;
	sf::Clock enemiesTimeSpon2;
	float bull;
	float melle;
	float hitT;
	float delaydie;
	float enemSpo1; 
	float enemSpo2;

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
			scocr += player.GetPosition().x / 1000;
		}


		//time = cl.getElapsedTime().asSeconds();
		//printf("%f\n",time);
		//////////////////////////////////////////////  check dead หนาม //////////////////////////////////////////////////////////////////////// 
		/*if (player.GetPosition().x > 1410.0f && player.GetPosition().x < 1475.0f && player.GetPosition().y == 590.0f) { player.SetPosition(sf::Vector2f(150.0f, 200.0f)); }
		if (player.GetPosition().x > 1585.6f && player.GetPosition().x < 1620.0f && player.GetPosition().y == 421.50f) { player.SetPosition(sf::Vector2f(1408.85f, 400.0f)); }
		if (player.GetPosition().x > 1805.78f && player.GetPosition().x < 1893.63f && player.GetPosition().y == 421.50f) { player.SetPosition(sf::Vector2f(1408.85f, 400.0f)); }
		if (player.GetPosition().x > 2026.0f && player.GetPosition().x < 2064.50f && player.GetPosition().y == 421.50f) { player.SetPosition(sf::Vector2f(1408.85f, 400.0f)); }
		if (player.GetPosition().x > 2243.93f && player.GetPosition().x < 2281.98f && player.GetPosition().y == 421.50f) { player.SetPosition(sf::Vector2f(1408.85f, 400.0f)); }
		if (player.GetPosition().x > 2464.60f && player.GetPosition().x < 2497.0f && player.GetPosition().y == 421.50f) { player.SetPosition(sf::Vector2f(1408.85f, 400.0f)); }
		if (player.GetPosition().x > 2687.0f && player.GetPosition().x < 2722.0f && player.GetPosition().y == 417.50f) { player.SetPosition(sf::Vector2f(1408.85f, 400.0f)); }
		if (player.GetPosition().x > 1512.0f && player.GetPosition().x < 1586.0f && player.GetPosition().y == 593.0f) { player.SetPosition(sf::Vector2f(150.0f, 200.0f)); }
		if (player.GetPosition().x > 1569.0f && player.GetPosition().x < 1623.0f && player.GetPosition().y == 593.0f) { player.SetPosition(sf::Vector2f(150.0f, 200.0f)); }
		if (player.GetPosition().x > 1728.0f && player.GetPosition().x < 1802.0f && player.GetPosition().y == 593.0f) { player.SetPosition(sf::Vector2f(150.0f, 200.0f)); }
		if (player.GetPosition().x > 1839.0f && player.GetPosition().x < 1913.0f && player.GetPosition().y == 593.0f) { player.SetPosition(sf::Vector2f(150.0f, 200.0f)); }
		if (player.GetPosition().x > 1948.0f && player.GetPosition().x < 2022.0f && player.GetPosition().y == 593.0f) { player.SetPosition(sf::Vector2f(150.0f, 200.0f)); }
		if (player.GetPosition().x > 2059.0f && player.GetPosition().x < 2135.0f && player.GetPosition().y == 593.0f) { player.SetPosition(sf::Vector2f(150.0f, 200.0f)); }
		if (player.GetPosition().x > 2059.0f && player.GetPosition().x < 3748.0f && player.GetPosition().y == 593.0f) { player.SetPosition(sf::Vector2f(150.0f, 200.0f)); }
		if (player.GetPosition().x > 2950.0f && player.GetPosition().x < 3625.0f && player.GetPosition().y >=  490.0f && player.GetPosition().y < 505.0f) { player.SetPosition(sf::Vector2f(2900.0f, 400.0f)); }
		if (player.GetPosition().x > 3728.0f && player.GetPosition().x < 3852.0f && player.GetPosition().y >= 180.0f && player.GetPosition().y < 245.0f) { player.SetPosition(sf::Vector2f(2900.0f, 400.0f)); }
		if (player.GetPosition().x > 3858.0f && player.GetPosition().x < 3861.0f && player.GetPosition().y >= 200.0f && player.GetPosition().y < 560.0f) { player.SetPosition(sf::Vector2f(2900.0f, 400.0f)); }
		if (player.GetPosition().x > 3817.0f && player.GetPosition().x < 3833.0f && player.GetPosition().y == 580.50f ) { player.SetPosition(sf::Vector2f(2900.0f, 400.0f)); }*/
		//////////////////////////////////////////////  check dead หนาม //////////////////////////////////////////////////////////////////////// //
		
		playerhp.setPosition(sf::Vector2f(player.GetPosition().x + 220.0f, player.GetPosition().y - 270.0f));
		heart.setPosition(sf::Vector2f(player.GetPosition().x + 175.0f, player.GetPosition().y - 255.0f));

		skills.setPosition(sf::Vector2f(player.GetPosition().x + 220.0f, player.GetPosition().y - 230.0f));
		skillsword.setPosition(sf::Vector2f(player.GetPosition().x + 171.5f, player.GetPosition().y - 215.0f)); //scors
		
		scors.setPosition(sf::Vector2f(player.GetPosition().x - 240.0f, player.GetPosition().y - 270.0f));
	
		/////////////////////////////////// HITBIX.BODY ////////////////////////////////////////////////////
		/*hitboxBody.setOutlineColor(sf::Color::White);
		hitboxBody.setSize(sf::Vector2f(20.f, 50.0f));
		hitboxBody.setPosition(player.GetPosition().x - 10, player.GetPosition().y - 25);*/
		//hitbox.push_back(Hitbox(sf::Vector2f(player.GetPosition().x -10,player.GetPosition().y -25)));
		Hitbox hitbox(sf::Vector2f(player.GetPosition().x, player.GetPosition().y));
		Collider hitboxCollision = hitbox.GetCollider();
		hitT = hitboxTime.getElapsedTime().asMilliseconds();
		
		/////////////////////////////////// HITBIX.BODY ////////////////////////////////////////////////////
		sf::Vector2f direction;
		///////////////////////////////////////////// ศัตรู //////////////////////////////////////////////////////
		enemSpo1 = enemiesTimeSpon1.getElapsedTime().asSeconds();
		if (enemSpo1 > 5.0f)
		{
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10,10), 0.9f, sf::Vector2f(4280.0f, 553.0f), enemiesSpeed));
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(4420.0f, 553.0f), enemiesSpeed));
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(4545.0f, 553.0f), enemiesSpeed));
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(4770.0f, 553.0f), enemiesSpeed));
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(4905.0f, 553.0f), enemiesSpeed));
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(5030.0f, 553.0f), enemiesSpeed));
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(5260.0f, 553.0f), enemiesSpeed));
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(5410.0f, 553.0f), enemiesSpeed));
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(5555.0f, 553.0f), enemiesSpeed));
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(5720.0f, 553.0f), enemiesSpeed));
			enemiesTimeSpon1.restart();
			

		}
		enemSpo2 = enemiesTimeSpon2.getElapsedTime().asSeconds();
		if (enemSpo2 > 60.0f)
		{
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(6040.0f, 553.0f), enemiesSpeed));
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(6340.0f, 553.0f), enemiesSpeed));
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(6740.0f, 553.0f), enemiesSpeed));
			enemies.push_back(Enemy(&enemiesTexture, sf::Vector2u(10, 10), 0.09f, sf::Vector2f(7014.0f, 553.0f), enemiesSpeed));
			enemiesTimeSpon2.restart();
		}
		///////////////////////////////////////////// ศัตรู //////////////////////////////////////////////////////

		bull = bulletTime.getElapsedTime().asMilliseconds();
		if (bull > 500.0f)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) ) //&& skill > 0
			{
				if (player.faceRight == false) {
					bullets.push_back(Bullet(&bulletTextureLeft, sf::Vector2u(1,1), 0.1f, sf::Vector2f(player.GetPosition().x - 10, player.GetPosition().y), -100));
				}
				else bullets.push_back(Bullet(&bulletTextureRight, sf::Vector2u(1,1), 0.1f, sf::Vector2f(player.GetPosition().x + 10, player.GetPosition().y), 100));
				bulletTime.restart();
				skill -= 1;
			}
		}
		
		melle = meleettackTime.getElapsedTime().asMilliseconds();
		if (melle > 400.0f)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			{
				if (player.faceRight == false) {
					meleeattacks.push_back(MeleeAttack(&meleeattacksTexture, sf::Vector2u(), 0, sf::Vector2f(player.GetPosition().x - 10, player.GetPosition().y), -100));
				}
				else
					meleeattacks.push_back(MeleeAttack(&meleeattacksTexture, sf::Vector2u(), 0, sf::Vector2f(player.GetPosition().x + 10, player.GetPosition().y), 100));
					meleettackTime.restart();
			}
		}
		
		
		player.Update(deltaTime);
		hitbox.Update(deltaTime);
		
		for (i = 0; i < enemies.size(); i++)
			enemies[i].Update(deltaTime);
		for (i = 0; i < bosse.size(); i++)
			bosse[i].Update(deltaTime);

		//Collider playerGetCollider = player.GetCollider();
		view.setCenter(player.GetPosition());
		Collider playerCollision = player.GetCollider();
		
		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
				player.OnCollision(direction);

		for (Platform& platform : platforms)
		{
			for (Enemy& enemie : enemies)
			{
				Collider temp = enemie.GetCollider();
				if (platform.GetCollider().CheckCollision(temp, direction, 1.0f))
					enemie.OnCollision(direction);
			}
		}

		for (Platform& platform : platformsEnemiesCheck)
		{
			for (Enemy& enemie : enemies)
			{
				Collider temp = enemie.GetCollider();
				if (platform.GetCollider().CheckCollision(temp, direction, 1.0f))
					enemie.OnCollision(direction);
			}
		}

		for (Platform& platform : platforms)
		{
			for (boss& Boss : bosse)
			{
				Collider temp = Boss.GetCollider();
				if (platform.GetCollider().CheckCollision(temp, direction, 1.0f))
					Boss.OnCollision(direction);
			}
		}

		for (Platform& platform : platformsEnemiesCheck)
		{
			for (boss& Boss : bosse)
			{
				Collider temp = Boss.GetCollider();
				if (platform.GetCollider().CheckCollision(temp, direction, 1.0f))
					Boss.OnCollision(direction);
			}
		}

		//printf("%d", playerHP);
		///////////////////////////////////////////////////// MEELEE ATTACK ////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////// Bullet ////////////////////////////////////////////////////////////////
		for (Bullet& bullet : bullets)
		{
			bullet.SetDestroy(false);
		}
		for (Bullet& bullet : bullets)
		{
			bullet.Update(deltaTime);
		}
		for (MeleeAttack& meleeattack : meleeattacks)
		{
			meleeattack.SetDestroy(false);
		}
		for (MeleeAttack& meleeattack : meleeattacks)
		{
			meleeattack.Update(deltaTime);
		}
		//std::cout << bullets.size() << std::endl;
		for ( i = 0; i < enemies.size(); i++)
		{
			if (enemies.size() > 0) 
			{
				
				Hitbox hitboxenemies(sf::Vector2f(enemies[i].GetPosition().x, enemies[i].GetPosition().y));
				Collider temp = hitboxenemies.GetCollider();
				//Collider temp = enemies[i].GetCollider();
				for (Bullet& bullet : bullets)
				{
					if (bullet.GetCollider().CheckCollision(temp, direction, 1.0f))
					{
						enemies[i].setHp(bullet.GetDmg());
						bullet.SetDestroy(true);
						if (enemies[i].GetHp() <= 0)
						{
							enemiesdid = true;
							item_drop = rand() % 2;
							if (item_drop == true )
							{
								
								item_random = rand() % 3;
								printf("%d\n",item_random);
								if (item_random == 0)
								{
									Checkitem = 0;
									enemiesX = enemies[i].GetPosition().x;
									enemiesY = enemies[i].GetPosition().y;
									//items.push_back(iTem(&Heart,sf::Vector2u(1,1),0.1f,sf::Vector2f(enemies[i].GetPosition().x, enemies[i].GetPosition().y), 0));
								
								}
								else if (item_random == 1)
								{
									Checkitem = 1;
									enemiesX = enemies[i].GetPosition().x;
									enemiesY = enemies[i].GetPosition().y;
									//items.push_back(iTem(&skillswords, sf::Vector2u(1, 1), 0.1f, sf::Vector2f(enemies[i].GetPosition().x, enemies[i].GetPosition().y), 0));
								}
								else if (item_random == 2)
								{
									Checkitem = 2;
									enemiesX = enemies[i].GetPosition().x;
									enemiesY = enemies[i].GetPosition().y;
									//items.push_back(iTem(&itemTexture, sf::Vector2u(4,1 ), 0.9f, sf::Vector2f(enemies[i].GetPosition().x, enemies[i].GetPosition().y), 1));
								}
							}
							scocr += 50;
							enemies.erase(enemies.begin() + i);
						}
					}
				}
				for ( j = 0; j < bullets.size(); j++)
				{
					if (bullets[j].isDestroy())
					{
						bullets.erase(bullets.begin() + j);
						//enemyHP -= 25;
					}
					else
					{
						if (bull > 5000)
						{
							bullets.erase(bullets.begin() + j);
							bulletTime.restart();
						}
					}
				}
				for (MeleeAttack& meleeattack : meleeattacks)
				{
					if (meleeattack.GetCollider().CheckCollision(temp, direction, 1.0f))
					{
						enemies[i].setHp(meleeattack.GetDmg());
						meleeattack.SetDestroy(true);
						if (enemies[i].GetHp() <= 0)
						{
							scocr += 50;
							enemies.erase(enemies.begin() + i);
							
						}
					}
				}
				for (j = 0; j < meleeattacks.size(); j++)
				{
					if (meleeattacks[j].isDestroy())
					{
						meleeattacks.erase(meleeattacks.begin() + j);
						//enemyHP -= 25;
					}
					else
					{
						if (melle > 470)
						{
							meleeattacks.erase(meleeattacks.begin() + j);
							bulletTime.restart();
						}
					}
				}
				if(hitbox.GetCollider().CheckCollision(temp, direction, 0.0f))
				{
					if (hitT > 600)
					{
						//printf(" Hit\n ");
						hitboxTime.restart();
						playerHP -= 1;
					}
					
				}
				hitboxenemies.Update(deltaTime);
				//hitboxenemies.Draw(window);
				
			}
			
		}
		
		//////////////////////////////////////////////////////////////////////////////////////////////////  BOSS ////////////////////////////////////////////////////////////////////////
		for (i = 0; i < bosse.size(); i++){
			if (bosse.size() > 0){
				Hitbox hitboxboss(sf::Vector2f(bosse[i].GetPosition().x, bosse[i].GetPosition().y));
				Collider temp = hitboxboss.GetCollider();
				for (Bullet& bullet : bullets){
					if (bullet.GetCollider().CheckCollision(temp, direction, 1.0f)){
						bosse[i].setHp(bullet.GetDmg());
						bullet.SetDestroy(true);
						if (bosse[i].GetHp() <= 0){
							
							scocr += 150;
							bosse.erase(bosse.begin() + i);
						}
					}
				}
				for (j = 0; j < bullets.size(); j++){
					if (bullets[j].isDestroy()){
						bullets.erase(bullets.begin() + j);
						//enemyHP -= 25;
					}
					else{
						if (bull > 5000){
							bullets.erase(bullets.begin() + j);
							bulletTime.restart();
						}
					}
				}
				for (MeleeAttack& meleeattack : meleeattacks){
					if (meleeattack.GetCollider().CheckCollision(temp, direction, 1.0f)){
						bosse[i].setHp(meleeattack.GetDmg());
						meleeattack.SetDestroy(true);
						if (bosse[i].GetHp() <= 0)
						{
							scocr += 150;
							bosse.erase(bosse.begin() + i);
						}
					}
				}
				for (j = 0; j < meleeattacks.size(); j++){
					if (meleeattacks[j].isDestroy()){
						meleeattacks.erase(meleeattacks.begin() + j);
						//enemyHP -= 25;
					}
					else{
						if (melle > 470)
						{
							meleeattacks.erase(meleeattacks.begin() + j);
							bulletTime.restart();
						}
					}
				}
				if (hitbox.GetCollider().CheckCollision(temp, direction, 0.0f)){
					if (hitT > 600){
						//printf(" Hit\n ");
						hitboxTime.restart();
						playerHP -= 1;
					}

				}
				
				hitboxboss.Update(deltaTime);
				//hitboxenemies.Draw(window);

			}

		}
		if (Checkitem == 0)
		{
			items.push_back(iTem(&Heart, sf::Vector2u(1, 1), 0.1f, sf::Vector2f(enemiesX, enemiesY), 0));
			Checkitem = 5;
		}
		for (i = 0; i < items.size();i++)
		{
			Collider temp = items[i].GetCollider();
			if(hitbox.GetCollider().CheckCollision(temp, direction, 0.0f))
			{
				playerHP += 1;
				items.erase(items.begin() + i);
			}
		}

		if (Checkitem == 1)
		{
			items1.push_back(iTem(&skillswords, sf::Vector2u(1, 1), 0.1f, sf::Vector2f(enemiesX, enemiesY), 0));
			Checkitem = 5;
		}
		for (i = 0; i < items1.size(); i++)
		{
			Collider temp = items1[i].GetCollider();
			if (hitbox.GetCollider().CheckCollision(temp, direction, 0.0f))
			{
				skill += 1;
				items1.erase(items1.begin() + i);
			}
		}
		if (Checkitem == 2)
		{
			items2.push_back(iTem(&itemTexture, sf::Vector2u(4,1), 0.9f, sf::Vector2f(enemiesX, enemiesY), 1));
			Checkitem = 5;
		}
		for (i = 0; i < items2.size(); i++)
		{
			Collider temp = items2[i].GetCollider();
			if (hitbox.GetCollider().CheckCollision(temp, direction, 0.0f))
			{
				scocr += 25;
				items2.erase(items2.begin() + i);
			}


		}
		//////////////////////////////////////////////////////////////////////////////////////////////////  BOSS ////////////////////////////////////////////////////////////////////////
		
		for (Bullet& bullet : bullets)
			bullet.Update(deltaTime);
		for (MeleeAttack& meleeattack : meleeattacks)
			meleeattack.Update(deltaTime);
		for (iTem& item : items)
			item.Update(deltaTime);
		///////////////////////////////////////////////////// Bullet ////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////// MEELEE ATTACK ////////////////////////////////////////////////////////////////

		

		window.clear(sf::Color(40, 37, 56));
		window.draw(Backgroundack);
		hitbox.Draw(window);
		player.Draw(window);

		playerhp.setString(std::to_string(playerHP));
		window.draw(playerhp);
		window.draw(heart);
		skills.setString(std::to_string(skill));
		window.draw(skills);
		window.draw(skillsword);
		scors.setString(std::to_string(scocr));
		window.draw(scors);
		window.setView(view);
		
		
/*for (Enemy& enemie : enemies)
			enemie.Draw(window);*/
	for(int i = 0; i < enemies.size(); i++)
		{
			if (enemies.size() > 0) 
			{
				enemies[i].Draw(window);
			}
		}

	for (int i = 0; i < bosse.size(); i++)
	{
		if (bosse.size() > 0)
		{
			bosse[i].Draw(window);
		}
	}
	
	for (Bullet& bullet : bullets)
		bullet.Draw(window);

	for (MeleeAttack& meleeattack : meleeattacks)
		meleeattack.Draw(window);

	for (iTem& item : items)
		item.Draw(window);
	
	for (iTem& item1 : items1)
		item1.Draw(window);

	for (iTem& item2 : items2)
		item2.Draw(window);

	/*for (Platform& platform : platforms)
		 platform.Draw(window);

	for (Platform& platform : platformsEnemiesCheck)
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
