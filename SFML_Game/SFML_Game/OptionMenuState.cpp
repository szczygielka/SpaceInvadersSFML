#include "OptionMenuState.h"

OptionMenuState::OptionMenuState()
{
	this->background = new Background(this->gameData->texturesManager.Get(GET_VARIABLE_NAME(optionsMenuBackground)));

	this->closeButtonText = new Text(this->gameData->fontsManager.Get(GET_VARIABLE_NAME(menuFont)), this->gameData->config.optionsMenuCloseButtonText,
		this->gameData->config.menuButtonsSize, this->gameData->config.menuButtonNotSelectedColor, this->gameData->config.menuButtonsStyle, sf::Vector2f(0, 0));

	std::string twoPlayersText = this->gameData->config.optionsMenuSecondPlayerOffText;
	if (this->gameData->player2On)
	{
		twoPlayersText = this->gameData->config.optionsMenuSecondPlayerOnText;
	}
	this->playersCountChangeButtonText = new Text(this->gameData->fontsManager.Get(GET_VARIABLE_NAME(menuFont)), twoPlayersText,
		this->gameData->config.menuButtonsSize, this->gameData->config.menuButtonNotSelectedColor, this->gameData->config.menuButtonsStyle, sf::Vector2f(0, 0));
}

void OptionMenuState::Init()
{
	sf::Vector2f windowsSize = sf::Vector2f((float)this->gameData->view.getSize().x, (float)this->gameData->view.getSize().y);

	//ustawianie pozycji tekstów
	this->playersCountChangeButtonText->SetCenterPosition(
		sf::Vector2f(windowsSize.x / 2, (float)this->gameData->view.getSize().y / 2 - playersCountChangeButtonText->GetGlobalBounds().height));

	this->closeButtonText->SetCenterPosition(
		sf::Vector2f(windowsSize.x / 2, (float)this->gameData->view.getSize().y / 2 + closeButtonText->GetGlobalBounds().height));
}


OptionMenuState::~OptionMenuState()
{
	delete this->background;
	delete this->closeButtonText;
}

void OptionMenuState::Render()
{
	this->background->Render();
	this->closeButtonText->Render();
	this->playersCountChangeButtonText->Render();

}

void OptionMenuState::HandleInput()
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
				if (this->closeButtonId == this->buttonSelected)
				{
					this->gameData->stateMachine.RemoveState();
				}
				else if (this->playersCountChangeButtonId == this->buttonSelected)
				{
					if (this->gameData->player2On)
					{
						this->playersCountChangeButtonText->SetText(this->gameData->config.optionsMenuSecondPlayerOffText);
						this->gameData->player2On = false;
					}
					else
					{
						this->playersCountChangeButtonText->SetText(this->gameData->config.optionsMenuSecondPlayerOnText);
						this->gameData->player2On = true;
					}
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

void OptionMenuState::Update(float dt)
{
	if (this->closeButtonId == this->buttonSelected)
	{
		this->closeButtonText->SetColor(this->gameData->config.menuButtonSelectedColor);
		this->playersCountChangeButtonText->SetColor(this->gameData->config.menuButtonNotSelectedColor);
	}
	else if (this->playersCountChangeButtonId == this->buttonSelected)
	{
		this->closeButtonText->SetColor(this->gameData->config.menuButtonNotSelectedColor);
		this->playersCountChangeButtonText->SetColor(this->gameData->config.menuButtonSelectedColor);
	}
}