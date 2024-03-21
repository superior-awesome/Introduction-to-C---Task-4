#ifndef _DEBUG_

#define _DEBUG_

#endif

#include "Game.h"



Game::Game()
{
	player = new Player;
	CreateMap();
}

//	Destructor
Game::~Game()
{
	delete player;
}


//	Copy Constructor
Game::Game(const Game& other)
{

	player = other.player;

}

//	Copy Assignment
Game& Game::operator=(const Game& other)
{
	player = other.player;

	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{
			map[i][j] = other.map[i][j];
		}
	}

	return *this;
}

//	Move
Game::Game(Game&& other)
{
	//			Q: Is there a way to trigger the other object to destroy itself?
	player = other.player;
	
	//			Q: Isnt the other.player still in the heap somewhere, but not just unacessable?
	other.player = nullptr;

	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{
			map[i][j] = other.map[i][j];
		}
	}

}

//	move Assignement
Game& Game::operator= (Game&& other)
{
	//			Q: Is there a way to trigger the other object to destroy itself?
	player = other.player;

	//			Q: Isnt the other.player still in the heap somewhere, but not just unacessable?
	other.player = nullptr;

	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{

			Room rHolder = other.map[i][j];
			map[i][j] = rHolder;
		}
	}

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



void Game::CreateMap()
{
	for (int i = 0; i < mapHeight; i++)
	{
		for (int j = 0; j < mapWidth; j++)
		{
			String *tempDesc = new String("TEMP");
			Item *tempItem = new Item();
			Vector2 tempV2 = { i,j };

			Room rHolder = Room(tempDesc, tempItem, tempV2);

			map[i][j] = rHolder;

		}
	}
	//map = &MapHolder;
}

const Room Game::GetRoomObject(const Vector2 vec2) 
{

	Room rHolder = map[vec2.a][vec2.b];

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
	std::cout << "Type new string into command line: ";
#endif


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