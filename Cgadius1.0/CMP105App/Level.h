///////////////////////////////               LEVEL.H                           /////////////////////////////////////
///////////////////////////////               COMMENTING COMPLETE               /////////////////////////////////////

#pragma once
// .h includes
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Framework/Input.h"
#include "Framework/Collision.h"
#include "Framework/AudioManager.h"
#include "AsteroidManager.h"
#include "WallManager.h"
#include "EnemyManager.h"
#include "BulletManager.h"
#include "Framework/GameState.h"
#include "Asteroid.h"
#include "Enemy.h"
#include "Wall.h"
#include "Player.h"
// library includes
#include <string>

// Main level class for the game
class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState *state);
	~Level();

	// Handling any input from the user
	void handleInput(float dt);
	// Updating the view and updating all the manager classes
	void update(float dt);
	// Renders all the objects from every class
	void render();
	// For the level timer so it only begins once the user enters the level and not on menu at the beginning
	bool clockstarted =false;

private:
	// Default functions for rendering to the screen.. Thanks Paul!
	void beginDraw();
	void endDraw();
	// Used in the game state changes from menu to level, level to credits
	GameState* gameState;
	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	// View objects for the main screen and the top of the screen ofr scoring,timer etc
	sf::View view1;
	sf::View scoreview;
	// Sound+Music
	AudioManager audioManager;
	// Background
	GameObject background;
	sf::Texture backgroundtexture;
	// Player
	Player player;
	sf::Texture playertexture;
	// Enemy
	sf::Texture enemytexture;
	
	// Objects used for the getters in the managers to get access to other manangers vectors
	AsteroidManager asteroidManager;
	WallManager wallManager;
	EnemyManager enemyManager;
	BulletManager bulletManager;
	
	// Text
	sf::Font font;
	sf::Text score;
	sf::Text time;
	sf::Text timer;
	// Unable to get this drawing. Probably missing something simple
	sf::Text pauseText;
	sf::Clock clock;
	sf::Time time1;
	// Used for clock
	float seconds;
	
};