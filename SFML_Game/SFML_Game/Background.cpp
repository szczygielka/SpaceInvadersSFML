#include "Background.h"

Background::Background(sf::Texture * texture)
	: TextureObject(texture, true, sf::Vector2f(0.0f, 0.0f),
		sf::Vector2f((float)GameData::getInstance()->view.getSize().x, 
		(float)GameData::getInstance()->view.getSize().y))
{
}

Background::~Background()
{
}
