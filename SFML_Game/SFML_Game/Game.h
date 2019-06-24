#ifndef GAME_H
#define GAME_H


#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "GameData.h"
#include "GameState.h"
#include "GameData.h"
#include "Constants.h"
#include "MainMenuState.h"
#include <iostream>


class Game
{
public:
	Game();
	void Run();

private:
	GameData * gameData;

};

#endif