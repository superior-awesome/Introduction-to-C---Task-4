#include "Player.h"

#include <iostream>

Player::Player()
{
	currentLocation = {1,1};
	String intitiator("Empty");
	command = intitiator;

}

//	Destructor
Player::~Player() = default;

//	Copy Constructor
Player::Player(const Player& other)
{
	currentLocation = other.currentLocation;

	for (int i = 0; i < noOfSpells; i++)
	{
		spells[i] = other.spells[i];
	}
}

//Copy Assignmnet
Player& Player::operator= (const Player other)
{
	currentLocation = other.currentLocation;

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

	for (int i = 0; i < noOfSpells; i++)
	{
		spells[i] = other.spells[i];
	}
}

void Player::StartGame()
{

}

Vector2 Player::GetCurrentLocation()
{
	return currentLocation;
}

void Player::SetCurrentLocation(Vector2 _newLoc)
{
	currentLocation = _newLoc;
}

void Player::ReadFromConsoleToCommand()
{

	std::string strHolderBase;
	getline(std::cin, strHolderBase);
	char arr[64];
	std::cout << sizeof(arr) << std::endl;
	strcpy_s(arr, sizeof(arr), strHolderBase.c_str());
	String tempStr(arr);

	command = tempStr;

	std::cout << "->";
	command.WriteToConsole();
	std::cout << std::endl;
}

const String Player::ReadFromCommandToString()
{
	return command;
}

String Player::FindSpell()
{
	String dummy;

	return dummy;
}
