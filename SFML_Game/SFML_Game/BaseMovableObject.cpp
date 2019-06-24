#include "BaseMovableObject.h"


BaseMovableObject::BaseMovableObject(sf::Texture * texture, bool active, sf::Vector2f startPos, sf::Vector2f spriteSize, sf::Vector2f velocity)
	: TextureObject(texture, active, startPos, spriteSize), velocity(velocity)
{
}

BaseMovableObject::~BaseMovableObject()
{
}

void BaseMovableObject::SetVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}
