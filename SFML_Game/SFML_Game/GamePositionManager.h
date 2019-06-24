#ifndef GAME_POSITION_MANAGER_H
#define GAME_POSITION_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <vector>
#include "Points.h"
#include "Lifebar.h"

class GamePositionManager
{
	std::vector< std::shared_ptr<Player > >::iterator playersIterator;
	std::vector< std::shared_ptr<Bullet > >::iterator bulletsIterator;
	std::vector< std::vector<std::shared_ptr<Enemy > > >::iterator enemiesYIterator;
	std::vector< std::shared_ptr<Enemy> > ::iterator enemiesXIterator;

	std::vector< std::shared_ptr<Player > > & players;
	std::vector< std::shared_ptr<Bullet > > & bullets;
	std::vector < std::vector<std::shared_ptr<Enemy > > > & enemys;

	GameData * gameData;

	void UpdatePlayers(float dt);
	void UpdateBullets(float dt);
	void UpdateEnemies(float dt);

	void UpdateEnemiesPosition(float dt);
	void UpdateEnemiesActivity(float dt);
	void UpdateEnemiesShooting(float dt);

	void ChcekBulletsPositions();

	void RemoveDisactiveBullets();

	sf::Time moveEnemyPeriod;
	sf::Clock lastMoveEnemyTime;
	//true - w lewo, false - w prawo
	bool enemyMoveRight;

	sf::Time shootEnemyPeriod;
	sf::Clock lastShootEnemyTime;

public:
	GamePositionManager(std::vector<std::shared_ptr<Player>> & players,
		std::vector<std::shared_ptr<Bullet>> & bullets,
		std::vector<std::vector<std::shared_ptr<Enemy>>> & enemys);
	~GamePositionManager();

	void Update(float dt);
	void Init();
	bool IsEnemiesGetPlayerLine();
};


#endif
