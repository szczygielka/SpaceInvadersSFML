#ifndef LIFE_BAR_H
#define LIFE_BAR_H

#include "BaseGameObject.h"
#include <string>
#include <vector>
#include "Life.h"

class Lifebar : public BaseGameObject
{
	std::vector< std::shared_ptr<Life>> lifes;
	std::vector<std::shared_ptr<Life>>::iterator lifesIterator;
	bool leftOrder; //tworz w lewa strone, znikaj z prawej 
	sf::Vector2f position;

public:
	Lifebar(sf::Vector2f position, bool leftOrder);
	~Lifebar();
	void RemoveOneLife();
	void Render();
	int GetLifesCount();
};

#endif