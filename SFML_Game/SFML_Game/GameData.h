#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "Constants.h"
#include <memory>
#include "Config.h"

//klasa odp za stan gry, singleton 
class GameData
{
	static GameData * instance;
	GameData();

public:

	AssetManager<sf::Texture> texturesManager;
	AssetManager<sf::Font> fontsManager;
	sf::RenderWindow renderWindow;
	sf::View view;
	StateMachine stateMachine;

	Config config;
	bool gameIsRunning;
	bool player2On;

	static GameData * getInstance();

	void LoadMenuAssets();
	void LoadGameAssets();
};




#endif