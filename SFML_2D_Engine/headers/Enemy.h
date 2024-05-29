#pragma once

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
private:
	bool exsists;

public:
	// Constructors
	Enemy();
	Enemy(sf::Vector2f pPosition, sf::Vector2f pSize);

	// Getters
	bool getExsits();

	// Setters
	void setExsists(bool pExsists);

	// Methods
	void calcMovement(sf::Time pDeltaTime, Player pPlayer);
};