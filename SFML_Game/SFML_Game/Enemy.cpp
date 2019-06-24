#include "Enemy.h"


Enemy::Enemy(sf::Vector2f startPos)
	: BaseMovableObject(GameData::getInstance()->texturesManager.Get(GET_VARIABLE_NAME(enemyTexture)),
		true, startPos, GameData::getInstance()->config.enemySize, GameData::getInstance()->config.enemyVelocity)
{
}

Enemy::~Enemy()
{
}
//w pozimie
void Enemy::Update(float dt)
{
	this->sprite.move(this->velocity.x * dt, 0.0f);
}

void Enemy::UpdateVerticaly(float dt)
{
	this->sprite.move(0.0f, this->velocity.y * dt);

}

