#include "Text.h"

//klasa odp za przechowywanie tekstu wyswietlanego na scenie 
Text::Text(sf::Font * font, std::string text, int textSize, sf::Color color, sf::Text::Style styl, sf::Vector2f centerPosition) : centerPosition(centerPosition)
{
	this->text.setFont(*font);
	this->text.setString(text);
	this->text.setStyle(styl);
	this->text.setCharacterSize(textSize);
	this->SetColor(color);
	this->SetCenterPosition(centerPosition);
}

void Text::SetColor(sf::Color color)
{
	this->text.setFillColor(color);
}

void Text::SetSize(int textSize)
{
	this->text.setCharacterSize(textSize);
}

void Text::SetCenterPosition(sf::Vector2f centerPosition)
{
	this->centerPosition = centerPosition;
	this->Reposition();
}

sf::FloatRect Text::GetGlobalBounds()
{
	return this->text.getGlobalBounds();
}

void Text::SetText(std::string text)
{
	this->text.setString(text);
}

void Text::SetStyle(sf::Text::Style styl)
{
	this->text.setStyle(styl);
}

void Text::Render()
{
	this->gameData->renderWindow.draw(this->text);
}

void Text::Reposition()
{
	this->text.setPosition(sf::Vector2f(this->centerPosition.x - this->text.getGlobalBounds().width / 2, this->centerPosition.y - this->text.getGlobalBounds().height / 2));
}