///////////////////////////////               PLAYER.H                          /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

#pragma once
// .h includes
#include "Framework/GameObject.h"
#include "Framework/Input.h"
#include "Framework/Animation.h"
#include "WallManager.h"
#include "BulletManager.h"

// Object for one player
class Player : public GameObject
{
public:
	Player();
	~Player();

	//controls the users input to control the player object and changes the animation based on input
	void handleInput(float dt);
	// collision checks between the walls and top and bottom of level. left level a bit high for user to skip badguys
	void update(float dt);
	// function to get access to the WallManager class
	void setPWallManager(WallManager* wm)
	{
		this->wallManager = wm;
	}
	// function to get access to the BulletManager class
	void setBulletManager(BulletManager* wm)
	{
		this->bulletManager = wm;
	}
	//timer used for the bullets firerate
	float timer;

	//getter and setter for the score
	int getScore();
	void setScore(int x);
	

protected:
	// Animations
	Animation idle;
	Animation back;
	Animation forward;
	Animation* currentAnimation;

private:

	// these are used for the above setters for the managers
	WallManager* wallManager;
	BulletManager* bulletManager;
	// vectors used for getting the center of the player and center of wall for collision check
	sf::Vector2f playerCentre;
	sf::Vector2f wallCentre;

	//setting score to default of -100 until i fix one enemy dieing at the start of the game 
	int score = -100;
	






};

