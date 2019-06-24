#include "Player.h"


Player::Player(sf::Texture * texture, sf::Vector2f startPos, std::map<CONTROL_KEYS, sf::Keyboard::Key> controlKeys,
	std::vector< std::shared_ptr <Bullet>> & bullets)
	: BaseMovableObject(texture, true, startPos, GameData::getInstance()->config.playerSize, GameData::getInstance()->config.playerVelocity),
	controlKeys(controlKeys), bullets(bullets), shootPeriod(GameData::getInstance()->config.playerShootPeriod)
{
	this->lastShootTime.restart();
}

Player::~Player()
{
}

void Player::Update(float dt)
{
	sf::Vector2f pos = sprite.getPosition();
	//isKeyPressed - funkcja z SFML
	if (sf::Keyboard::isKeyPressed(controlKeys[CONTROL_KEYS::LEFT]))
	{
		pos.x -= this->velocity.x*dt;
		//spr czy jestem w oknie
		if (pos.x <= 0)
		{
			pos.x = 0;
		}
	}
	if (sf::Keyboard::isKeyPressed(controlKeys[CONTROL_KEYS::RIGHT]))
	{
		pos.x += this->velocity.x*dt;
		//spr czy jestem w oknie
		if (pos.x >= this->gameData->view.getSize().x - this->sprite.getGlobalBounds().width)
		{
			pos.x = this->gameData->view.getSize().x - this->sprite.getGlobalBounds().width;
		}
	}
	if (sf::Keyboard::isKeyPressed(controlKeys[CONTROL_KEYS::SHOOT]))
	{
		this->Shoot();
	}

	this->SetPosition(pos);
}

void Player::Shoot()
{
	//Time - kl. przech czas, Clock - kl. przech zegar (ca³y czas sie odswieze)
	//getElapsedTime - czas od ost resetu 
	if (this->lastShootTime.getElapsedTime() >= this->shootPeriod)
	{
		this->bullets.push_back(std::shared_ptr < PlayerBullet >(
			new PlayerBullet(sf::Vector2f(this->GetPosition().x + this->GetGlobalBounds().width / 2, this->GetPosition().y))));
		this->lastShootTime.restart();
	}
}