#ifndef _ROOM_

#define _ROOM_

#include "Item.h"
#include "String.h"
#include "structs.h"

class Room
{

public:

	Room();
	Room(String* description, Item* item, Vector2* _roomLocation);

	~Room();
	Room(const Room& other);
	Room& operator= (const Room& other);
	Room& operator= (const Room&& other);
	Room(Room&& other);

	

	int useItem();


private:

	String *roomDesc;
	
	Vector2 *roomLocation;
		
	Item *itemInRoom;
};

#endif //_ROOM_