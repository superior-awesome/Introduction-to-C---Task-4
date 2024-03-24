#ifndef _DEBUG_

#define _DEBUG_

#endif

#include "Game.h"



Game::Game()
{
	player = new Player;
	map = new Room[mapWidth*mapHeight];
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

	map = new Room[mapWidth * mapHeight];
	for (int i = 0; i < (mapWidth*mapHeight); i++)
	{
		map[i] = other.map[i];
	}

}

//	Copy Assignment
Game& Game::operator=(const Game& other)
{
	delete player;
	player = new Player;
	player = other.player;

	delete[] map;
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

	player = new Player;
	player = other.player;
	delete other.player;


	int MapSize = other.mapHeight * other.mapWidth;
	map = new Room[MapSize];
	for (int i = 0; i < (MapSize); i++)
	{
		map[i] = other.map[i];
	}
	delete[] other.map;

}

//	move Assignement
Game& Game::operator= (Game&& other)
{

	delete player;
	player = new Player;
	player = other.player;
	delete other.player;

	delete[] map;
	int MapSize = other.mapHeight * other.mapWidth;
	map = new Room[MapSize];
	for (int i = 0; i < (MapSize); i++)
	{
		map[i] = other.map[i];
	}
	delete[] other.map;

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
	GetCommand();

	return 0;
}


/*
void Game::CreateMap()
{
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			std::cout << i << "," << j << std::endl;
			String *tempDesc = new String("TEMP");
			Item *tempItem = new Item();
			Vector2 tempV2 = { i,j };
			Room rHolder = Room(tempDesc, tempItem, tempV2);

			map[i][j] = rHolder;

		}
	}
	std::cout << "ALL DONE" << std::endl;
	//map = &MapHolder;
}
*/

const Room Game::GetRoomObject(const Vector2 vec2) 
{

	int x = vec2.a;
	int y = vec2.b;

	size_t S = ((3 * x) + y);

	Room rHolder(map[S]);

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
	std::cout << "GETCOMMAND fired" << std::endl;
#endif
	std::cout << "Type new string into command line: ";


	player->ReadFromConsoleToCommand();
	String commandHolder = player->ReadFromCommandToString();

	String testStr("TEST");

	if (commandHolder.EqualTo(testStr))
	{
		std::cout << "IT WORKS";
		return 0;
	}
	else if(commandHolder.EqualTo("north"))
	{
		std::cout << "MOVING NORTH" << std::endl;
		return 0;

	} else
	{
		std::cout << "It doesnt work" << std::endl;
		return 1;
	}

	return 1;


}

int Game::MovePlayer()
{
	Vector2 currentLoc = player->GetCurrentLocation();

	

	return 0;
}