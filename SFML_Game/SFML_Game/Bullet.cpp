#include "Bullet.h"


Bullet::Bullet(sf::Texture * texture, bool active, sf::Vector2f startPos, sf::Vector2f spriteSize, sf::Vector2f velocity)
	: BaseMovableObject(texture, active, startPos, spriteSize, velocity)
{
}

Bullet::~Bullet()
{
}

void Bullet::Update(float dt)
{
	this->sprite.move(this->velocity.x * dt, this->velocity.y * dt);
}