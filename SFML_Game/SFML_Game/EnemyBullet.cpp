#include "EnemyBullet.h"


EnemyBullet::EnemyBullet(sf::Vector2f startPos)
	: Bullet(GameData::getInstance()->texturesManager.Get(GET_VARIABLE_NAME(bulletEnemyTexture)),
		true, startPos, GameData::getInstance()->config.enemyBulletSize, GameData::getInstance()->config.enemyBulletVelocity)
{
}

EnemyBullet::~EnemyBullet()
{
}


