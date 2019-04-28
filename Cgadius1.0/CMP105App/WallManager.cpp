///////////////////////////////               WALLMANAGER.CPP                   /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

//single include
#include "WallManager.h"


//setting up the wall vector with a texture and setting a collision box for each object
WallManager::WallManager()
{
	wall1texture.loadFromFile("gfx/wall1.png");

	for (int i = 0; i < 13; i++)
	{
		walls1.push_back(Wall());
		walls1[i].setTexture(&wall1texture);
		walls1[i].setSize(sf::Vector2f(150, 125));
		walls1[i].setCollisionBox(0, 0, 150, 125);
	}
}

WallManager::~WallManager() {}

//Function:  Spawning the walls in set positions 
//Parameter: None
//output:    None
void WallManager::spawn()
{
	walls1[0].setPosition(450, 340);
	walls1[1].setPosition(1210, 105);
	walls1[2].setPosition(1210, 340);
	walls1[3].setPosition(1210, 571);
	walls1[4].setPosition(1480, 105);
	walls1[5].setPosition(1480, 571);
	walls1[6].setPosition(1680, 230);
	walls1[7].setPosition(1680, 480);
	walls1[8].setPosition(2700, 140);
	walls1[9].setPosition(2700, 530);
	walls1[10].setPosition(3150, 320);
	walls1[11].setPosition(3560, 140);
	walls1[12].setPosition(3560, 530);


}

//Function:  Render all alive walls
//Parameter: RenderWindow
//output:    None
void WallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < walls1.size(); i++)
	{
		window->draw(walls1[i]);
	}
}
