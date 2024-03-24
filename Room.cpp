#include "Room.h"


Room::Room()
{
	roomLocation = new Vector2;
	roomLocation->a = 0;
	roomLocation->b = 0;

	itemInRoom = new Item;	

	roomDesc = new String;
}

Room::Room(String* description, Item* item, Vector2* _roomLocation)
{

	roomLocation = new Vector2;
	roomLocation->a = (*_roomLocation).a;
	roomLocation->b = (*_roomLocation).b;

	itemInRoom = new Item;
	itemInRoom = item;

	roomDesc = new String;
	roomDesc = description;

}

//	Destructor
Room::~Room()
{
	delete roomDesc;

	delete roomLocation;

	delete itemInRoom;
}

//	Copy Constructor
Room::Room(const Room& other)
{

	roomLocation = new Vector2;
	roomLocation->a = other.roomLocation->a;
	roomLocation->b = other.roomLocation->b;

	

	itemInRoom = new Item;
	itemInRoom = other.itemInRoom;
	roomDesc = new String;
	roomDesc = other.roomDesc;	//This is the point of failure.
}

//	Copy Operator
Room& Room::operator= (const Room& other)
{
	roomLocation->a = other.roomLocation->a;
	roomLocation->b = other.roomLocation->b;

	roomDesc = other.roomDesc;	//This is the point of failure.
	//Item iHolder = (*other.itemInRoom);
	//itemInRoom = iHolder;

	itemInRoom = other.itemInRoom;

	return *this;
}

//	Move
Room::Room(Room&& other)
{

	roomLocation = new Vector2;
	roomLocation = other.roomLocation;
	
	itemInRoom = new Item;
	itemInRoom = other.itemInRoom;

	roomDesc = new String;
	roomDesc = other.roomDesc;

}

int Room::useItem() 
{
	std::cout << "Empty Room, no items avaible" << std::endl;
	
	return 0;
}


