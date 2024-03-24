#ifndef _PLAYER_
#define _PLAYER_


#include "String.h"
#include "structs.h"
#include <string>

class Player
{

public:

	Player();
	~Player();
	Player& operator= (const Player other);
	Player(Player&& other);

	Player(const Player& other);
	
	void StartGame();

	Vector2 GetCurrentLocation();
	void SetCurrentLocation(Vector2 _newLoc);

	void ReadFromConsoleToCommand();
	const String ReadFromCommandToString();

	String FindSpell();

	String command;

private:

	const int noOfSpells = 10;

	String *spells;
	
	Vector2 *currentLocation;

};


#endif	// _PLAYER_
