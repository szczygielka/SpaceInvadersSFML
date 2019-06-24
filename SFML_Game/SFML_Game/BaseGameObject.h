#ifndef BASE_RENDER_OBJECT_H
#define BASE_RENDER_OBJECT_H

#include <SFML/Graphics.hpp>
#include "GameData.h"

class BaseGameObject
{
protected:
	GameData * gameData;

public:
	BaseGameObject();
	~BaseGameObject();

	virtual void Render() = 0;
};

#endif