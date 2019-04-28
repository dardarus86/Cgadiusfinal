///////////////////////////////               ENEMY.H                           /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

#pragma once
// .h includes
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include <SFML/Audio.hpp>

//class to control a single enemy
class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	//used for controlling the idle animation and collision resonse with top and bottom of level
	void update(float dt);
	//used when an enemy is hit to change animation. Slightly bugged and i believe it's linked to the timer.
	void collision(float dt);

protected:
	//animations used in class
	Animation idle;
	Animation explosion;
	Animation* currentAnimation;
};