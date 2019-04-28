///////////////////////////////               WALLMANAGER.H                     /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

#pragma once
//.h includes
#include "Wall.h"
#include <math.h>
#include <iostream>
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include <vector>

//This class is used for spawning, and rendering the walls
class WallManager
{
public:
	WallManager();
	~WallManager();
	// used for setting up the wall locations
	void spawn();
	//rendering the wall segments to level
	void render(sf::RenderWindow* window);
	//function to return the values of the wall vector
	std::vector<Wall>& getWalls1() { return walls1; }

private:
	//creating the wall vector and setting its texture
	std::vector<Wall> walls1;
	sf::Texture wall1texture;

};
