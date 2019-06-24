#ifndef TEXTURE_OBJECT_H
#define TEXTURE_OBJECT_H

#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "BaseGameObject.h"

class TextureObject : public BaseGameObject
{
protected:
	sf::Sprite sprite;
	sf::Vector2f spriteSize;
	bool active;

public:
	TextureObject(sf::Texture * texture, bool active, sf::Vector2f startPos, sf::Vector2f spriteSize);
	~TextureObject();

	void Render();

	sf::FloatRect GetGlobalBounds();

	void SetPosition(sf::Vector2f pos);
	sf::Vector2f GetPosition();

	void SetTextureSize(sf::Vector2f textureSize);
	sf::Vector2f GetTextureSize();

	void Move(sf::Vector2f offset);

	void Resize();
	void SetActive(bool active);
	bool GetActive();

};



#endif