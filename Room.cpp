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

//	Destructor
Room::~Room()
{
	delete roomDesc;
	delete itemInRoom;
}

//	Copy Constructor
Room::Room(const Room& other)
{
	roomLocation = other.roomLocation;
	(*roomDesc) = (*other.roomDesc);
	(*itemInRoom) = (*other.itemInRoom);
}

//	Copy Operator
Room& Room::operator= (const Room& other)
{
	roomLocation = other.roomLocation;
	(*roomDesc) = (*other.roomDesc);
	Item iHolder = (*other.itemInRoom);
	(*itemInRoom) = iHolder;

	return *this;
}

//	Move
Room::Room(Room&& other)
{
	roomLocation = other.roomLocation;
	(*roomDesc) = (*other.roomDesc);
	(*itemInRoom) = (*other.itemInRoom);

}

int Room::useItem() 
{
	std::cout << "Empty Room, no items avaible" << std::endl;
	
	return 0;
}

