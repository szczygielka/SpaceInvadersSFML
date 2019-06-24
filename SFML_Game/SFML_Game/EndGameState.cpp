#include "EndGameState.h"


EndGameState::EndGameState(int points, bool winGame) : winGame(winGame), pointsCount(points)
{
	if (this->winGame)
	{
		this->background = new Background(this->gameData->texturesManager.Get(GET_VARIABLE_NAME(endGameStateWinBackground)));
		this->endGameText = new Text(this->gameData->fontsManager.Get(GET_VARIABLE_NAME(menuFont)), this->gameData->config.endGameScreenWinText,
			this->gameData->config.endGameScreenTextSize, this->gameData->config.endGameScreenTextColor, this->gameData->config.endGameScreenTextStyle, 
			this->gameData->config.endGameScreenTextPosition);
	}
	else
	{
		this->background = new Background(this->gameData->texturesManager.Get(GET_VARIABLE_NAME(endGameStateLossBackground)));
		this->endGameText = new Text(this->gameData->fontsManager.Get(GET_VARIABLE_NAME(menuFont)), this->gameData->config.endGameScreenLossText,
			this->gameData->config.endGameScreenTextSize, this->gameData->config.endGameScreenTextColor, this->gameData->config.endGameScreenTextStyle, 
			this->gameData->config.endGameScreenTextPosition);
	}
	this->points.Set(this->pointsCount);
	this->points.SetCenterPosition(this->gameData->config.endGameScreenPointsPosition);
	this->points.SetSize(this->gameData->config.endGameScreenPointsSize);
	this->points.SetColor(this->gameData->config.endGameScreenPointsColor);
	this->points.SetStyle(this->gameData->config.endGameScreenPointsStyle);

	
}

EndGameState::~EndGameState()
{
}

void EndGameState::Init()
{
	
}

void EndGameState::HandleInput()
{
	sf::Event evt;

	if (this->gameData->renderWindow.pollEvent(evt)) 
	{
		if (sf::Event::Closed == evt.type) 
		{
			this->gameData->renderWindow.close();
		}

		if (sf::Event::KeyPressed == evt.type) 
		{

			if (evt.key.code == sf::Keyboard::Enter)
			{
				this->gameData->gameIsRunning = false;
				this->gameData->stateMachine.RemoveState();
			}
		}
	}
}

void EndGameState::Update(float dt)
{
}

void EndGameState::Render()
{
	this->gameData->renderWindow.clear(sf::Color::Black);
	this->background->Render();
	this->points.Render();
	this->endGameText->Render();
}

