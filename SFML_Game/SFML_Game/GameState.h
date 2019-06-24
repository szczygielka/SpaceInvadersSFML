#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Background.h"
#include "Player.h"
#include "Bullet.h"
#include "Life.h"
#include "Lifebar.h"
#include "Enemy.h"
#include <vector>
#include <stdlib.h>  
#include "Points.h"
#include "EndGameState.h"
#include "GameCollisionManager.h"
#include "GamePositionManager.h"
class GameState : public State
{
public:
	GameState();
	~GameState();

	void Init();

	void HandleInput();
	void Update(float dt);

	void Render();

private:
	GameData * gameData;
	Background * background;
	GamePositionManager * gamePositionManager;

	GameCollisionManager * gameCollisionManager;

	std::vector< std::shared_ptr<Player > >::iterator playersIterator;
	std::vector< std::shared_ptr<Lifebar> >::iterator lifebarsIterator;
	std::vector< std::shared_ptr<Bullet > >::iterator bulletsIterator;

	std::vector< std::vector<std::shared_ptr<Enemy > > >::iterator enemiesYIterator;
	std::vector< std::shared_ptr<Enemy> > ::iterator enemiesXIterator;


	std::vector< std::shared_ptr<Player > > players;
	std::vector< std::shared_ptr<Lifebar> > lifebars;
	std::vector< std::shared_ptr<Bullet > > bullets;

	std::vector < std::vector<std::shared_ptr<Enemy > > > enemys;

	Points points;

	void InitPlayers();
	void InitLifebars();
	void InitEnemies();

	
	void ChcekGameFinish();
};
#endif

