///////////////////////////////               BULLET.H                          /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

#pragma once
#include "Framework/GameObject.h"

//class to control a single bullet
class Bullet : public GameObject
{
public:
	//empty constructor/deconstructor
	Bullet();
	~Bullet();
	//function for the movement of bullet
	void update(float dt);

};

