#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H


#include <SFML/Graphics/Text.hpp>
#include "BaseMenuState.h"
#include "Text.h"


class PauseState : public BaseMenuState
{
public:
	PauseState();
	~PauseState();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Render();

private:
	// Do zmiany na klase MenuButton i MenuButtonManager
	Text * resumeButtonText;
	int resumeButtonId = 0;
	Text * exitGameButtonText;
	int exitGameButtonId = 1;

};


#endif
