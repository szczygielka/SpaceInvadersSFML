#include "PauseState.h"

PauseState::PauseState()
{
	this->background = new Background(this->gameData->texturesManager.Get(GET_VARIABLE_NAME(pauseMenuBackground)));

	this->resumeButtonText = new Text(this->gameData->fontsManager.Get(GET_VARIABLE_NAME(menuFont)), this->gameData->config.pauseMenuResumeButtonText,
		this->gameData->config.menuButtonsSize, this->gameData->config.menuButtonNotSelectedColor, this->gameData->config.menuButtonsStyle, sf::Vector2f(0, 0));

	this->exitGameButtonText = new Text(this->gameData->fontsManager.Get(GET_VARIABLE_NAME(menuFont)), this->gameData->config.pauseMenuExitGameButtonText,
		this->gameData->config.menuButtonsSize, this->gameData->config.menuButtonNotSelectedColor, this->gameData->config.menuButtonsStyle, sf::Vector2f(0, 0));
}

PauseState::~PauseState()
{
	delete this->background;
	delete this->resumeButtonText;
	delete this->exitGameButtonText;
}

void PauseState::Init()
{
	


	sf::Vector2f windowsSize = sf::Vector2f((float)this->gameData->view.getSize().x, (float)this->gameData->view.getSize().y);

	//ustawianie pozycji tekstów
	this->resumeButtonText->SetCenterPosition(
		sf::Vector2f(windowsSize.x / 2,
		(float)this->gameData->view.getSize().y / 2 - resumeButtonText->GetGlobalBounds().height));

	this->exitGameButtonText->SetCenterPosition(
		sf::Vector2f(windowsSize.x / 2,
		(float)this->gameData->view.getSize().y / 2 + exitGameButtonText->GetGlobalBounds().height));

}

void PauseState::Render()
{
	this->background->Render();
	this->resumeButtonText->Render();
	this->exitGameButtonText->Render();
}


void PauseState::HandleInput()
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
			switch (evt.key.code)
			{
			case sf::Keyboard::Up:
				this->buttonSelected--;
				break;
			case sf::Keyboard::Down:
				this->buttonSelected++;
				break;
			case sf::Keyboard::Enter:
				if (this->resumeButtonId == this->buttonSelected)
				{
					this->gameData->stateMachine.RemoveState();
				}
				else if (this->exitGameButtonId == this->buttonSelected)
				{
					this->gameData->gameIsRunning = false;
					this->gameData->stateMachine.RemoveState();
				}
			default:
				break;
			}

			if (this->buttonSelected > 1)
			{
				this->buttonSelected = 0;
			}
			if (this->buttonSelected < 0)
			{
				this->buttonSelected = 1;
			}
		}
	}
}

void PauseState::Update(float dt)
{
	if (this->resumeButtonId == this->buttonSelected)
	{
		this->resumeButtonText->SetColor(this->gameData->config.menuButtonSelectedColor);
		this->exitGameButtonText->SetColor(this->gameData->config.menuButtonNotSelectedColor);
	}
	else if (this->exitGameButtonId == this->buttonSelected)
	{
		this->resumeButtonText->SetColor(this->gameData->config.menuButtonNotSelectedColor);
		this->exitGameButtonText->SetColor(this->gameData->config.menuButtonSelectedColor);
	}
}