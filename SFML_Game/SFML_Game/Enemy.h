#ifndef ENEMY_H
#define ENEMY_H

#include "BaseMovableObject.h"
#include "Bullet.h"
#include "EnemyBullet.h"
class Enemy :
	public BaseMovableObject
{

public:
	Enemy(sf::Vector2f startPos);
	~Enemy();
	void Update(float dt);
	void UpdateVerticaly(float dt);
};

#endif
