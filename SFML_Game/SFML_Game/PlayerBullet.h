#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H

#include "Bullet.h"
class PlayerBullet :
	public Bullet
{
public:
	PlayerBullet(sf::Vector2f startPo);
	~PlayerBullet();
};

#endif
