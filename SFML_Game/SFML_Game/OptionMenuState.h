#ifndef OPTION_MENU_STATE_H
#define OPTION_MENU_STATE_H

#include <SFML/Graphics/Text.hpp>
#include "Constants.h"
#include "Text.h"
#include "BaseMenuState.h"


class OptionMenuState : public BaseMenuState
{
public:
	OptionMenuState();
	~OptionMenuState();
	void Init();
	void HandleInput();
	void Update(float dt);
	void Render();

private:

	// Do zmiany na klase MenuButton i MenuButtonManager
	Text * closeButtonText;
	int closeButtonId = 1;
	Text * playersCountChangeButtonText;
	int playersCountChangeButtonId = 0;

};


#endif