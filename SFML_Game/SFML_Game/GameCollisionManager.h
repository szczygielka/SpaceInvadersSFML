#ifndef GAME_COLLISTION_MANAGER_H
#define GAME_COLLISTION_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <vector>
#include "Points.h"
#include "Lifebar.h"

class GameCollisionManager
{
	std::vector< std::shared_ptr<Player > >::iterator playersIterator;
	std::vector< std::shared_ptr<Bullet > >::iterator bulletsIterator;
	std::vector< std::vector<std::shared_ptr<Enemy > > >::iterator enemiesYIterator;
	std::vector< std::shared_ptr<Enemy> > ::iterator enemiesXIterator;
	std::vector< std::shared_ptr<Lifebar> >::iterator lifebarsIterator;


	std::vector< std::shared_ptr<Player > > & players;
	std::vector< std::shared_ptr<Bullet > > & bullets;
	std::vector < std::vector<std::shared_ptr<Enemy > > > & enemys;
	std::vector< std::shared_ptr<Lifebar> > & lifebars;

	GameData * gameData;

	Points & points;

public:
	GameCollisionManager(std::vector< std::shared_ptr<Player > > & players,
		std::vector< std::shared_ptr<Bullet > > & bullets,
		std::vector < std::vector<std::shared_ptr<Enemy > > > & enemys, Points & points,
		std::vector< std::shared_ptr<Lifebar> > & lifebars);
	~GameCollisionManager();

	void CheckCollisions();
};


#endif
