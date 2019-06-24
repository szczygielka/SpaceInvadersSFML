#ifndef BULLET_H
#define BULLET_H

#include "BaseMovableObject.h"
class Bullet :
	public BaseMovableObject
{
public:
	Bullet(sf::Texture * texture, bool active, sf::Vector2f startPos, sf::Vector2f spriteSize, sf::Vector2f velocity);
	~Bullet();

	void Update(float dt);
};

#endif
