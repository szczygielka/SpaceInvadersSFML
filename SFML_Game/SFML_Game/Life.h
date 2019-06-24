#ifndef LIFE_H
#define LIFE_H

#include "TextureObject.h"


class Life :
	public TextureObject
{
public:
	Life(sf::Vector2f startPos);
	~Life();
};

#endif

