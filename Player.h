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
	
	Vector2 GetCurrentLocation() const;
	void SetCurrentLocation(Vector2 _newLoc);

	void WriteFromConsoleToCommand();
	void ReadCommandToCout() const;

	String FindSpell();

	String GetCommand() const;

private:

	int noOfSpells = 3;

	Vector2 *currentLocation;

	String *command;
	
	String *spells;

};


#endif	// _PLAYER_
