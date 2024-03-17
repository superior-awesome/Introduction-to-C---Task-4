#include "Room.h"


Room::Room()
{
	roomLocation = { 0 };

	itemInRoom = new Item;	
	roomDesc = new String("Empty Room.");
}

Room::Room(String* description, Item* item, Vector2 _roomLocation)
{
	roomLocation = _roomLocation;

	itemInRoom = item;
	roomDesc = description;
}

Room::~Room()
{
	delete roomDesc;
	delete itemInRoom;
}
int Room::useItem() {

	
	return 0;
}

