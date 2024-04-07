#include "Player.h"


#include <iostream>
#include <ctype.h>

Player::Player()
{

	currentLocation = new Vector2;
	
	command = new String("None");

	spells = new Spell[noOfSpells];

	InitialiseSpells();

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

	//spells = new Spell[noOfSpells];
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

	spells = new Spell[5];
	//noOfSpells = other.noOfSpells;

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

	for (int i = 0; i < noOfSpells; i++)
	{
		spells[i] = other.spells[i];
	}
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

bool Player::FindSpell()
{
	int i = BinarySearchForSpell(GetCommand());

	if(i != -1){
		spells[i].Cast();
		return true;
	}
	else
	{
		std::cout << "You do not know that spell." << std::endl;
		return false;
	};

}

void Player::InitialiseSpells() {

	spells[0] = Spell(-2,"Eclipse","You siphon what light you can from around you, healing slightly.");
	spells[1] = Spell(5,"Eruption","Your hands burst aflame, you enjoy the warmth while you can sustain it.");
	spells[2] = Spell(-5,"Frostbite","You heal your numb toes, staving off frostbite.");
	spells[3] = Spell(0,"Levitate","You lift up off the ground to avoid walking mud through the cabin.");
	spells[4] = Spell(0,"Mirage","You shed a translucent ghost which starts to explore the dark cabin.");
	spells[5] = Spell(0,"Petrify","You pull a scary face, nobody is there to react.");
	spells[6] = Spell(0,"Polymorph","You turn yourself into a sheep. This will wear off in 24 hours.");
	spells[7] = Spell(0,"Teleport","*Cannot telleport while in danger* - Spell unavailable.");
	spells[8] = Spell(3,"Thunderwave","You cast lightning-wave from your hands, and than wait until thunderwave is cast.");
	spells[9] = Spell(7,"Vortex","All the furniture in the room is pushed away from you.");

}

void Player::PrintSpells() {
	for (int i = 0; i < noOfSpells; i++)
	{
		spells[i].Describe();
	}
}

int Player::BinarySearchForSpell(String _input)
{

	int LBounds = 0;
	int RBounds = noOfSpells-1;
	int MPoint = (LBounds - RBounds)/2;

	std::string _Str_T = _input.ToLower().CStr(); //  T for Target
	std::string _CStr_M;
	
	MPoint = (RBounds + LBounds)/2;

	bool searching = true;

	while (searching)
	{

//#define _DEBUG_

#ifdef _DEBUG_
		std::cout << "( L:" << LBounds <<" - M:" << MPoint << " - R:" << RBounds << " )\n";
#endif

		String _Str_M = spells[MPoint].GetName(); // M for Midpoint
		_Str_M.ToLower();

		_CStr_M = _Str_M.CStr();


		if (_Str_T == _CStr_M)
		{
			return MPoint;
		}
		else if (RBounds <= LBounds)
		{
			searching = false;
			return -1;
			
		}
		else if (_Str_T < _CStr_M)
		{
			RBounds = MPoint-1;
			MPoint = (RBounds + LBounds)/ 2;

		} 
		else if (_Str_T > _CStr_M)
		{
			LBounds = MPoint+1;
			MPoint = (RBounds + LBounds)/2;
		}
	}
	return -1;

}