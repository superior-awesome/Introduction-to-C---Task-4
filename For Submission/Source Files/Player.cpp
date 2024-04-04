#include "Player.h"

#include <iostream>

Player::Player()
{

	currentLocation = new Vector2;
	
	command = new String("None");

	spells = new String[noOfSpells];

}

//	Destructor
Player::~Player()
{

	delete currentLocation;

	delete command;

	delete[] spells;

}

//	Copy Constructor
Player::Player(const Player& other)
{
	currentLocation = new Vector2;
	currentLocation->a = other.currentLocation->a;
	currentLocation->b = other.currentLocation->b;

	command = new String;
	command = other.command;

	spells = new String[noOfSpells];
	for (int i = 0; i < noOfSpells; i++)
	{
		spells[i] = other.spells[i];
	}
}

//Copy Assignmnet
Player& Player::operator= (const Player other)
{
	currentLocation->a = other.currentLocation->a;
	currentLocation->b = other.currentLocation->b;

	command = other.command;

	if (spells != nullptr)
	{
		delete[] spells;
	}

	spells = new String[other.noOfSpells];
	noOfSpells = other.noOfSpells;

	for (int i = 0; i < noOfSpells; i++)
	{
		spells[i] = other.spells[i];
	}

	return *this;
}

//	Move
Player::Player(Player&& other)
{

	currentLocation = other.currentLocation;
	other.currentLocation = nullptr;

	command = other.command;
	other.command= nullptr;

	spells = other.spells;
	other.spells= nullptr;

}



Vector2 Player::GetCurrentLocation() const
{
	return (*currentLocation);
}

void Player::SetCurrentLocation(Vector2 _newLoc)
{
	currentLocation->a = _newLoc.a;
	currentLocation->b = _newLoc.b;
}

void Player::WriteFromConsoleToCommand()
{
	std::cout << ": ";
	std::string strHolderBase;
	getline(std::cin, strHolderBase);
	char arr[128];
	//std::cout << sizeof(arr) << std::endl;
	strcpy_s(arr, sizeof(arr), strHolderBase.c_str());
	String output(arr);

	command = new String(output);

}

void Player::ReadCommandToCout() const
{
	command->WriteToConsole();
}

String Player::GetCommand() const
{
	return *command;
}

String Player::FindSpell()
{
	String dummy;

	return dummy;
}
