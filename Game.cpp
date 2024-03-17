#ifndef _DEBUG_

#define _DEBUG_

#endif

#include "Game.h"

Game::Game()
{
	player = new Player;
	CreateMap();
}

Game::~Game()
{
	delete player;
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
			String *tempDesc = new String("EmptyRoom");
			Item *tempItem = new Item();
			Vector2 tempV2 = { i,j };
			map[i][j] = Room(tempDesc, tempItem,tempV2);
		}
	}
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

	} else
	{
		std::cout << "It doesnt work" << std::endl;
		return 1;
	}
}

int Game::MovePlayer()
{
	Vector2 currentLoc = player->GetCurrentLocation();

	

	return 0;
}