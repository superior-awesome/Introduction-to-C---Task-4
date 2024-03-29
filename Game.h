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


	void CreateMap();

	int GetMapHeight();

	int GetMapWidth();

	int MovePlayer();

	Room* GetRoomObject(const Vector2 vec2);

	int UseRoomItem(Room* _room);

	void DescribeRoomByIndex(int index);

	void DescribeAllRooms();

	int Tick();



private:

	const int mapWidth = 3;
	const int mapHeight = 3; 
	int mapSize;

	Player *player;
	Room *map;

};	

#endif	// _GAME_