#include "Lifebar.h"

Lifebar::Lifebar(sf::Vector2f position, bool leftOrder) : leftOrder(leftOrder), position(position)
{
	float order = 1;
	if (!leftOrder) //jezeli  
	{
		order = -1; //wstawianie od prawej 
	}

	for (int i = 0; i < this->gameData->config.playerLifes; i++)
	{
		this->lifes.push_back(std::shared_ptr<Life>(
			new Life(sf::Vector2f(this->position.x - i * order * (this->gameData->config.lifeSize.x + this->gameData->config.lifeLifebarGap), 
				this->position.y))));
	}
}


Lifebar::~Lifebar()
{
}

void Lifebar::RemoveOneLife()
{
	if (this->lifes.size() > 0) //jezeli sa jakies zycia 
	{
		this->lifesIterator = this->lifes.end() - 1; //ustawienie na koniec
		this->lifesIterator = this->lifes.erase(lifesIterator);
	}
}

void Lifebar::Render()
{
	for (this->lifesIterator = this->lifes.begin(); lifesIterator != this->lifes.end(); ++lifesIterator)
	{
		(*this->lifesIterator)->Render();
	}
}

int Lifebar::GetLifesCount()
{
	return this->lifes.size();
}
