#pragma once

#include "Room.h"

class Display
{
public:
	static void room(sf::Vector2f pPosition, sf::RectangleShape pRoomRec, Room pRoom, Obstacle (&pObstacles)[8][12], sf::Texture pRocks, sf::Texture pOpenDoor, sf::Texture pClosedDoor, sf::RenderWindow* pWindow);
};