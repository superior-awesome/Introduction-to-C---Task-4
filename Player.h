#ifndef _PLAYER_
#define _PLAYER_


#include "String.h"
#include "structs.h"

class Player
{

public:

	Player();
	~Player();
	
	void StartGame();

	Vector2 GetCurrentLocation();
	void SetCurrentLocation(Vector2 _newLoc);

	void ReadFromConsoleToCommand();
	const String ReadFromCommandToString();

	String FindSpell();

private:

	String command;
	String spells[10];
	Vector2 currentLocation;

};


#endif	// _PLAYER_
