#include "GameCollisionManager.h"






GameCollisionManager::GameCollisionManager(std::vector<std::shared_ptr<Player>>& players,
	std::vector<std::shared_ptr<Bullet>>& bullets,
	std::vector<std::vector<std::shared_ptr<Enemy>>>& enemys, Points & points,
	std::vector< std::shared_ptr<Lifebar> > & lifebars) : players(players), bullets(bullets), enemys(enemys), points(points), lifebars(lifebars)
{
	this->gameData = GameData::getInstance();
}


GameCollisionManager::~GameCollisionManager()
{
}

void GameCollisionManager::CheckCollisions()
{
	//przejdz po wszystkich kulach i w zaleznosci czy sa to kule playerow czy wrogow spr kolizje z wrogami lub graczami 
	for (this->bulletsIterator = this->bullets.begin(); bulletsIterator != this->bullets.end(); ++bulletsIterator)
	{
		std::shared_ptr<PlayerBullet> playerBullet = std::dynamic_pointer_cast<PlayerBullet>(*bulletsIterator); //RTTI 

		if (playerBullet)
		{
			for (this->enemiesYIterator = this->enemys.begin(); enemiesYIterator != this->enemys.end(); ++enemiesYIterator)
			{
				for (this->enemiesXIterator = this->enemiesYIterator->begin(); enemiesXIterator != this->enemiesYIterator->end(); ++enemiesXIterator)
				{
					if ((*enemiesXIterator)->GetActive() && (*bulletsIterator)->GetActive())
					{
						//intersects  - funkcja z SFML sprawdzajaca czy obiekt nie znajduje sie w obiekcie 
						if ((*bulletsIterator)->GetGlobalBounds().intersects((*enemiesXIterator)->GetGlobalBounds())) //zwraca FloatRect
						{
							(*enemiesXIterator)->SetActive(false); //dezaktywuj wroga
							(*bulletsIterator)->SetActive(false); //kule 
							this->points.Add(this->gameData->config.pointsPerEnemy); //dodaj pkt graczowi 
						}
					}
				}
			}
		}
		else
		{
			//kula przeciwnika
			//po wszystkich graczach jezeli kula koliduje z graczem 
			for (size_t i = 0; i < this->players.size(); i++) //przejscie po wektorze graczy
			{
				if (this->players.at(i)->GetActive() && (*bulletsIterator)->GetActive())
				{
					if ((*bulletsIterator)->GetGlobalBounds().intersects(this->players.at(i)->GetGlobalBounds()))
					{
						(*bulletsIterator)->SetActive(false);

						this->lifebars.at(i)->RemoveOneLife(); //usuniecie zycia gracza 

						if (this->lifebars.at(i)->GetLifesCount() == 0)
						{
							this->players.at(i)->SetActive(false); //0 zyc dezaktywacja gracza 
						}
					}
				}
			}
		}

	}
}
