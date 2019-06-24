#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "BaseGameObject.h"

class Text : public BaseGameObject
{
protected:
	sf::Vector2f centerPosition;

public:
	Text(sf::Font * font, std::string text, int textSize, sf::Color color, sf::Text::Style styl, sf::Vector2f centerPosition);

	void SetColor(sf::Color color);
	void SetSize(int textSize);
	void SetText(std::string text);
	void SetStyle(sf::Text::Style styl);
	void SetCenterPosition(sf::Vector2f pos);
	void Reposition();
	void Render();
	sf::FloatRect GetGlobalBounds();

protected:
	sf::Text text;
};

#endif;