#ifndef _ROOM_

#define _ROOM_

#include "Item.h"
#include "String.h"
#include "structs.h"

class Room
{

public:

	Room();
	Room(String* description, Item* item, Vector2* _roomLocation, Doors* _roomDoors);

	~Room();
	Room(const Room& other);
	Room& operator= (const Room& other);
	Room& operator= (Room&& other);
	Room(Room&& other);



	void describeRoom();

	int useItem();

	int GetnumberOfDoors();

	void PrintDoorLocation();
	void PrintDoorLocationFull();

	Doors *roomDoors;

private:

	String *roomDesc;
	
	Item *itemInRoom;
		
	Vector2 *roomLocation;

};

#endif //_ROOM_