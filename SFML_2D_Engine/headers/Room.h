#pragma once

#include "Obstacle.h"
#include "Enemy.h"

class Room
{
private:
	bool upDoor;
	bool downDoor;
	bool rightDoor;
	bool leftDoor;

	bool enemies;

	bool exists;

	bool spawn;

	Obstacle roomObstacles[8][12];
	Enemy roomEnemy;

public:
	// Constructor
	Room();

	// Getters
	void getObstacles(Obstacle (&pObstacles)[8][12]);
	void getEnemy(Enemy &pEnemy);
	bool getExsists();
	bool getDoorUp();
	bool getDoorDown();
	bool getDoorRight();
	bool getDoorLeft();
	bool getEnemies();

	// Setters
	void setExsists(bool pExists);
	void setDoorUp(bool pUpDoor);
	void setDoorDown(bool pDownDoor);
	void setDoorRight(bool pRightDoor);
	void setDoorLeft(bool pLeftDoor);
	void setEnemies(bool pEnemies);

	// Methods
	
};