#include "Room.h"

Room::Room()
{
	roomLocation = new Vector2;
	roomLocation->a = 0;
	roomLocation->b = 0;

	itemInRoom = new Item;	

	roomDesc = new String;

	roomDoors = new Doors(true);
}

Room::Room(String* description, Item* item, Vector2* _roomLocation, Doors* _roomDoors)
{

	roomLocation = new Vector2;
	roomLocation->a = (*_roomLocation).a;
	roomLocation->b = (*_roomLocation).b;

	itemInRoom = new Item;
	itemInRoom = item;

	roomDesc = new String;
	roomDesc = description;

	roomDoors = new Doors;
	roomDoors = _roomDoors;

}

//	Destructor
Room::~Room()
{
	delete roomDesc;

	delete roomLocation;

	delete itemInRoom;

	delete roomDoors;
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

	roomDoors = new Doors;
	roomDoors = other.roomDoors;
}

//	Copy Operator
Room& Room::operator= (const Room& other)
{
	roomLocation->a = other.roomLocation->a;
	roomLocation->b = other.roomLocation->b;

	roomDesc = other.roomDesc;	

	itemInRoom= other.itemInRoom;

	roomDoors = other.roomDoors;
	
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

	roomDoors = other.roomDoors;
	other.roomDoors = nullptr;

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

	roomDoors = other.roomDoors;
	other.roomDoors = nullptr;


}

void Room::describeRoom()
{

	roomDesc->WriteToConsole();
	std::cout << std::endl;
	itemInRoom->Description();
	std::cout << std::endl;
	std::cout << std::endl;

}

int Room::useItem() 
{
	
	itemInRoom->Use();
	
	return 0;
}

int Room::GetnumberOfDoors()
{
	return roomDoors->numberOfDoors;
}

void Room::PrintDoorLocation()
{
	int doorCounter = 0;
	if (roomDoors->numberOfDoors > 1)
	{
		std::cout << "You can go ";
		if (roomDoors->North)
		{
			std::cout << "North";
			doorCounter++;
		}

		if (doorCounter == (roomDoors->numberOfDoors - 1))
		{
			std::cout << ", or ";
		}
		else
		{
			std::cout << ", ";
		}

		if (roomDoors->South)
		{
			std::cout << "South";
			doorCounter++;
		}

		if (doorCounter == (roomDoors->numberOfDoors - 1))
		{
			std::cout << ", or ";
		}
		else
		{
			std::cout << ", ";
		}
		if (roomDoors->East)
		{
			std::cout << "East";
			doorCounter++;
		}

		if (doorCounter == (roomDoors->numberOfDoors - 1))
		{
			std::cout << ", or ";
		}
		else
		{
			std::cout << ", ";
		}
		if (roomDoors->West)
		{
			std::cout << "West";
			doorCounter++;
		}
		std::cout << "?\n";
	}
	else {
		
			std::cout << "You can only go ";
			if (roomDoors->North)
			{
				std::cout << "North.";
				doorCounter++;
			}

			if (roomDoors->South)
			{
				std::cout << "South.";
				doorCounter++;
			}

			if(roomDoors->East)
			{
				std::cout << "East.";
				doorCounter++;
			}


			if (roomDoors->West)
			{
				std::cout << "West.";
				doorCounter++;
			}
			std::cout << "\n";
		
	}


}

void Room::PrintDoorLocationFull()
{
	

		if (roomDoors->North)
		{
			std::cout << "- Move North\n";
		}
		if (roomDoors->South)
		{
			std::cout << "- Move South\n";
		}
		if (roomDoors->East)
		{
			std::cout << "- Move East\n";
		}
		if (roomDoors->West)
		{
			std::cout << "- Move West\n";
		}



}