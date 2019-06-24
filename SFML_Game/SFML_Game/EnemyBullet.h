#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H

#include "Bullet.h"
class EnemyBullet :
	public Bullet
{
public:
	EnemyBullet(sf::Vector2f startPos);
	~EnemyBullet();
};
#endif
