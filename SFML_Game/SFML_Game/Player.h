#ifndef PLAYER_H
#define PLAYER_H

#include "BaseMovableObject.h"
#include "ControlKeysEnum.h"
#include "Bullet.h"
#include "PlayerBullet.h"

class Player : public BaseMovableObject
{

	std::map<CONTROL_KEYS, sf::Keyboard::Key> controlKeys;
	std::vector< std::shared_ptr <Bullet > > & bullets;
	sf::Time shootPeriod;
	sf::Clock lastShootTime;
public:
	Player(sf::Texture * texture, sf::Vector2f startPos, std::map<CONTROL_KEYS, sf::Keyboard::Key>  controlKeys,
		std::vector< std::shared_ptr <Bullet > > & bullets);
	~Player();

	void Shoot();
	void Update(float dt);
};

#endif
