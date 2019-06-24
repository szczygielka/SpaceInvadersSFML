#include "Config.h"



Config::Config()
{
}

Config::~Config()
{
}
std::pair<std::string, std::string> Config::ConfigTextToPair(const std::string& str, char delim)
{
	std::size_t delimPosition;
	delimPosition = str.find(delim);
	if (delimPosition != std::string::npos)
	{
		return std::pair<std::string, std::string>(str.substr(0, delimPosition), str.substr(delimPosition + 1));
	}
	else
	{
		throw std::exception("Config file is corrupt");
	}
}

void Config::ReadConfigFromFileToMap(std::string fileName)
{
	std::ifstream file;
	file.open(fileName, std::ios::in);
	if (file) {
		std::string line;

		while (getline(file, line))
		{
			if (line.find("#") == std::string::npos && !line.empty())
			{
				this->configMap.insert(ConfigTextToPair(line));
			}
		}
	}
	else
	{
		throw std::exception("Config file not exists");
	}
}


void Config::ParseConfig()
{
	for (std::map<std::string, std::string>::iterator it = this->configMap.begin(); it != this->configMap.end(); ++it)
	{
		try
		{
			this->gameTitle = this->configMap.at(GET_VARIABLE_NAME(gameTitle));
		
			this->windowSize = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(windowSize)));
			this->framePerSec = Str2Float(this->configMap.at(GET_VARIABLE_NAME(framePerSec)));
		
			this->mainMenuBackground = this->configMap.at(GET_VARIABLE_NAME(mainMenuBackground));
			this->pauseMenuBackground = this->configMap.at(GET_VARIABLE_NAME(pauseMenuBackground));
			this->optionsMenuBackground = this->configMap.at(GET_VARIABLE_NAME(optionsMenuBackground));
			this->gameBackground = this->configMap.at(GET_VARIABLE_NAME(gameBackground));
		
			this->gamePlayer1Texture = this->configMap.at(GET_VARIABLE_NAME(gamePlayer1Texture));
			this->gamePlayer2Texture = this->configMap.at(GET_VARIABLE_NAME(gamePlayer2Texture));
			this->bulletPlayerTexture = this->configMap.at(GET_VARIABLE_NAME(bulletPlayerTexture));
			this->bulletEnemyTexture = this->configMap.at(GET_VARIABLE_NAME(bulletEnemyTexture));
			this->lifeTexture = this->configMap.at(GET_VARIABLE_NAME(lifeTexture));
			this->enemyTexture = this->configMap.at(GET_VARIABLE_NAME(enemyTexture));
		
			this->menuFont = this->configMap.at(GET_VARIABLE_NAME(menuFont));
			this->pointsFont = this->configMap.at(GET_VARIABLE_NAME(pointsFont));
		
			this->mainMenuPlayButtonText = this->configMap.at(GET_VARIABLE_NAME(mainMenuPlayButtonText));
			this->mainMenuCloseButtonText = this->configMap.at(GET_VARIABLE_NAME(mainMenuCloseButtonText));
			this->mainMenuOptionsButtonText = this->configMap.at(GET_VARIABLE_NAME(mainMenuOptionsButtonText));
			this->optionsMenuCloseButtonText = this->configMap.at(GET_VARIABLE_NAME(optionsMenuCloseButtonText));
			this->optionsMenuSecondPlayerOffText = this->configMap.at(GET_VARIABLE_NAME(optionsMenuSecondPlayerOffText));
			this->optionsMenuSecondPlayerOnText = this->configMap.at(GET_VARIABLE_NAME(optionsMenuSecondPlayerOnText));
			this->pauseMenuResumeButtonText = this->configMap.at(GET_VARIABLE_NAME(pauseMenuResumeButtonText));
			this->pauseMenuExitGameButtonText = this->configMap.at(GET_VARIABLE_NAME(pauseMenuExitGameButtonText));
		
			this->endGameStateWinBackground = this->configMap.at(GET_VARIABLE_NAME(endGameStateWinBackground));
			this->endGameStateLossBackground = this->configMap.at(GET_VARIABLE_NAME(endGameStateLossBackground));
		
			this->menuButtonNotSelectedColor = Str2Color(this->configMap.at(GET_VARIABLE_NAME(menuButtonNotSelectedColor)));
			this->menuButtonSelectedColor = Str2Color(this->configMap.at(GET_VARIABLE_NAME(menuButtonSelectedColor)));
			this->menuButtonsSize = Str2Int(this->configMap.at(GET_VARIABLE_NAME(menuButtonsSize)));
			this->menuButtonsStyle = Str2TextStyle(this->configMap.at(GET_VARIABLE_NAME(menuButtonsStyle)));
			
			this->gamePointsColor = Str2Color(this->configMap.at(GET_VARIABLE_NAME(gamePointsColor)));
			this->gamePointsSize = Str2Int(this->configMap.at(GET_VARIABLE_NAME(gamePointsSize)));
			this->gamePointsStyle = Str2TextStyle(this->configMap.at(GET_VARIABLE_NAME(gamePointsStyle)));
			this->player1Control = Str2ControlKeyMap(this->configMap.at(GET_VARIABLE_NAME(player1Control)));
			this->player2Control = Str2ControlKeyMap(this->configMap.at(GET_VARIABLE_NAME(player2Control)));
			this->playerVelocity = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(playerVelocity)));
			this->enemyVelocity = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(enemyVelocity)));
			this->playerSize = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(playerSize)));
			this->enemySize = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(enemySize)));
			this->playerBulletSize = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(playerBulletSize)));
			this->playerBulletVelocity = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(playerBulletVelocity)));
			this->enemyBulletSize = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(enemyBulletSize)));
			this->enemyBulletVelocity = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(enemyBulletVelocity)));
			this->playerShootPeriod = sf::seconds(Str2Float(this->configMap.at(GET_VARIABLE_NAME(playerShootPeriod))));
			this->enemyMovePeriod = sf::seconds(Str2Float(this->configMap.at(GET_VARIABLE_NAME(enemyMovePeriod))));
			this->enemyShootPeriod = sf::seconds(Str2Float(this->configMap.at(GET_VARIABLE_NAME(enemyShootPeriod))));
			this->playerBottomWindowGap = Str2Float(this->configMap.at(GET_VARIABLE_NAME(playerBottomWindowGap)));
			this->lifeLifebarGap = Str2Float(this->configMap.at(GET_VARIABLE_NAME(lifeLifebarGap)));
			this->lifeSize = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(lifeSize)));
			this->player1LifebarPosition = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(player1LifebarPosition)));
			this->player2LifebarPosition = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(player2LifebarPosition)));
			this->pointsPosition = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(pointsPosition)));
			this->backgroudPosition = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(backgroudPosition)));
			this->endGameEnemyPosition = Str2Float(this->configMap.at(GET_VARIABLE_NAME(endGameEnemyPosition)));
			this->player2DefaultOn = (bool)Str2Int(this->configMap.at(GET_VARIABLE_NAME(player2DefaultOn)));
			this->enemiesXCount = Str2Int(this->configMap.at(GET_VARIABLE_NAME(enemiesXCount)));
			this->enemiesYCount = Str2Int(this->configMap.at(GET_VARIABLE_NAME(enemiesYCount)));
			this->enemyFirstWaveYPosition = Str2Float(this->configMap.at(GET_VARIABLE_NAME(enemyFirstWaveYPosition)));
			this->playerLifes = Str2Int(this->configMap.at(GET_VARIABLE_NAME(playerLifes)));
			this->pointsPerEnemy = Str2Int(this->configMap.at(GET_VARIABLE_NAME(pointsPerEnemy)));
			this->enemiesGap = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(enemiesGap)));
			this->endGameWaveYPosition = Str2Float(this->configMap.at(GET_VARIABLE_NAME(endGameWaveYPosition)));


			this->endGameScreenTextSize = Str2Int(this->configMap.at(GET_VARIABLE_NAME(endGameScreenTextSize)));
			this->endGameScreenPointsPosition = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(endGameScreenPointsPosition)));
			this->endGameScreenTextColor = Str2Color(this->configMap.at(GET_VARIABLE_NAME(endGameScreenTextColor)));
			this->endGameScreenPointsColor = Str2Color(this->configMap.at(GET_VARIABLE_NAME(endGameScreenPointsColor)));

			this->endGameScreenTextStyle = Str2TextStyle(this->configMap.at(GET_VARIABLE_NAME(endGameScreenTextStyle)));
			this->endGameScreenPointsStyle = Str2TextStyle(this->configMap.at(GET_VARIABLE_NAME(endGameScreenPointsStyle)));
			this->endGameScreenPointsSize = Str2Int(this->configMap.at(GET_VARIABLE_NAME(endGameScreenPointsSize)));

			this->endGameScreenWinText = this->configMap.at(GET_VARIABLE_NAME(endGameScreenWinText));
			this->endGameScreenLossText = this->configMap.at(GET_VARIABLE_NAME(endGameScreenLossText));

			this->endGameScreenTextPosition = Str2Vector2f(this->configMap.at(GET_VARIABLE_NAME(endGameScreenTextPosition)));

		}
		catch (std::exception&)
		{
			throw std::exception("Parse config error");
		}
	}
}



void Config::ReadConfig()
{
	this->ReadConfigFromFileToMap();
	this->ParseConfig();
}
