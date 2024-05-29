#include "../headers/Display.h"

void Display::room(sf::Vector2f pPosition, sf::RectangleShape pRoomRec, Room pRoom, Obstacle (&pObstacles)[8][12], sf::Texture pRooks, sf::Texture pOpenDoor, sf::Texture pClosedDoor, sf::RenderWindow* pWindow)
{
	sf::RectangleShape doorRec;
	doorRec.setSize(sf::Vector2f(98.0f, 66.0f));

	sf::VertexArray triangleStrip(sf::Quads, 4 * 96);
	// i < 8
	for (int i = 0; i < 8; i++)
	{
		// j < 12
		for (int j = 0; j < 12; j++)
		{
			if (pObstacles[i][j].getExists() == true)
			{
				triangleStrip[0 + ((4 * j) + (48 * i))].position = pObstacles[i][j].getPostion() + pPosition;
				triangleStrip[1 + ((4 * j) + (48 * i))].position = sf::Vector2f(pObstacles[i][j].getPostion().x, pObstacles[i][j].getPostion().y + pObstacles[i][j].getSize().y) + pPosition;
				triangleStrip[2 + ((4 * j) + (48 * i))].position = sf::Vector2f(pObstacles[i][j].getPostion().x + pObstacles[i][j].getSize().x, pObstacles[i][j].getPostion().y + pObstacles[i][j].getSize().y) + pPosition;
				triangleStrip[3 + ((4 * j) + (48 * i))].position = sf::Vector2f(pObstacles[i][j].getPostion().x + pObstacles[i][j].getSize().x, pObstacles[i][j].getPostion().y) + pPosition;

				triangleStrip[0 + ((4 * j) + (48 * i))].texCoords = sf::Vector2f(0.0f + ((60.0f * pObstacles[i][j].getType()) * pObstacles[i][j].getMarkerd()), 0.0f);
				triangleStrip[1 + ((4 * j) + (48 * i))].texCoords = sf::Vector2f(0.0f + ((60.0f * pObstacles[i][j].getType()) * pObstacles[i][j].getMarkerd()), 60.0f);
				triangleStrip[2 + ((4 * j) + (48 * i))].texCoords = sf::Vector2f(60.0f + ((60.0f * pObstacles[i][j].getType()) * pObstacles[i][j].getMarkerd()), 60.0f);
				triangleStrip[3 + ((4 * j) + (48 * i))].texCoords = sf::Vector2f(60.0f + ((60.0f * pObstacles[i][j].getType()) * pObstacles[i][j].getMarkerd()), 0.0f);
			}
		}
	}

	pRoomRec.setPosition(pPosition);
	pWindow->draw(pRoomRec);
	pWindow->draw(triangleStrip, &pRooks);

	if (pRoom.getEnemies() == true)
	{
		doorRec.setTexture(&pClosedDoor);
	}
	else
	{
		doorRec.setTexture(&pOpenDoor);
	}

	if (pRoom.getDoorUp() == true)
	{
		doorRec.setRotation(0.0f);
		doorRec.setPosition(sf::Vector2f(492.0f, 56.0f) + pPosition);
		pWindow->draw(doorRec);
	}
	if (pRoom.getDoorDown() == true)
	{
		doorRec.setRotation(180.0f);
		doorRec.setPosition(sf::Vector2f(590, 664.0f) + pPosition);
		pWindow->draw(doorRec);
	}
	if (pRoom.getDoorRight() == true)
	{
		doorRec.setRotation(90.0f);
		doorRec.setPosition(sf::Vector2f(964.0f, 310.0f) + pPosition);
		pWindow->draw(doorRec);
	}
	if (pRoom.getDoorLeft() == true)
	{
		doorRec.setRotation(270.0f);
		doorRec.setPosition(sf::Vector2f(116.0f, 408.0f) + pPosition);
		pWindow->draw(doorRec);
	}
}
