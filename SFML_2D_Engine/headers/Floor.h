#pragma once

#include "Room.h"

class Floor
{
private:
	int roomX;
	int roomY;

	bool roomChange;

	Room floorRooms[4][4];

public:
	// Constructor
	Floor();

	// Getters
	int getRoomX();
	int getRoomY();
	bool getRoomChange();
	void getRooms(Room (&pRooms)[4][4]);

	// Setters
	void setRoomX(int pRoomX);
	void swtRoomY(int pRoomY);
	void setRoomChange(bool pRoomChange);

	// Methods
	void changeRoom(Entity &pEntity);
};