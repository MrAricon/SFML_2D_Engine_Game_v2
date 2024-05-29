#include "../headers/Room.h"

Room::Room()
{
	Obstacle::obstacles(roomObstacles);
	roomEnemy = Enemy(sf::Vector2f(300.0f, 300.0f), sf::Vector2f(64.0f, 64.0f));
}

void Room::getObstacles(Obstacle (&pObstacles)[8][12])
{
	Obstacle nullOb;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			pObstacles[i][j] = nullOb;
			if (roomObstacles[i][j].getPostion() != sf::Vector2f(0.0f, 0.0f))
			{
				pObstacles[i][j] = roomObstacles[i][j];
			}
		}
	}
}

void Room::getEnemy(Enemy &pEnemy)
{
	pEnemy = roomEnemy;
}

bool Room::getExsists()
{
	return exists;
}

bool Room::getDoorUp()
{
	return upDoor;
}

bool Room::getDoorDown()
{
	return downDoor;
}

bool Room::getDoorRight()
{
	return rightDoor;
}

bool Room::getDoorLeft()
{
	return leftDoor;
}

bool Room::getEnemies()
{
	return enemies;
}

void Room::setExsists(bool pExists)
{
	exists = pExists;
}

void Room::setDoorUp(bool pUpDoor)
{
	upDoor = pUpDoor;
}

void Room::setDoorDown(bool pDownDoor)
{
	downDoor = pDownDoor;
}

void Room::setDoorRight(bool pRightDoor)
{
	rightDoor = pRightDoor;
}

void Room::setDoorLeft(bool pLeftDoor)
{
	leftDoor = pLeftDoor;
}

void Room::setEnemies(bool pEnemies)
{
	enemies = pEnemies;
}
