#pragma once

#ifndef _PLAYER_
#define _PLAYER_

#include "header.h"
#include "String.h"
#include "Spell.h"
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

	void InitialiseSpells();

	void PrintSpells();

	int BinarySearchForSpell(String _input);

private:


	int const noOfSpells = 10;

	Vector2* currentLocation;

	String* command;

	Spell* spells;

};


#endif	// _PLAYER_
