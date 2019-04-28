///////////////////////////////               PLAYER.CPP                        /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

#include "Player.h"

// constructor setting the player animation and collision box
Player::Player()
{
	idle.addFrame(sf::IntRect(0, 139, 160, 135));
	idle.addFrame(sf::IntRect(159, 139, 160, 135));
	idle.addFrame(sf::IntRect(319, 139, 160, 135));
	idle.addFrame(sf::IntRect(479, 139, 160, 135));
	idle.addFrame(sf::IntRect(639, 139, 160, 135));
	idle.addFrame(sf::IntRect(799, 139, 160, 135));
	idle.addFrame(sf::IntRect(959, 139, 160, 135));
	idle.addFrame(sf::IntRect(1119, 139, 160, 135));
	idle.addFrame(sf::IntRect(1279, 139, 160, 135));
	idle.addFrame(sf::IntRect(1439, 139, 160, 135));
	idle.addFrame(sf::IntRect(1599, 139, 160, 135));
	idle.setFrameSpeed(0.1f);
	

	forward.addFrame(sf::IntRect(479, 0, 160, 139));
	forward.addFrame(sf::IntRect(639, 0, 160, 139));
	forward.setFrameSpeed(0.1f);

	back.addFrame(sf::IntRect(0, 0, 160, 139));
	back.addFrame(sf::IntRect(159, 0, 160, 139));
	back.addFrame(sf::IntRect(319, 0, 160, 139));
	back.setFrameSpeed(0.1f);

	currentAnimation = &idle;
	setTextureRect(currentAnimation->getCurrentFrame());

	setCollisionBox(0,0, 60, 60);
}

Player::~Player(){}

//Function:  used for handle input of user and changing the current animation and setting different velocities depending on keypress 
//Parameter: deltatime
//output:    None
void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		currentAnimation = &forward;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = 400;
		velocity.y = 0;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		currentAnimation = &back;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = -400;
		velocity.y = 0;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Up))
	{
		currentAnimation = &idle;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = 0;
		velocity.y = -400;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		currentAnimation = &idle;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = 0;
		velocity.y = 400;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Right) && input->isKeyDown(sf::Keyboard::RControl))
	{
		currentAnimation = &forward;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = 2000;
		velocity.y = 0;
		move(velocity*dt);
	}

	if (input->isKeyDown(sf::Keyboard::Left) && input->isKeyDown(sf::Keyboard::RControl))
	{
		currentAnimation = &back;
		setTextureRect(currentAnimation->getCurrentFrame());
		velocity.x = -2100;
		velocity.y = 0;
		move(velocity*dt);
	}

	//  firing the bullets from the vector and setting the two X and Y floats from the bulletmanager spawn function
	if (input->isKeyDown(sf::Keyboard::Space))
	{
      		if (timer >= 0.15 )
		{
			bulletManager->spawn(this->getPosition().x + 30, this->getPosition().y + 30);
			timer = 0;
		}
	}
		
}

//Function:  used for updating the animation and checking Wall/Player collision
//Parameter: deltatime
//output:    None
void Player::update(float dt)
{
	timer+=dt;

	bulletManager->setPlayerPosX(getPosition().x);
	bulletManager->setPosition(getPosition().x + 50, getPosition().y + 26);
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());
	

	//assigning new vectors to the elements of the vector used in WallManager
	std::vector<Wall> walls1 = wallManager->getWalls1();


for (auto& wall : walls1)
	{	
		
		if (Collision::checkBoundingBox(this, &wall))
		{
			// First you calculate the middle of both object x and Y
			playerCentre.x = getPosition().x + (getSize().x * 0.5);
			playerCentre.y = getPosition().y + (getSize().y * 0.5);
			wallCentre.x = wall.getPosition().x + (wall.getSize().x * 0.5);
			wallCentre.y = wall.getPosition().y + (wall.getSize().y * 0.5);
			

			//two ints to work out which direction has been hit
			float tempX, tempY;
		
			tempX = abs(wallCentre.x - playerCentre.x);
			tempY = abs(wallCentre.y - playerCentre.y);

			if (tempX < 0)
			{
				tempX *= -1;
			}

			if (tempY < 0)
			{
				tempY *= -1;
			}
			//if the center of X of both objects are closer than the Ys of both objects then collision is horizontal
			if (tempX > tempY)
			{
				// if the walls x is great than the players x then that means its colliding with the left of the wall
				if (wallCentre.x > playerCentre.x)
				{
					velocity.x = 0;
					setPosition(wall.getPosition().x - getSize().x, getPosition().y);
				}
				// if the walls x is less than the players x then that means its colliding with the right of the wall
				if (wallCentre.x < playerCentre.x)
				{
					velocity.x = 0;
					setPosition(wall.getPosition().x + wall.getSize().x, getPosition().y);
				}
			}
			//if the center of Y of both objects are closer than the Xs of both objects then collision is vertical
			else
			{
				// if the walls y is great than the players y then that means its colliding with the top of the wall
				if (wallCentre.y > playerCentre.y)
				{
					velocity.y = 0;
					setPosition(getPosition().x, wall.getPosition().y - getSize().y);
				}
				// if the walls y is less than the players y then that means its colliding with the bottom of the wall
				else
				{
					velocity.y = 0;
					setPosition(getPosition().x, wall.getPosition().y + wall.getSize().y);
				}
			}

		}
	}

	if (getPosition().y <= 100)
	{
		setPosition(getPosition().x, 100);
	}

	if (getPosition().y >= 700)
	{
		setPosition(getPosition().x, 700);
	}


}

//Function:  used for getting the score
//Parameter: None
//output:    score
int Player::getScore()
{
	return score;
}

//Function:  used for setting the score
//Parameter: Int X
//output:    None
void Player::setScore(int x)
{
	score = score + x;
}




