#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include <SFML/Graphics/Text.hpp>
#include "Constants.h"
#include "Text.h"
#include "GameState.h"
#include "OptionMenuState.h"
#include "BaseMenuState.h"


// TODO: klasa bazowa z Menu 
// Stworzyc klase Menu z funkcj¹ HandleInput wywo³uj¹c¹ funkcjê odpowiedzaln¹ za nacisniecie konkretnego przycisku 
class MainMenuState : public BaseMenuState
{
public:
	MainMenuState();
	~MainMenuState();
	void Init();
	void HandleInput();
	void Update(float dt);
	void Render();

private:

	// Do zmiany na klase MenuButton i MenuButtonManager
	Text * playButtonText;
	int playButtonId = 0;
	Text * optionsButtonText;
	int optionsButtonId = 1;
	Text * closeButtonText;
	int closeButtonId = 2;
};

#endif