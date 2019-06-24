#ifndef CONFIG_H
#define CONFIG_H


#include <SFML/Graphics.hpp>
#include <string>
#include "ControlKeysEnum.h"
#include <fstream>
#include "Constants.h"

class Config
{
	std::map<std::string, std::string> configMap;
	void ReadConfigFromFileToMap(std::string fileName = CONFIG_FILE_NAME);
	void ParseConfig();

public:
	Config();
	~Config();

	std::pair<std::string, std::string> ConfigTextToPair(const std::string& str, char delim = '=');
	void ReadConfig();

	std::string gameTitle;
	sf::Vector2f windowSize;

	// max fps
	float framePerSec;

	// background textures
	std::string mainMenuBackground;
	std::string pauseMenuBackground;
	std::string optionsMenuBackground;
	std::string gameBackground;

	// game textures
	std::string gamePlayer1Texture;
	std::string gamePlayer2Texture;
	std::string bulletPlayerTexture;
	std::string bulletEnemyTexture;
	std::string lifeTexture;
	std::string enemyTexture;

	// fonts
	std::string menuFont;
	std::string pointsFont;

	// menu button
	std::string mainMenuPlayButtonText;
	std::string mainMenuCloseButtonText;
	std::string mainMenuOptionsButtonText;
	std::string optionsMenuCloseButtonText;
	std::string optionsMenuSecondPlayerOffText;
	std::string optionsMenuSecondPlayerOnText;
	std::string pauseMenuResumeButtonText;
	std::string pauseMenuExitGameButtonText;
	std::string endGameStateWinBackground;
	std::string endGameStateLossBackground;
	sf::Color menuButtonNotSelectedColor;
	sf::Color menuButtonSelectedColor;
	int menuButtonsSize;
	sf::Text::Style menuButtonsStyle;

	//endgame screen
	int endGameScreenTextSize;
	sf::Vector2f endGameScreenPointsPosition;
	sf::Color endGameScreenTextColor;
	sf::Color endGameScreenPointsColor;

	sf::Text::Style endGameScreenTextStyle;
	sf::Text::Style endGameScreenPointsStyle;
	int endGameScreenPointsSize;

	std::string endGameScreenWinText;
	std::string endGameScreenLossText;

	sf::Vector2f endGameScreenTextPosition;



	//points
	sf::Color gamePointsColor;
	int gamePointsSize;
	sf::Text::Style gamePointsStyle;

	std::map<CONTROL_KEYS, sf::Keyboard::Key> player1Control;

	std::map<CONTROL_KEYS, sf::Keyboard::Key> player2Control;


	sf::Vector2f playerVelocity;
	sf::Vector2f enemyVelocity;

	sf::Vector2f playerSize;
	sf::Vector2f enemySize;

	sf::Vector2f playerBulletSize;
	sf::Vector2f playerBulletVelocity;

	sf::Vector2f enemyBulletSize;
	sf::Vector2f enemyBulletVelocity;

	sf::Time playerShootPeriod;
	sf::Time enemyMovePeriod;
	sf::Time enemyShootPeriod;


	float playerBottomWindowGap;
	float lifeLifebarGap;

	sf::Vector2f lifeSize;
	sf::Vector2f player1LifebarPosition;
	sf::Vector2f player2LifebarPosition;
	sf::Vector2f pointsPosition;
	sf::Vector2f backgroudPosition;

	float endGameEnemyPosition;

	bool player2DefaultOn;
	int enemiesXCount;
	int enemiesYCount;
	float enemyFirstWaveYPosition;

	int playerLifes;
	int pointsPerEnemy;
	sf::Vector2f enemiesGap;
	float endGameWaveYPosition;

};

#endif