#include "../headers/Floor.h"

Floor::Floor()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			floorRooms[i][j] = Room();
			floorRooms[i][j].setExsists(true);
			floorRooms[i][j].setEnemies(true);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i - 1 >= 0)
			{
				if (floorRooms[i-1][j].getExsists() == true)
				{
					floorRooms[i][j].setDoorUp(true);
				}
			}
			if (i + 1 <= 3)
			{
				if (floorRooms[i + 1][j].getExsists() == true)
				{
					floorRooms[i][j].setDoorDown(true);
				}
			}
			if (j - 1 >= 0)
			{
				if (floorRooms[i][j - 1].getExsists() == true)
				{
					floorRooms[i][j].setDoorLeft(true);
				}
			}
			if (j + 1 <= 3)
			{
				if (floorRooms[i][j + 1].getExsists() == true)
				{
					floorRooms[i][j].setDoorRight(true);
				}
			}
		}
	}

	roomX = rand() % 4;
	roomY = rand() % 4;	
}

int Floor::getRoomX()
{
	return roomX;
}

int Floor::getRoomY()
{
	return roomY;
}

void Floor::getRooms(Room (&pRooms)[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			pRooms[i][j] = floorRooms[i][j];
		}
	}
}

bool Floor::getRoomChange()
{
	return roomChange;
}

void Floor::setRoomX(int pRoomX)
{
	roomX = pRoomX;
}

void Floor::swtRoomY(int pRoomY)
{
	roomY = pRoomY;
}

void Floor::changeRoom(Entity &pEntity)
{
	float diff = 3.0f;

	if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f + 320.0f &&
		pEntity.getPosition().x < 180.0f + 320.0f + 80.0f &&
		pEntity.getPosition().y + pEntity.getSize().y > 60.0f &&
		pEntity.getPosition().y < 60.0f + 60.0f - diff)
	{
		roomChange = true;
		roomY -= 1;
		pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 598.0f - 60.0f - diff));
		std::cout << "1\n";
	}
	if (pEntity.getPosition().x + pEntity.getSize().x > 180.0f + 320.0f &&
		pEntity.getPosition().x < 180.0f + 320.0f + 80.0f &&
		pEntity.getPosition().y + pEntity.getSize().y > 598.0f + diff &&
		pEntity.getPosition().y < 598.0f + 60.0f)
	{
		roomChange = true;
		roomY += 1;
		pEntity.setPosition(sf::Vector2f(pEntity.getPosition().x, 60.0f + 60.0f + diff));
	}
	if (pEntity.getPosition().x + pEntity.getSize().x > 120.0f + 60.0f && 
		pEntity.getPosition().x < 120.0f + 60.0f - diff && 
		pEntity.getPosition().y + pEntity.getSize().y > 120.0f && 
		pEntity.getPosition().y < 120.0f + 598.0f)
	{
		roomChange = true;
		roomX -= 1;
		pEntity.setPosition(sf::Vector2f(898.0f - 60.0f - diff, pEntity.getPosition().y));
	}
	if (pEntity.getPosition().x + pEntity.getSize().x > 898.0f + diff &&
		pEntity.getPosition().x < 898.0f + 60.0f &&
		pEntity.getPosition().y + pEntity.getSize().y > 120.0f &&
		pEntity.getPosition().y < 120.0f + 598.0f)
	{
		roomChange = true;
		roomX += 1;
		pEntity.setPosition(sf::Vector2f(190.0f + diff, pEntity.getPosition().y));
	}
}

void Floor::setRoomChange(bool pRoomChange)
{
	roomChange = pRoomChange;
}
