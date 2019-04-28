///////////////////////////////               WALL.H                            /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

#pragma once
// .h includes
#include "Framework/GameObject.h"
#include "Framework/Collision.h"

//class for creating single wall object. no update as wall does not move
class Wall : public GameObject
{
public:
	Wall();
	~Wall();
};
