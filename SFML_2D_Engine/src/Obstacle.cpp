#include "../headers/Obstacle.h"

void Obstacle::populateObstacle(int x, int y, Obstacle(&pObstacles)[8][12])
{
	pObstacles[y][x] = Obstacle();
	pObstacles[y][x].setPosition(sf::Vector2f(180.0f + (pObstacles[y][x].getSize().x * x),
											  120.0f + (pObstacles[y][x].getSize().y * y)));
	pObstacles[y][x].setExists(true);
}

Obstacle::Obstacle()
{
	if (rand() % 100 + 1 > 95)
	{
		bomb = true;
	}
	else
	{
		bomb = false;
	}
	if (rand() % 200 + 1 < 5)
	{
		marked = 2;
	}
	else
	{
		marked = 1;
	}
	type = rand() % 2;
	size = sf::Vector2f(60.0f, 60.0f);
}

sf::Vector2f Obstacle::getPostion()
{
	return position;
}

sf::Vector2f Obstacle::getSize()
{
	return size;
}

bool Obstacle::getExists()
{
	return exists;
}

bool Obstacle::getBomb()
{
	return bomb;
}

int Obstacle::getMarkerd()
{
	return marked;
}

int Obstacle::getType()
{
	return type;
}

void Obstacle::setPosition(sf::Vector2f pPosition)
{
	position = pPosition;
}

void Obstacle::setExists(bool pExsists)
{
	exists = pExsists;
}

void Obstacle::obstacles(Obstacle (&pObstacles)[8][12])
{
	if (rand() % 8 == 1)
	{
		Obstacle::populateObstacle(0, 0, pObstacles);
		Obstacle::populateObstacle(1, 0, pObstacles);
		Obstacle::populateObstacle(0, 1, pObstacles);

		Obstacle::populateObstacle(11, 0, pObstacles);
		Obstacle::populateObstacle(10, 0, pObstacles);
		Obstacle::populateObstacle(11, 1, pObstacles);

		Obstacle::populateObstacle(0, 6, pObstacles);
		Obstacle::populateObstacle(1, 7, pObstacles);
		Obstacle::populateObstacle(0, 7, pObstacles);

		Obstacle::populateObstacle(11, 6, pObstacles);
		Obstacle::populateObstacle(11, 7, pObstacles);
		Obstacle::populateObstacle(10, 7, pObstacles);
	}
	else if (rand() % 8 == 2)
	{
		Obstacle::populateObstacle(0, 0, pObstacles);
		Obstacle::populateObstacle(1, 0, pObstacles);
		Obstacle::populateObstacle(2, 0, pObstacles);
		Obstacle::populateObstacle(0, 1, pObstacles);
		Obstacle::populateObstacle(0, 2, pObstacles);
		Obstacle::populateObstacle(2, 2, pObstacles);

		Obstacle::populateObstacle(11, 0, pObstacles);
		Obstacle::populateObstacle(10, 0, pObstacles);
		Obstacle::populateObstacle(9, 0, pObstacles);
		Obstacle::populateObstacle(11, 1, pObstacles);
		Obstacle::populateObstacle(11, 2, pObstacles);
		Obstacle::populateObstacle(9, 2, pObstacles);

		Obstacle::populateObstacle(0, 6, pObstacles);
		Obstacle::populateObstacle(0, 5, pObstacles);
		Obstacle::populateObstacle(2, 5, pObstacles);
		Obstacle::populateObstacle(1, 7, pObstacles);
		Obstacle::populateObstacle(2, 7, pObstacles);
		Obstacle::populateObstacle(0, 7, pObstacles);

		Obstacle::populateObstacle(11, 6, pObstacles);
		Obstacle::populateObstacle(11, 5, pObstacles);
		Obstacle::populateObstacle(11, 7, pObstacles);
		Obstacle::populateObstacle(10, 7, pObstacles);
		Obstacle::populateObstacle(9, 7, pObstacles);
		Obstacle::populateObstacle(9, 5, pObstacles);
	}
	else if (rand() % 8 == 3)
	{
		Obstacle::populateObstacle(4, 2, pObstacles);
		Obstacle::populateObstacle(5, 2, pObstacles);
		Obstacle::populateObstacle(6, 2, pObstacles);
		Obstacle::populateObstacle(7, 2, pObstacles);

		Obstacle::populateObstacle(3, 3, pObstacles);
		Obstacle::populateObstacle(3, 4, pObstacles);

		Obstacle::populateObstacle(4, 5, pObstacles);
		Obstacle::populateObstacle(5, 5, pObstacles);
		Obstacle::populateObstacle(6, 5, pObstacles);
		Obstacle::populateObstacle(7, 5, pObstacles);

		Obstacle::populateObstacle(8, 3, pObstacles);
		Obstacle::populateObstacle(8, 4, pObstacles);
	}
	else if (rand() % 8 == 4)
	{
		Obstacle::populateObstacle(0, 0, pObstacles);
		Obstacle::populateObstacle(0, 1, pObstacles);
		Obstacle::populateObstacle(0, 2, pObstacles);
		Obstacle::populateObstacle(1, 2, pObstacles);
		Obstacle::populateObstacle(2, 2, pObstacles);

		Obstacle::populateObstacle(11, 0, pObstacles);
		Obstacle::populateObstacle(11, 1, pObstacles);
		Obstacle::populateObstacle(10, 0, pObstacles);
		Obstacle::populateObstacle(10, 1, pObstacles);

		Obstacle::populateObstacle(11, 7, pObstacles);
		Obstacle::populateObstacle(11, 6, pObstacles);
		Obstacle::populateObstacle(11, 5, pObstacles);
		Obstacle::populateObstacle(10, 5, pObstacles);
		Obstacle::populateObstacle(9, 5, pObstacles);

		Obstacle::populateObstacle(0, 7, pObstacles);
		Obstacle::populateObstacle(0, 6, pObstacles);
		Obstacle::populateObstacle(1, 7, pObstacles);
		Obstacle::populateObstacle(1, 6, pObstacles);

		Obstacle::populateObstacle(5, 3, pObstacles);
		Obstacle::populateObstacle(5, 4, pObstacles);
		Obstacle::populateObstacle(6, 3, pObstacles);
		Obstacle::populateObstacle(6, 4, pObstacles);
	}
}