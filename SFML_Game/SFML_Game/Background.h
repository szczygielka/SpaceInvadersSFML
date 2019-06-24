#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "TextureObject.h"


class Background : public TextureObject
{
public:
	Background(sf::Texture * texture);
	~Background();
};

#endif
