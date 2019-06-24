#include "GameData.h"

GameData* GameData::instance = 0;

GameData::GameData()
{
	this->texturesManager = AssetManager<sf::Texture>();
	this->fontsManager = AssetManager<sf::Font>();
	this->gameIsRunning = false;
	this->player2On = this->config.player2DefaultOn;
}

GameData * GameData::getInstance()
{
	if (GameData::instance == 0)
	{
		GameData::instance = new GameData();
	}
	return GameData::instance;
}

void GameData::LoadMenuAssets()
{
	texturesManager.Load(GET_VARIABLE_NAME(mainMenuBackground), this->config.mainMenuBackground);

	texturesManager.Load(GET_VARIABLE_NAME(optionsMenuBackground), this->config.optionsMenuBackground);

	texturesManager.Load(GET_VARIABLE_NAME(pauseMenuBackground), this->config.pauseMenuBackground);
	
	fontsManager.Load(GET_VARIABLE_NAME(menuFont), this->config.menuFont);

	fontsManager.Load(GET_VARIABLE_NAME(pointsFont), this->config.pointsFont);

}

void GameData::LoadGameAssets()
{
	texturesManager.Load(GET_VARIABLE_NAME(gameBackground), this->config.gameBackground);

	texturesManager.Load(GET_VARIABLE_NAME(endGameStateWinBackground), this->config.endGameStateWinBackground);
	
	texturesManager.Load(GET_VARIABLE_NAME(endGameStateLossBackground), this->config.endGameStateLossBackground);
	
	texturesManager.Load(GET_VARIABLE_NAME(gamePlayer1Texture), this->config.gamePlayer1Texture);

	texturesManager.Load(GET_VARIABLE_NAME(gamePlayer2Texture), this->config.gamePlayer2Texture);

	texturesManager.Load(GET_VARIABLE_NAME(lifeTexture), this->config.lifeTexture);
	
	texturesManager.Load(GET_VARIABLE_NAME(bulletPlayerTexture), this->config.bulletPlayerTexture);
	
	texturesManager.Load(GET_VARIABLE_NAME(enemyTexture), this->config.enemyTexture);

	texturesManager.Load(GET_VARIABLE_NAME(bulletEnemyTexture), this->config.bulletEnemyTexture);
}
