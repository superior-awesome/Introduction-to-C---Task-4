#ifndef _ROOM_

#define _ROOM_

#include "Item.h"
#include "String.h"
#include "structs.h"

class Room
{

public:

	Room();
	Room(String* description, Item* item, Vector2 _roomLocation);

	~Room();
	Room(const Room& other);
	Room& operator= (const Room& other);
	Room& operator= (const Room&& other);
	Room(Room&& other);

	int useItem();

private:

	Vector2 roomLocation;
		
	String *roomDesc;
	Item *itemInRoom;
};

#endif //_ROOM_