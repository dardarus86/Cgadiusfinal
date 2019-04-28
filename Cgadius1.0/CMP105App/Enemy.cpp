///////////////////////////////               ENEMY.CPP                         /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

//single include
#include "Enemy.h"

// creating the animation from the spritesheet added in Enemymanager
Enemy::Enemy()
{
	idle.addFrame(sf::IntRect(0, 0, 432, 367));
	idle.addFrame(sf::IntRect(432, 0, 432, 367));
	idle.addFrame(sf::IntRect(864, 0, 432, 367));
	idle.addFrame(sf::IntRect(1296, 0, 432, 367));
	idle.setFrameSpeed(0.1f);
	idle.setFlipped(false);
	
	explosion.addFrame(sf::IntRect(0,   384, 79, 79));
	explosion.addFrame(sf::IntRect(80,  384, 79, 79));
	explosion.addFrame(sf::IntRect(160, 384, 79, 79));
	explosion.addFrame(sf::IntRect(240, 384, 79, 79));
	explosion.addFrame(sf::IntRect(320, 384, 79, 79));
	explosion.addFrame(sf::IntRect(400, 384, 79, 79));
	explosion.addFrame(sf::IntRect(480, 384, 79, 79));
	explosion.addFrame(sf::IntRect(540, 384, 79, 79));
	explosion.setFrameSpeed(0.03f);
		
	currentAnimation = &idle;
	setTextureRect(currentAnimation->getCurrentFrame());

}

Enemy::~Enemy(){}

//Function:  Used for setting up the animation, mvement and collision check with top and bottom of level
//Parameter: Deltatime
//output:    None
void Enemy::update(float dt)
{
	currentAnimation->animate(dt);
	move(velocity*dt);
	
	if (getPosition().y <= 105 || getPosition().y >= 646)
	{
		velocity = -velocity;
	}
}

//Function:  if the enemy collision function is called, changes the current animation and stops them moving. not working properly
//Parameter: Deltatime
//output:    None
void Enemy::collision(float dt)
{
	currentAnimation = &explosion;
	setTextureRect(explosion.getCurrentFrame());
	velocity.y = 0;
}


