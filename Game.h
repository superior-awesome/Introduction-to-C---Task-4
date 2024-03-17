#ifndef _GAME_

#define _GAME_

#include <iostream>

#include "Room.h"
#include "Player.h"

class Game
{

public:
	Game();
	~Game();
	void Run();

	int Tick();

	void CreateMap();

	int GetMapHeight();
	int GetMapWidth();

	int GetCommand();

	int MovePlayer();

private:
	Player *player;

	const int mapWidth = 3;
	const int mapHeight = 3; 

	Room map[3][3];


};	

#endif	// _GAME_