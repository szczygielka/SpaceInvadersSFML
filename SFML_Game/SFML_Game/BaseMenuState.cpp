#include "BaseMenuState.h"



BaseMenuState::BaseMenuState()
{
	this->gameData = GameData::getInstance();

	this->buttonSelected = 0;
}


BaseMenuState::~BaseMenuState()
{

}