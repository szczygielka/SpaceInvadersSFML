#include "MainMenuState.h"



MainMenuState::~MainMenuState()
{
	delete this->background;
	delete this->playButtonText;
	delete this->optionsButtonText;
	delete this->closeButtonText;
}

MainMenuState::MainMenuState()
{
	this->background = new Background(this->gameData->texturesManager.Get(GET_VARIABLE_NAME(mainMenuBackground)));

	this->playButtonText = new Text(this->gameData->fontsManager.Get(GET_VARIABLE_NAME(menuFont)), this->gameData->config.mainMenuPlayButtonText,
		this->gameData->config.menuButtonsSize, this->gameData->config.menuButtonNotSelectedColor, this->gameData->config.menuButtonsStyle, sf::Vector2f(0, 0));

	this->optionsButtonText = new Text(this->gameData->fontsManager.Get(GET_VARIABLE_NAME(menuFont)), this->gameData->config.mainMenuOptionsButtonText,
		this->gameData->config.menuButtonsSize, this->gameData->config.menuButtonNotSelectedColor, this->gameData->config.menuButtonsStyle, sf::Vector2f(0, 0));

	this->closeButtonText = new Text(this->gameData->fontsManager.Get(GET_VARIABLE_NAME(menuFont)), this->gameData->config.mainMenuCloseButtonText,
		this->gameData->config.menuButtonsSize, this->gameData->config.menuButtonNotSelectedColor, this->gameData->config.menuButtonsStyle, sf::Vector2f(0, 0));
}

void MainMenuState::Init()
{
	sf::Vector2f windowsSize = sf::Vector2f((float)this->gameData->view.getSize().x, (float)this->gameData->view.getSize().y);
	float optionButtonHeight = this->optionsButtonText->GetGlobalBounds().height;

	//ustawianie pozycji tekstów
	this->playButtonText->SetCenterPosition(
		sf::Vector2f(windowsSize.x / 2,
		(float)this->gameData->view.getSize().y / 2 - (float)this->optionsButtonText->GetGlobalBounds().height));

	this->optionsButtonText->SetCenterPosition(sf::Vector2f(windowsSize.x / 2, windowsSize.y / 2));

	this->closeButtonText->SetCenterPosition(
		sf::Vector2f(windowsSize.x / 2,
		(float)this->gameData->view.getSize().y / 2 + (float)this->optionsButtonText->GetGlobalBounds().height));
}


//generowanie sceny i wyswietlanie
void MainMenuState::Render()
{
	this->background->Render();
	this->playButtonText->Render();
	this->optionsButtonText->Render();
	this->closeButtonText->Render();

}


void MainMenuState::HandleInput()
{
	//zmienna przechowujaca zdarzenia 
	sf::Event evt;


	//pollEvent zwraca 0 jezeli nie bylo eventu
	if (this->gameData->renderWindow.pollEvent(evt))
	{
		if (sf::Event::Closed == evt.type) //sprawdzenie czy ktos nie wcisnal zamkniecia okna X
		{
			this->gameData->renderWindow.close();
		}
		if (sf::Event::KeyPressed == evt.type) //spr czy zostal ncisniety przycisk
		{
			switch (evt.key.code) //(evt.key.code < int,bo enum?
			{
			case sf::Keyboard::Up:
				this->buttonSelected--;
				break;
			case sf::Keyboard::Down:
				this->buttonSelected++;
				break;
			case sf::Keyboard::Enter:
				if (this->playButtonId == this->buttonSelected)
				{
					this->gameData->LoadGameAssets();
					this->gameData->gameIsRunning = true;

					std::shared_ptr < State > gameState(new GameState());

					this->gameData->stateMachine.AddState(gameState);
				}
				else if (this->optionsButtonId == this->buttonSelected)
				{
					std::shared_ptr < State > optionMenuState(new OptionMenuState());

					this->gameData->stateMachine.AddState(optionMenuState);

				}
				else if (this->closeButtonId == this->buttonSelected)
				{
					//render Window - zmienna z SFML przechowuje okno 
					this->gameData->renderWindow.close();

				}
			default:
				break;
			}
			//zapetlanie
			if (this->buttonSelected > 2)
			{
				this->buttonSelected = 0;
			}
			if (this->buttonSelected < 0)
			{
				this->buttonSelected = 2;
			}
		}
	}
}
//update koloru na aktualnym przycisku 
void MainMenuState::Update(float dt)
{
	if (this->playButtonId == this->buttonSelected)
	{
		this->playButtonText->SetColor(this->gameData->config.menuButtonSelectedColor);
		this->optionsButtonText->SetColor(this->gameData->config.menuButtonNotSelectedColor);
		this->closeButtonText->SetColor(this->gameData->config.menuButtonNotSelectedColor);
	}
	else if (this->optionsButtonId == this->buttonSelected)
	{
		this->playButtonText->SetColor(this->gameData->config.menuButtonNotSelectedColor);
		this->optionsButtonText->SetColor(this->gameData->config.menuButtonSelectedColor);
		this->closeButtonText->SetColor(this->gameData->config.menuButtonNotSelectedColor);
	}
	else if (this->closeButtonId == this->buttonSelected)
	{
		this->playButtonText->SetColor(this->gameData->config.menuButtonNotSelectedColor);
		this->optionsButtonText->SetColor(this->gameData->config.menuButtonNotSelectedColor);
		this->closeButtonText->SetColor(this->gameData->config.menuButtonSelectedColor);

	}
}


