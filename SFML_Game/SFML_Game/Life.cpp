#include "Life.h"


Life::Life(sf::Vector2f startPos)
	: TextureObject(GameData::getInstance()->texturesManager.Get(GET_VARIABLE_NAME(lifeTexture)), 
		true, startPos, GameData::getInstance()->config.lifeSize)
{
}

Life::~Life()
{
}

