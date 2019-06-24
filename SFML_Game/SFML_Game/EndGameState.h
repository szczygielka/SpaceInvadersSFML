#ifndef END_GAME_STATE_H
#define END_GAME_STATE_H

#include "BaseMenuState.h"
#include "Points.h"

class EndGameState :
	public BaseMenuState
{
public:
	EndGameState(int points, bool winGame = false);
	~EndGameState();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Render();

private:
	bool winGame;
	int pointsCount;
	Points points;
	Text * endGameText;

};

#endif