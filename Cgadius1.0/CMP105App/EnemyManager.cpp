///////////////////////////////               ENEMYMANAGER.CPP                  /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

#include "EnemyManager.h"

// constructor setting the time for explosion animation to zero, loading texture and audio file for enemy and populationg the Enemy vector
EnemyManager::EnemyManager()
{
	audioManager.addSound("sfx/enemydeath.wav", "enemydeath");
	Enemytexture.loadFromFile("gfx/enemy1sheet.png");
	for (int i = 0; i < 94; i++)
	{
		enemy.push_back(Enemy());
		enemy[i].setAlive(false);
		enemy[i].setTexture(&Enemytexture);
		enemy[i].setSize(sf::Vector2f(60, 50));
		enemy[i].setCollisionBox(0, 0, 60, 50);
	
	}
}

EnemyManager::~EnemyManager(){}

//Function:  Setting all the enemy positions manually and setting the velocity
//Parameter: None
//output:    None
void EnemyManager::spawn()
{
	//wave 1 top 4
	enemy[0].setPosition(260, 300);
	enemy[1].setPosition(310, 240);
	enemy[2].setPosition(380, 215);
	enemy[3].setPosition(460, 210);
	//wave 1 bottom 8
	enemy[4].setPosition(260, 420);
	enemy[5].setPosition(310, 480);
	enemy[6].setPosition(380, 520);
	enemy[7].setPosition(460, 520);
	//wave 2 top 12
	enemy[8].setPosition(840, 240);
	enemy[9].setPosition(910, 180);
	enemy[10].setPosition(910, 240);
	enemy[11].setPosition(910, 300);
	//wave 2 bottom 16
	enemy[12].setPosition(980, 480);
	enemy[13].setPosition(1050, 420);
	enemy[14].setPosition(1050, 480);
	enemy[15].setPosition(1050, 540);
	//wave 3 first grey 25
	enemy[16].setPosition(2080, 300);
	enemy[17].setPosition(2150, 300);
	enemy[18].setPosition(2220, 300);
	enemy[19].setPosition(2290, 300);
	enemy[20].setPosition(2080, 360);
	enemy[21].setPosition(2290, 360);
	enemy[22].setPosition(2080, 420);
	enemy[23].setPosition(2150, 420);
	enemy[24].setPosition(2220, 420);
	enemy[25].setPosition(2290, 420);
	//wave 3 first green 27
	enemy[26].setPosition(2150, 360);
	enemy[27].setPosition(2220, 360);
	//wave 3 second green 32
	enemy[28].setPosition(2460, 360);
	enemy[29].setPosition(2520, 300);
	enemy[30].setPosition(2580, 240);
	enemy[31].setPosition(2520, 420);
	enemy[32].setPosition(2580, 480);
	//wave 4 top 36
	enemy[33].setPosition(3000, 240);
	enemy[34].setPosition(3060, 180);
	enemy[35].setPosition(3060, 300);
	enemy[36].setPosition(3120, 240);
	//wave 4 bot 40
	enemy[37].setPosition(3000, 420);
	enemy[38].setPosition(3060, 360);
	enemy[39].setPosition(3060, 480);
	enemy[40].setPosition(3150, 470);
	//wave 5 49
	enemy[41].setPosition(3720, 110);
	enemy[42].setPosition(3720, 170);
	enemy[43].setPosition(3720, 490);
	enemy[44].setPosition(3720, 320);
	enemy[45].setPosition(3720, 490);
	enemy[46].setPosition(3720, 620);
	enemy[47].setPosition(3970, 110);
	enemy[48].setPosition(3970, 170);
	enemy[49].setPosition(3890, 490);
	//wave 6 50 - 70
	enemy[50].setPosition(4560, 130);
	enemy[51].setPosition(4490, 185);
	enemy[52].setPosition(4560, 245);
	enemy[53].setPosition(4560, 305);
	enemy[54].setPosition(4490, 365);
	enemy[55].setPosition(4560, 420);
	enemy[56].setPosition(4560, 480);
	enemy[57].setPosition(4490, 540);
	enemy[58].setPosition(4560, 600);
	enemy[59].setPosition(4550, 365);
	enemy[60].setPosition(4620, 305);
	enemy[61].setPosition(4620, 420);
	enemy[62].setPosition(4680, 245);
	enemy[63].setPosition(4680, 480);
	enemy[64].setPosition(4760, 180);
	enemy[65].setPosition(4760, 240);
	enemy[66].setPosition(4760, 300);
	enemy[67].setPosition(4760, 360);
	enemy[68].setPosition(4760, 420);
	enemy[69].setPosition(4760, 480);
	enemy[70].setPosition(4760, 540);
	//wave 71 92
	enemy[71].setPosition(5160, 240);
	enemy[72].setPosition(5220, 300);
	enemy[73].setPosition(5280, 360);
	enemy[74].setPosition(5280, 480);
	enemy[75].setPosition(5220, 540);
	enemy[76].setPosition(5160, 600);
	enemy[77].setPosition(5400, 360);
	enemy[78].setPosition(5460, 300);
	enemy[79].setPosition(5400, 480);
	enemy[80].setPosition(5460, 540);
	enemy[81].setPosition(5160, 420);
	enemy[82].setPosition(5220, 420);
	enemy[83].setPosition(5280, 420);
	enemy[84].setPosition(5400, 420);
	enemy[85].setPosition(5460, 420);
	enemy[86].setPosition(5340, 240);
	enemy[87].setPosition(5340, 300);
	enemy[88].setPosition(5340, 360);
	enemy[89].setPosition(5340, 480);
	enemy[90].setPosition(5340, 540);
	enemy[91].setPosition(5340, 600);
	enemy[92].setPosition(5340, 420);

	for (int i = 0; i < enemy.size(); i++)
	{
		if (!enemy[i].isAlive())
		{
			enemy[i].setAlive(true);
			enemy[i].setVelocity(0, 75);
			return;
		}
	}
}

//Function:  collision detection between Bullet/Enemy, Wall/Enemy and Player/Enemy 
//Parameter: Deltatime and Player reference
//output:    None
void EnemyManager::update(float dt, Player &player)
{
	// two new vectors getting populated by the walls and bullets from the other classes
	std::vector<Wall> walls1 = wallManager->getWalls1();
	std::vector<Bullet>* bullet1 = bulletManager->getBullets();

	// first collision check for Enemy vs Walls. If collision detected then reverse the enemy velocity
	for (auto& wall : walls1)
	{
		for (auto& enemy : enemy)
		{
			if (Collision::checkBoundingBox(&enemy, &wall))
			{

 				enemy.setVelocity(0, enemy.getVelocity().y * (-1));
				
			}
		}
	}
	
	// second collision check for Enemy vs Bullets. If collision detected then remove the bullet and enemy and increase player score by 100
	//This check is bugged i believe as the timer seems to cause the enemy to explode and get stuck halfway through animation and require another shot to be killed
	for (auto& bullet : *bullet1)
	{
		for (auto& enemy : enemy)
		{
			if (Collision::checkBoundingBox(&enemy, &bullet))
			{
				if (enemy.isAlive())
				{
					timer += dt;
					enemy.collision(dt);
					audioManager.playSoundbyName("enemydeath");
					bullet.setAlive(false);
					if (timer >= 0.1)
					{
						enemy.setAlive(false);
						enemy.setPosition(-100, 0);
						player.setScore(100);
						timer = 0;

					}
				}
			}
		}
	}

	// Third collision check for Enemy vs Player. If collision detected, set the players position back by 50 pixels nad reduce score by 100
	// moved the player back due if in contact the score would decrease by 10,000s of points every second
	for (auto& enemy : enemy)
	{
		if (Collision::checkBoundingBox(&enemy, &player))
		{
			player.setScore(-100);
			player.setPosition(player.getPosition().x - 50, player.getPosition().y);
		}
	}
	
	//call update on all ALIVE enemies
	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i].update(dt);
	}
}

//Function:  Render all alive enemies
//Parameter: RenderWindow
//output:    None
void EnemyManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i].isAlive())
		{
			window->draw(enemy[i]);
		}
	}
}
