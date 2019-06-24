#include "Game.h"

Game::Game()
{
	this->gameData = GameData::getInstance();

	this->gameData->config.ReadConfig();

	this->gameData->renderWindow.create(sf::VideoMode((unsigned int)this->gameData->config.windowSize.x,
		(unsigned int)this->gameData->config.windowSize.y), this->gameData->config.gameTitle);

	this->gameData->view.reset(sf::FloatRect(0.0f, 0.0f, (float)this->gameData->config.windowSize.x, (float)this->gameData->config.windowSize.y));


	this->gameData->renderWindow.setView(this->gameData->view);
	this->gameData->view.setCenter(sf::Vector2f(this->gameData->config.windowSize.x / 2, this->gameData->config.windowSize.y / 2));

	this->gameData->LoadMenuAssets();
	this->gameData->renderWindow.setFramerateLimit(this->gameData->config.framePerSec);
	std::shared_ptr < State > mainMenuState(new MainMenuState());
	this->gameData->stateMachine.AddState(mainMenuState);
}


void Game::Run()
{
	sf::Clock lastRenderTime;
	lastRenderTime.restart();

	while (this->gameData->renderWindow.isOpen())
	{
		this->gameData->stateMachine.ProcessStateChanges(); //sprawdzanie czy stan ma byc dodany/usuniety

		this->gameData->stateMachine.GetActiveState()->HandleInput(); //³apanie przycisków

		this->gameData->stateMachine.GetActiveState()->Update(lastRenderTime.restart().asSeconds());

		this->gameData->renderWindow.clear(sf::Color::Black);
		this->gameData->stateMachine.GetActiveState()->Render(); //aktualizacja co okreœlon¹ klatkê 
		this->gameData->renderWindow.display();

	}
}

