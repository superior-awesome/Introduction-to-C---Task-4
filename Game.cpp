#ifndef _DEBUG_

#define _DEBUG_

#endif

#include "Game.h"

Game::Game()
{

	CreateMap();

	player = new Player;
	player->SetCurrentLocation({1,0}); 


	
	//DescribeAllRooms();

}

//	Destructor
Game::~Game()
{
	delete player;
	delete[] map;
}


//	Copy Constructor
Game::Game(const Game& other)
{

	player = new Player;
	player = other.player;

	mapSize = other.mapWidth * other.mapHeight;

	map = new Room[mapSize];
	for (int i = 0; i < mapSize; i++)
	{
		map[i] = other.map[i];
	}

}

//	Copy Assignment
Game& Game::operator=(const Game& other)
{

	if (player != nullptr)
	{
		delete player;
	}
	player = new Player;
	player = other.player;

	mapSize = other.mapHeight * other.mapWidth;
	map = new Room[mapSize];
	for (int i = 0; i < (mapSize); i++)
	{
		map[i] = other.map[i];
	}
	
	return *this;
}

//	Move
Game::Game(Game&& other)
{

	player = other.player;
	other.player = nullptr;

	map = other.map;
	other.map = nullptr;


}

//	move Assignement
Game& Game::operator= (Game&& other)
{

	player = other.player;
	other.player = nullptr;

	map = other.map;
	other.map = nullptr;

	return *this;

}

void Game::DescribeRoomByIndex(int index)
{
	map[index].describeRoom();
}



void Game::CreateMap()
{

	const int numberOfRooms = mapWidth * mapHeight;
	mapSize = numberOfRooms;

	map = new Room[numberOfRooms];

	// Room 0 - Empty
	
	String* desc_0 = new String("Blocked Room, should not be accessable.");
	Item* item_0 = new Item;
	Vector2* v2_0= new Vector2(0,0);
	Doors* doors_0 = new Doors(false);

	Room room_0(desc_0, item_0, v2_0, doors_0);

	map[0] = std::move(room_0);
	 
	// Room 1 - Entrance
	
	//String* desc_1 = new String("Rain is hitting the sloop above you, growing in speed. \nYour backpack feels heavy on your shoulders as you grope for a door handle, finding a doorknocker in one hand, and a handle in the other.");
	String* desc_1 = new String("You are on a porch");
	Item* item_1 = new Item;
	Vector2* v2_1 = new Vector2(1,0);
	Doors* doors_1 = new Doors(true, false, false, false);

	Room room_1(desc_1, item_1, v2_1, doors_1);

	map[1] = std::move(room_1);
	
	// Room 2 - Empty

	String* desc_2 = new String("Blocked Room, should not be accessable");
	Item* item_2 = new Item;
	Vector2* v2_2 = new Vector2(2,0);
	Doors* doors_2 = new Doors(false);

	Room room_2(desc_2, item_2, v2_2, doors_2);

	map[2] = std::move(room_2);

	// Room 3 - Bathroom

	String* desc_3 = new String("You are in a bathroom");
	Item* item_3 = new Item;
	Vector2* v2_3 = new Vector2(0,1);
	Doors* doors_3 = new Doors(false);

	Room room_3(desc_3, item_3, v2_3, doors_3);

	map[3] = std::move(room_3);
	
	// Room 4 - Hallway 1
	
	String* desc_4 = new String("You are at the south end of a long hallway.");
	Item* item_4 = new Item;
	Vector2* v2_4 = new Vector2(1,1);
	Doors* doors_4 = new Doors(true);

	Room room_4(desc_4, item_4, v2_4, doors_4);

	map[4] = std::move(room_4);
	// 
	// Room 5 - Living Room
	// 
	
	String* desc_5 = new String("You are in a living room.");
	Item* item_5 = new Item;
	Vector2* v2_5 = new Vector2(2, 1);
	Doors* doors_5 = new Doors(true,false,false,true);

	Room room_5(desc_0, item_0, v2_0, doors_0);

	map[5] = std::move(room_5);

	// Room 6 - Kitchen
	 
	String* desc_6 = new String("The room is a kitchen, you can smell fresh Donuts.");
	Item* item_6 = new BoxOfDonuts();
	Vector2* v2_6 = new Vector2(0, 2);
	Doors* doors_6 = new Doors(false,true,true,false);

	Room room_6(desc_6, item_6, v2_6, doors_6);

	map[6] = std::move(room_6);
	 
	// Room 7 - Hallway 2
	
	String* desc_7 = new String("You are at the north end of a long hallway.");
	Item* item_7 = new Item;
	Vector2* v2_7 = new Vector2(1,2);
	Doors* doors_7 = new Doors(false,true,true,true);

	Room room_7(desc_7, item_7, v2_7, doors_7);

	map[7] = std::move(room_7);
	
	// Room 8 - Dining Room

	String* desc_8 = new String("You are in a dining room.");
	Item* item_8 = new Item;
	Vector2* v2_8 = new Vector2(1, 2);
	Doors* doors_8 = new Doors(false,true,false,true);

	Room room_8(desc_8, item_8, v2_8, doors_8);

	map[8] = std::move(room_8);
	
}


Room* Game::GetRoomObject(const Vector2 vec2) 
{

	int x = vec2.a;
	int y = vec2.b;

	int S = ((mapWidth * x) + y);

	if (S > mapSize || S < 0)
	{
		std::cout << "Error, incorrect map index requested in GetRomObject()->" << S<< std::endl;
		return nullptr;
	}
	else
	{
		//Room* rHolder;

		Room* rHolder = &map[S];
	
		return rHolder;
	}
}

int Game::UseRoomItem(Room* _room)
{

	_room->useItem();

	return 0;

}

int Game::GetMapHeight()
{
	return mapHeight;
}

int Game::GetMapWidth()
{
	return mapWidth;
}


int Game::MovePlayer()
{
	
	Vector2 currentLoc= player->GetCurrentLocation();

	int currentIndex = (currentLoc.a + (mapHeight * currentLoc.b));

	Room* currentRoom = &map[currentIndex];

	std::cout << "Which way do you want to go." << std::endl;
	currentRoom->PrintDoorLocation();
		
	player->WriteFromConsoleToCommand();

	if (player->GetCommand().ToLower() == "north")
	{
		std::cout << "Attempt to go north!" << std::endl;
		if (currentRoom->roomDoors->North)
		{
			Vector2 newLoc = currentLoc;
			newLoc.b++;
			player->SetCurrentLocation(newLoc);

			int currentIndex = (newLoc.a + (mapHeight * newLoc.b));

			map[currentIndex].describeRoom();
			
		}
		else {
			std::cout << "Cannot move in that direction" << std::endl;
		}
	}
	else {

		std::cout << "Command (";
		player->GetCommand().WriteToConsole();
		std::cout << ") is not recognised." << std::endl;
	}



	return 0;
}



void Game::DescribeAllRooms()
{
	for (int i = 0; i < mapSize; i++)
	{

		std::cout << "Room Index: " << i << "----------------------------" << std::endl;
		map[i].describeRoom();
		std::cout << "\n" << std::endl;
	}
}

int Game::Tick()
{
	Vector2 v2holder = player->GetCurrentLocation();
	std::cout << "Choose an action: (You are at "<< v2holder.a<<","<< v2holder.b<<")\n-Move\n-Look\n-Use\n-Quit\n";
	player->WriteFromConsoleToCommand();

	if (player->GetCommand().ToLower() == "move")
	{
		MovePlayer();
		return 0;
	}
	else if (player->GetCommand().ToLower() == "look")
	{

		return 0;
	}
	else if(player->GetCommand().ToLower() == "use")
	{

		return 0;
	}
	else if(player->GetCommand().ToLower() == "quit")
	{
		return 1;
	}
	else
	{
		std::cout << "Command not recognised";
		return 0;
	}
}