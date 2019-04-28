///////////////////////////////               BULLETMANAGER.H                   /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

#pragma once
//.h includes
#include "Framework/AudioManager.h"
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "WallManager.h"
// library includes
#include <vector>

//This class is used for spawning, controlling collision with Bullets/Walls
class BulletManager : public GameObject
{
public:
	BulletManager();
	~BulletManager();

	//used to spawn bullets at the players location
	void spawn(float x, float y);
	// two functions to get and set the players positions
	float getPlayerPosX();
	void setPlayerPosX(float x);
	//collision check done here
	void update(float dt);
	//for despawning the bullets to be used again
	void deathCheck();
	// drawing the bullets to the screen in level.cpp
	void render(sf::RenderWindow* window);

	//function to return the values of the bullet vector
	std::vector<Bullet>* getBullets() { return  &bullet; }
	float PlayerX;

	// function to get access to the WallManager class
	void setWallManager(WallManager* wm)
	{
		this->wallManager = wm;
	}

private:

	//vector used to create multiple bullets
	std::vector<Bullet> bullet;
	//texture for bullet
	sf::Texture texture;
	//Audiomanager used for the bullet sound effect
	AudioManager audioManager;
	//object pointer used in the set function above
	WallManager* wallManager;
	
};
