#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	

public:
	// Constructor
	Player(std::string pTextureFile, sf::Vector2f pPosition, sf::Vector2f pSize);


	// Methods
	void calcMovement(sf::Time pDeltaTime);
};