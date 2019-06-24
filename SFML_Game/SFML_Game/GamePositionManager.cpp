#include "GamePositionManager.h"



GamePositionManager::GamePositionManager(std::vector<std::shared_ptr<Player>>& players,
	std::vector<std::shared_ptr<Bullet>>& bullets,
	std::vector<std::vector<std::shared_ptr<Enemy>>>& enemys) : players(players), bullets(bullets), enemys(enemys)
{
	this->gameData = GameData::getInstance();
	this->moveEnemyPeriod = this->gameData->config.enemyMovePeriod;
	this->shootEnemyPeriod = this->gameData->config.enemyShootPeriod;
}

GamePositionManager::~GamePositionManager()
{
}

void GamePositionManager::Init()
{
	this->lastMoveEnemyTime.restart();
	this->lastShootEnemyTime.restart();
}



void GamePositionManager::Update(float dt)
{
	this->UpdateBullets(dt);
	this->UpdateEnemies(dt);
	this->UpdatePlayers(dt);
	this->ChcekBulletsPositions();
	this->RemoveDisactiveBullets();
}

void GamePositionManager::UpdatePlayers(float dt)
{
	for (this->playersIterator = this->players.begin(); playersIterator != this->players.end(); ++playersIterator)
	{
		if ((*playersIterator)->GetActive())
		{
			(*playersIterator)->Update(dt);
		}
	}
}

void GamePositionManager::UpdateBullets(float dt)
{
	for (this->bulletsIterator = this->bullets.begin(); bulletsIterator != this->bullets.end(); ++bulletsIterator)
	{
		(*bulletsIterator)->Update(dt);
	}
}

void GamePositionManager::UpdateEnemies(float dt)
{
	this->UpdateEnemiesPosition(dt);
	this->UpdateEnemiesActivity(dt);
	this->UpdateEnemiesShooting(dt);
}

void GamePositionManager::UpdateEnemiesPosition(float dt)
{
	//to trzeba zaktualizowaæ pozycje 
	if (this->moveEnemyPeriod < this->lastMoveEnemyTime.getElapsedTime())
	{
		float scale = 1.0f;
		if (!this->enemyMoveRight) //mowi w ktora strone maja sie poruszac
		{
			scale = -1.0f;
		}
		for (this->enemiesYIterator = this->enemys.begin(); enemiesYIterator != this->enemys.end(); ++enemiesYIterator)
		{
			for (this->enemiesXIterator = this->enemiesYIterator->begin(); enemiesXIterator != this->enemiesYIterator->end(); ++enemiesXIterator)
			{
				//scale: 
				//- maja sie poruszac w prawo
				//+ w lewo
				(*enemiesXIterator)->Update(scale);
			}
		}

		if (this->enemys.size() > 0 && this->enemys.back().size() > 0)
		{
			//sprawdzenie czy ostatni element w pionie z prawej strony nie jest przy prawej scianie
			//if true -> poruszaj sie w lewo  i obniz o wartosc z config w dol 
			if (this->enemys.back().back()->GetPosition().x >
				((float)this->gameData->view.getSize().x - 2 * this->gameData->config.enemySize.x))
			{
				this->enemyMoveRight = false;

				for (this->enemiesYIterator = this->enemys.begin(); enemiesYIterator != this->enemys.end(); ++enemiesYIterator)
				{
					for (this->enemiesXIterator = this->enemiesYIterator->begin(); enemiesXIterator != this->enemiesYIterator->end(); ++enemiesXIterator)
					{
						//obnizenie w pionie (warunkiem jest dobicie do sciany)
						(*enemiesXIterator)->UpdateVerticaly(1);
					}
				}
			}
			//jezeli 1 element z lewej str nie jest przy lewej scianie to poruszaj sie w prawo i obniz wart z config w dol 
			if (this->enemys.front().front()->GetPosition().x < this->gameData->config.enemySize.x)
			{
				this->enemyMoveRight = true;

				for (this->enemiesYIterator = this->enemys.begin(); enemiesYIterator != this->enemys.end(); ++enemiesYIterator)
				{
					for (this->enemiesXIterator = this->enemiesYIterator->begin(); enemiesXIterator != this->enemiesYIterator->end(); ++enemiesXIterator)
					{
						//obnizenie w pionie (warunkiem jest dobicie do sciany)
						(*this->enemiesXIterator)->UpdateVerticaly(1);
					}
				}

			}
		}
		this->lastMoveEnemyTime.restart();
	}
}

//usuwanie 1 pionu lub poziomu wrogow 
void GamePositionManager::UpdateEnemiesActivity(float dt)
{
	if (this->enemys.size() > 0)
	{
		bool verticalWaveToDelete = true;
		bool horizontalWaveToDelete = true;
		//przejscie po kolumnie i spr czy jest aktywny jakikolwiek wrog
		for (size_t x = 0; x < this->enemys.front().size(); x++)
		{
			verticalWaveToDelete = true;
			//sprawdzenie wierszy danej kolumny
			for (size_t y = 0; y < this->enemys.size(); y++)
			{
				if (this->enemys.at(y).at(x)->GetActive())
				{
					verticalWaveToDelete = false;
				}
			}
			//jezeli wszystkie elementy sa nieaktywne to usun ta kolumne
			if (verticalWaveToDelete)
			{
				for (size_t y = 0; y < this->enemys.size(); y++)
				{
					this->enemys.at(y).erase(this->enemys.at(y).begin() + x);
				}
				this->shootEnemyPeriod = sf::seconds((this->gameData->config.enemiesXCount - this->enemys.front().size()) * this->gameData->config.enemyShootPeriod.asSeconds());
			}
		}
		//sprawdzenie czy dany wiersz jest aktywny 
		for (size_t y = 0; y < this->enemys.size(); y++)
		{
			horizontalWaveToDelete = true;

			for (size_t x = 0; x < this->enemys.at(y).size(); x++)
			{
				if (this->enemys.at(y).at(x)->GetActive())
				{
					horizontalWaveToDelete = false;
				}
			}
			//jezeli nie to usun wiersz 
			if (horizontalWaveToDelete)
			{
				this->enemys.erase(this->enemys.begin() + y);
			}

		}
	}
}
//SHOOT BENG BENG
//pdateEnemiesActivity gwarantuje ze w danej kolumnie ktos jest aktywny
void GamePositionManager::UpdateEnemiesShooting(float dt)
{
	if (this->enemys.size() > 0 && this->enemys.back().size() > 0)
	{
		//czy wrog ma strzelac?
		if (this->shootEnemyPeriod < this->lastShootEnemyTime.getElapsedTime())
		{
			int randomValue = rand() % this->enemys.back().size(); //wygenruj indeks przeciwnika 
			//idac od dolu w danej kolumnie szukam 1 aktywnego przeciwnika i ten ma strzelic 
			for (int y = this->enemys.size() - 1; y >= 0; y--)
			{
				if (this->enemys.at(y).at(randomValue)->GetActive())
				{
					//pozycja to srodek przeciwnika 
					sf::Vector2f pos = sf::Vector2f(this->enemys.at(y).at(randomValue)->GetPosition().x + this->enemys.at(y).at(randomValue)->GetGlobalBounds().width / 2,
						this->enemys.at(y).at(randomValue)->GetPosition().y + this->enemys.at(y).at(randomValue)->GetGlobalBounds().height);

					this->bullets.push_back(std::shared_ptr<EnemyBullet>(new EnemyBullet(pos)));
					this->lastShootEnemyTime.restart();
					return;
				}
			}
		}
	}
}

void GamePositionManager::ChcekBulletsPositions()
{
	for (this->bulletsIterator = this->bullets.begin(); bulletsIterator != this->bullets.end(); ++bulletsIterator)
	{
		if ((*bulletsIterator)->GetPosition().x < 0 || (*bulletsIterator)->GetPosition().y < 0
			|| (*bulletsIterator)->GetPosition().x > this->gameData->view.getSize().x ||
			(*bulletsIterator)->GetPosition().y > this->gameData->view.getSize().y)
		{
			(*bulletsIterator)->SetActive(false); //dezaktywacja kuli, nie jest usunieta
		}
	}
}

void GamePositionManager::RemoveDisactiveBullets()
{
	this->bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](std::shared_ptr<Bullet> i)
	{
		return !i->GetActive();
	}
	), bullets.end());
}

bool GamePositionManager::IsEnemiesGetPlayerLine()
{
	//sprawdzenie czy dolny wiersz enemy nie przeszedl linii zdef w configu (za nisko=> koniec gry)
	//przypomnienie:  jezeli wiersz byl pusty to zostal usuniety
	if (this->enemys.size() > 0 && this->enemys.back().size() > 0)
	{
		enemiesYIterator = this->enemys.end() - 1; //ustawienie na najni¿szy wiersz 
		for (this->enemiesXIterator = this->enemiesYIterator->begin(); enemiesXIterator != this->enemiesYIterator->end(); ++enemiesXIterator)
		{
			if ((*enemiesXIterator)->GetActive())
			{
				if ((*enemiesXIterator)->GetPosition().y + this->gameData->config.enemySize.y > this->gameData->config.endGameWaveYPosition)
				{
					return true;
				}
			}
		}
	}
	return false;
}