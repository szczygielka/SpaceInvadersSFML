#include "PauseState.h"
#include "GameState.h"

GameState::GameState()
{
	this->gameCollisionManager = new GameCollisionManager(this->players, this->bullets, this->enemys, this->points, this->lifebars);
	this->gamePositionManager = new GamePositionManager(this->players, this->bullets, this->enemys);
	this->gameData = GameData::getInstance();
	this->background = new Background(this->gameData->texturesManager.Get(GET_VARIABLE_NAME(gameBackground)));

	bool enemyMoveRight = true;
}

GameState::~GameState()
{
	delete this->background;
	delete this->gamePositionManager;
	delete this->gameCollisionManager;
}

void GameState::Init()
{
	this->InitPlayers();
	this->InitLifebars();
	this->InitEnemies();
	this->gamePositionManager->Init();
}

void GameState::Update(float dt)
{
	if (!this->gameData->gameIsRunning)
	{
		this->gameData->stateMachine.RemoveState();
		return;
	}
	this->gamePositionManager->Update(dt);
	this->gameCollisionManager->CheckCollisions();
	this->ChcekGameFinish();
}

void GameState::InitPlayers()
{
	sf::Vector2f playerPos = { 0,0 };

	Player * player1 = new Player(this->gameData->texturesManager.Get(GET_VARIABLE_NAME(gamePlayer1Texture)), playerPos, this->gameData->config.player1Control, this->bullets);
	this->players.push_back(std::shared_ptr < Player>(player1));

	playerPos = { (float)this->gameData->view.getSize().x / 2,
		(float)this->gameData->view.getSize().y - this->gameData->config.playerBottomWindowGap - (float)player1->GetGlobalBounds().height };

	//spr czy bêdzie te¿ 2 gracz
	if (this->gameData->player2On)
	{
		playerPos.x -= (float)player1->GetGlobalBounds().width; //w lewo o szerokosc
		Player * player2 = new Player(this->gameData->texturesManager.Get(GET_VARIABLE_NAME(gamePlayer2Texture)), playerPos, this->gameData->config.player2Control, this->bullets);
		playerPos.x += 2 * (float)player1->GetGlobalBounds().width; //w prawo o szerokosc
		this->players.push_back(std::shared_ptr < Player>(player2));
	}
	player1->SetPosition(playerPos);
}

void GameState::InitLifebars()
{
	this->lifebars.push_back(std::shared_ptr<Lifebar>(new Lifebar(this->gameData->config.player1LifebarPosition, true)));

	if (this->gameData->player2On)
	{
		this->lifebars.push_back(std::shared_ptr<Lifebar>(new Lifebar(this->gameData->config.player2LifebarPosition, false)));
	}
}

void GameState::InitEnemies()
{

	float windowsSizeX = (float)this->gameData->view.getSize().x;
	//ilosc wrogow  w poziomie/2 * (ich szerokosc + odlegl miedzy nimi ) + 1/2 szerok wroga 
	float startPosX = windowsSizeX / 2 - (this->gameData->config.enemiesXCount / 2) *
		(this->gameData->config.enemySize.x + this->gameData->config.enemiesGap.x) - this->gameData->config.enemySize.x * 0.5f;
	//pozycja z config (stala)
	float startPosY = this->gameData->config.enemyFirstWaveYPosition;


	for (int i = 0; i < this->gameData->config.enemiesYCount; i++)
	{
		this->enemys.push_back(std::vector< std::shared_ptr<Enemy> >());
		for (int j = 0; j < this->gameData->config.enemiesXCount; j++)
		{
			this->enemys.at(i).push_back(std::shared_ptr<Enemy>(
				new Enemy(sf::Vector2f(startPosX + j * (this->gameData->config.enemySize.x +
					this->gameData->config.enemiesGap.x), startPosY + i * (this->gameData->config.enemiesGap.y +
						this->gameData->config.enemySize.y)))));
		}
	}
}

void GameState::Render()
{
	if (!this->gameData->gameIsRunning)
	{
		return;
	}
	this->background->Render();
	for (this->lifebarsIterator = this->lifebars.begin(); lifebarsIterator != this->lifebars.end(); ++lifebarsIterator)
	{
		(*lifebarsIterator)->Render();
	}
	for (this->playersIterator = this->players.begin(); playersIterator != this->players.end(); ++playersIterator)
	{
		(*playersIterator)->Render();
	}
	for (this->bulletsIterator = this->bullets.begin(); bulletsIterator != this->bullets.end(); ++bulletsIterator)
	{
		(*bulletsIterator)->Render();
	}
	for (this->enemiesYIterator = this->enemys.begin(); enemiesYIterator != this->enemys.end(); ++enemiesYIterator)
	{
		for (this->enemiesXIterator = this->enemiesYIterator->begin(); enemiesXIterator != this->enemiesYIterator->end(); ++enemiesXIterator)
		{
			(*enemiesXIterator)->Render();
		}
	}
	this->points.Render();
}

void GameState::HandleInput()
{
	if (!this->gameData->gameIsRunning)
	{
		return;
	}
	sf::Event evt;
	if (this->gameData->renderWindow.pollEvent(evt))
	{
		if (sf::Event::Closed == evt.type)
		{
			this->gameData->renderWindow.close();
		}
		if (sf::Event::KeyPressed == evt.type)
		{
			if (sf::Keyboard::Escape == evt.key.code) //pauza
			{
				std::shared_ptr < State > pauseState(new PauseState());
				this->gameData->stateMachine.AddState(pauseState);
			}
		}
	}
}



void GameState::ChcekGameFinish()
{
	//sprawdzenie czy jakis enemy jeszcze ¿yje 
	if (this->enemys.size() == 0)
	{
		std::shared_ptr < State > endGameState(new EndGameState(this->points.Get(), true));
		this->gameData->stateMachine.AddState(endGameState);
		return;
	}

	bool gameOver = true;

	//sprawdzenie czy jakis gracz jeszcze zyje
	for (this->playersIterator = this->players.begin(); playersIterator != this->players.end(); ++playersIterator)
	{
		if ((*playersIterator)->GetActive()) //dalej zyje
		{
			gameOver = false;
		}
	}


	if (this->gamePositionManager->IsEnemiesGetPlayerLine())
	{
		gameOver = true;
	}

	if (gameOver) //koniec gry 
	{
		std::shared_ptr < State > endGameState(new EndGameState(this->points.Get())); //dodaj stan konca gry 
		this->gameData->stateMachine.AddState(endGameState);
	}

}

