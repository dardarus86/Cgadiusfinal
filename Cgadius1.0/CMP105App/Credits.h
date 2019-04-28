///////////////////////////////               CREDITS.H               /////////////////////////////////////
///////////////////////////////               COMMENTING              /////////////////////////////////////

#pragma once
//.h includes
#include <SFML/Graphics.hpp>
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
#include "Framework/GameState.h"
#include "Player.h"
// library includes
#include <string>

//This class is used for credits screen after player reaches end of level
class Credits :public GameObject
{
public:
	Credits(sf::RenderWindow* hwnd);
	~Credits();

	// used to get the score. Does not work i dont think?
	void playerScore(Player &player);
	//used for animating the credit screen
	void update(float dt);
	//rendering the animation and text
	void render();

private:
	// Default functions for rendering to the screen. Good job Paul!
	void beginDraw();
	void endDraw();

	// Default variables for level class. Good job Paul!
	sf::RenderWindow* window;

	// font and text used in credits screen
	sf::Font font;
	sf::Text text;
	sf::Text text2;
	//backgroundob and background used for the animated background
	GameObject backgroundobj;
	Animation background;
	sf::Texture backgroundtexture;

// used for calculating the final score. does not work though =(
	int finalScore = 0;


};