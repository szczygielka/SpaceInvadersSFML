#include "TextureObject.h"


TextureObject::TextureObject(sf::Texture * texture, bool active, sf::Vector2f startPos, sf::Vector2f spriteSize) 
	: spriteSize(spriteSize), active(active)
{
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(startPos.x, startPos.y);
	this->Resize();
}

TextureObject::~TextureObject()
{
}

void TextureObject::Render()
{
	if (this->active)
	{
		this->gameData->renderWindow.draw(this->sprite);
	}
}

void TextureObject::Resize()
{
	sf::Vector2f spriteSize = sf::Vector2f(this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().height);
	this->sprite.setScale(this->spriteSize.x / spriteSize.x, this->spriteSize.y / spriteSize.y);
}

sf::FloatRect TextureObject::GetGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}

void TextureObject::SetPosition(sf::Vector2f pos)
{
	this->sprite.setPosition(pos.x, pos.y);
}

sf::Vector2f TextureObject::GetPosition()
{
	return this->sprite.getPosition();
}

void TextureObject::SetTextureSize(sf::Vector2f textureSize)
{
	this->spriteSize = spriteSize;
	this->Resize();
}

sf::Vector2f TextureObject::GetTextureSize()
{
	return this->spriteSize;
}

void TextureObject::Move(sf::Vector2f offset)
{
	this->sprite.move(offset);
}


void TextureObject::SetActive(bool active)
{
	this->active = active;
}

bool TextureObject::GetActive()
{
	return this->active;
}
