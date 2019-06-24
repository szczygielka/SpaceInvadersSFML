#include "PlayerBullet.h"


PlayerBullet::PlayerBullet(sf::Vector2f startPos)
	: Bullet(GameData::getInstance()->texturesManager.Get(GET_VARIABLE_NAME(bulletPlayerTexture)), true, startPos,
		GameData::getInstance()->config.playerBulletSize, GameData::getInstance()->config.playerBulletVelocity)
{
}

PlayerBullet::~PlayerBullet()
{
}