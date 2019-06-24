#ifndef BASE_MOVABLE_OBJECT_H
#define BASE_MOVABLE_OBJECT_H

#include "TextureObject.h"


class BaseMovableObject :
	public TextureObject
{
protected:
	sf::Vector2f velocity;
public:
	BaseMovableObject(sf::Texture * texture, bool active, sf::Vector2f startPos, sf::Vector2f spriteSize, sf::Vector2f velocity);
	~BaseMovableObject();

	void SetVelocity(sf::Vector2f velocity);
	void virtual Update(float dt) = 0;


};

#endif