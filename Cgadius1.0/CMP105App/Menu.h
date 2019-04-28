///////////////////////////////               MENU.H                            /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

#pragma once
// .h includes
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
#include <string>
#include <iostream>

// menu class for the game called before the level with some information to help the user
class Menu :public GameObject
{
public:
	Menu(sf::RenderWindow* hwnd, Input* in, GameState* state);
	~Menu();

	// takes in a keypress to change the gamestate to level
	void handleInput(float dt);
	//used for animating the background
	void update(float dt);
	//renders the background and text objects
	void render();

private:
	// Default functions for rendering to the screen. Thanks Paul!
	void beginDraw();
	void endDraw();

	// Default variables for level class. Thanks Paul!
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager audioManager;

	// text objects used 
	sf::Font font;
	sf::Text text;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;
	GameObject backgroundobj;
	//animation object for the background
	Animation background;
	sf::Texture backgroundtexture;


};