#ifndef BASE_MENU_STATE_H
#define BASE_MENU_STATE_H

#include "State.h"
#include "Background.h"
#include "GameData.h"

class BaseMenuState :
	public State
{
protected:
	GameData * gameData;
	Background * background;

	int buttonSelected;
public:
	BaseMenuState();
	~BaseMenuState();

	void virtual Init() = 0;
	void virtual HandleInput() = 0;
	void virtual Update(float dt) = 0;
	void virtual Render() = 0;
};

#endif

