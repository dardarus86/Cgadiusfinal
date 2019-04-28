///////////////////////////////               ENEMYMANAGER.H                    /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

#pragma once
//.h includes

#include "Framework/Collision.h"
#include "Enemy.h"
#include "WallManager.h"
#include "BulletManager.h"
#include "Player.h"
// library includes
#include <vector>

//This class is used for spawning, controlling collisions and modifying the players scores 
class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	// used for setting up the enemy variables and locations
	void spawn();
	//collision checks, deletion of enemies on collision and player score updated
	void update(float dt, Player &player);
	// drawing the enemies to the screen in level.cpp
	void render(sf::RenderWindow* window);
	//function to return the values of the enemy vector
	std::vector<Enemy>& getEnemy() { return enemy; }
	// function to get access to the WallManager class
	void setWallManager(WallManager* wm)
	{
		this->wallManager = wm;
	}
	// function to get access to the BulletManager class
	void setBulletManager(BulletManager* bm)
	{
		this->bulletManager = bm;
	}


private:
	//vector of  enemy objects from Enemy class
	std::vector<Enemy> enemy;
	//texture used for the enemy sprite
	sf::Texture Enemytexture;
	//object pointers used in the set functions above
	WallManager* wallManager;
	BulletManager* bulletManager;
	//AudioManager object being used for the death sound effect
	AudioManager audioManager;
	//timer used to allow the explosion animation to finish before despawning the enemies. Bugged I believe, unsure how to fix
	float timer;
};
