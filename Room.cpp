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

	roomDesc = other.roomDesc;	

	itemInRoom= other.itemInRoom;
	
	return *this;
}

//	Move Operator
Room& Room::operator= (Room&& other)
{
	roomLocation = other.roomLocation;
	other.roomLocation = nullptr;

	roomDesc = other.roomDesc;
	other.roomDesc = nullptr;

	itemInRoom = other.itemInRoom;
	other.itemInRoom = nullptr;

	return *this;
}

//	Move (Constructor)
Room::Room(Room&& other)
{

	roomLocation = other.roomLocation;
	other.roomLocation = nullptr;
	
	roomDesc = other.roomDesc;
	other.roomDesc = nullptr;
	
	itemInRoom = other.itemInRoom;
	other.itemInRoom = nullptr;


}

int Room::useItem() 
{
	std::cout << "Empty Room, no items avaible" << std::endl;
	
	return 0;
}

void Room::describeRoom()
{
	
	std::cout << "Room Being Described: ";
	roomDesc->WriteToConsole();
	itemInRoom->Description();
	std::cout << std::endl;

}
