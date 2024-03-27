#ifndef _GAME_

#define _GAME_

#include <iostream>


#include "Room.h"
#include "header.h"


class Game
{

public:
	Game();
	~Game();
	Game(const Game& other);

	Game& operator=(const Game& other);
	Game(Game&& other);
	Game& operator= (Game&& other);

	void Run();

	void CreateMap();

	int GetMapHeight();

	int GetMapWidth();

	int GetCommand();

	int MovePlayer();

	Room* GetRoomObject(const Vector2 vec2);

	int UseRoomItem(Room* _room);

	void DescribeAllRooms();



private:

	const int mapWidth = 2;
	const int mapHeight = 2; 
	int mapSize;

	Player *player;
	Room *map;

};	

#endif	// _GAME_