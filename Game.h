#ifndef _GAME_

#define _GAME_

#include <iostream>
//#include <string>

#include "Room.h"
#include "Player.h"


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

	int Tick();

	void CreateMap();

	int GetMapHeight();
	int GetMapWidth();

	int GetCommand();

	int MovePlayer();

	const Room GetRoomObject(const Vector2 vec2);

	int UseRoomItem(Room* _room);

private:

	const int mapWidth = 3;
	const int mapHeight = 3; 

	Player *player;
	Room map[3][3];

};	

#endif	// _GAME_