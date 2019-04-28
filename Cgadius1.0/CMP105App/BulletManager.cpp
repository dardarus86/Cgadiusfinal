///////////////////////////////               BULLETMANAGER.CPP                 /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

//single include
#include "BulletManager.h"


//constructor loading the texture,sound effect and populating the vector of bullets
BulletManager::BulletManager()
{
	texture.loadFromFile("gfx/playerbullet.png");
	audioManager.addSound("sfx/shot2.wav", "wallhit");
	for (int i = 0; i < 30; i++)
	{
		bullet.push_back(Bullet());
		bullet[i].setAlive(false);
		bullet[i].setTexture(&texture);
		bullet[i].setSize(sf::Vector2f(6, 24));
	}
}

BulletManager::~BulletManager(){}

//Function:  setting the players X position for use in the deathcheck function
//Parameter: Float
//output:    None
void BulletManager::setPlayerPosX(float x)
{
	PlayerX = x;
}

//Function:  getting the players X position for use in the deathcheck function
//Parameter: None
//output:    PlayerX variable
float BulletManager::getPlayerPosX()
{
	return PlayerX;
}

//Function:  Spawning the bullets with a velocity and assigning the position to the players x and y position from player.cpp
//Parameter: Two floats
//output:    None
void BulletManager::spawn(float x, float y)
{
	
	
	for (int i = 0; i < bullet.size(); i++)
	{
		if (!bullet[i].isAlive())
		{
			bullet[i].setPosition(x, y);
			bullet[i].setAlive(true);
			bullet[i].setVelocity(1500,0);
			return;
				
		}
	}
}

//Function:  collision detection between Bullet/Walls.  Bullet/Asteroids in AsteroidManager, Bullet/Enemies in enemymanager. bad practice to do it like this though
//Parameter: Deltatime
//output:    None
void BulletManager::update(float dt)
{
	//assigning new vector to the elements of the vector used in WallManager
	std::vector<Wall> walls1 = wallManager->getWalls1();

	// first collision check for Bullets vs Walls. If collision detected then destroy bullet and play a sound to indicate hit
	for (auto& bullet : bullet)
	{
		for (auto& wall : walls1)
		{
			if (Collision::checkBoundingBox(&bullet, &wall))
			{
				audioManager.playSoundbyName("wallhit");
				bullet.setAlive(false);
				// moving bullet away from wall as setalive does not remove the object only make it invisible so sound plays constantly
				bullet.setPosition(-100, -100);
			}
		}
	}
	for (int i = 0; i < bullet.size(); i++)
	{
		if (bullet[i].isAlive())
		{
			bullet[i].update(dt);
		}
	}
	deathCheck();
}
//Function:  If the bullet is 700 pixels away from player then despawn. This is he variable taken from the getter and setter above
//Parameter: None
//output:    None
void BulletManager::deathCheck()
{
	for (int i = 0; i < bullet.size(); i++)
	{
		if (bullet[i].isAlive())
		{
			if (bullet[i].getPosition().x > PlayerX + 700)
			{
				bullet[i].setAlive(false);
			}
		}
	}
}
//Function:  Render all alive bullets
//Parameter: RenderWindow
//output:    None
void BulletManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < bullet.size(); i++)
	{
		if (bullet[i].isAlive())
		{
			window->draw(bullet[i]);
		}
	}
}
