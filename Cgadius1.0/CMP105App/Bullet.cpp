///////////////////////////////               BULLET.CPP                        /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

//single include
#include "Bullet.h"

Bullet::Bullet() {}
Bullet::~Bullet(){}

//Function:  Used to move the object
//Parameter: Deltatime
//output:    None
void Bullet::update(float dt)
{
	move(velocity*dt);
}
