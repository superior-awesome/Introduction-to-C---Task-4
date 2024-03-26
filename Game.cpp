#ifndef _DEBUG_

#define _DEBUG_

#endif

#include "Game.h"

Game::Game()
{
	player = new Player;

	const int numberOfRooms = mapWidth * mapHeight;
	


	map = new Room[4];
	
	//map = new Room[numberOfRooms];

	for (int i = 0; i < numberOfRooms; i++)
	{
		map[i].describeRoom();
	}

	//map = mapHolder;

	std::cout << "X" << std::endl;
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

	size_t mapSize = other.mapWidth * other.mapHeight;

	map = new Room[mapSize];
	for (size_t i = 0; i < mapSize; i++)
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

	int MapSize = other.mapHeight * other.mapWidth;
	map = new Room[MapSize];
	for (int i = 0; i < (MapSize); i++)
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


void Game::Run()
{

}

int Game::Tick()
{
#ifdef _DEBUG_
	std::cout << "TICK fired" << std::endl;
#endif


	return 0;
}



void Game::CreateMap()
{
	int mapSize = mapWidth * mapHeight;
	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			size_t mapIndex = (i * 3 + j);

			std::cout << i << "," << j << std::endl;
			String *tempDesc = new String("TEMP");
			Item *tempItem = new Item();
			Vector2* tempV2 = new Vector2;

			tempV2->a = i;
			tempV2->b = j;

			Room rHolder(tempDesc, tempItem, tempV2);

			map[mapIndex] = rHolder;


			delete tempDesc;
			delete tempItem;
			delete tempV2;

		}
	}
	
	std::cout << "ALL DONE" << std::endl;
	//map = &MapHolder;
}


Room* Game::GetRoomObject(const Vector2 vec2) 
{

	int x = vec2.a;
	int y = vec2.b;

	size_t S = ((mapWidth * x) + y);

	Room* rHolder;
	rHolder = &map[S];

	return rHolder;

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

int Game::GetCommand()
{
	
#ifdef _DEBUG_
	std::cout << "GETCOMMAND fired\nFunction isolated.\n" << std::endl;
#endif
	std::cout << "Type new string into command line: ";


	player->ReadCommandToCout();
	
	//player->WriteFromConsoleToCommand();

	/*
	String testStr("TEST");
	String comHolder = player->GetCommand();

	if (comHolder.EqualTo(testStr))
	{
		std::cout << "IT WORKS";
		return 0;
	}
	else if(comHolder.EqualTo("north"))
	{
		std::cout << "MOVING NORTH" << std::endl;
		return 0;

	} else
	{
		std::cout << "It doesnt work" << std::endl;
		return 1;
	}
	*/

	return 1;


}

int Game::MovePlayer()
{
	//Vector2 currentLoc = player->GetCurrentLocation();

	return 0;
}