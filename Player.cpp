#include "Player.h"


#include <iostream>
#include <ctype.h>

Player::Player()
{

	currentLocation = new Vector2;
	
	command = new String("None");

	//noOfSpells = 5;

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
	//for (int i = 0; i < noOfSpells; i++)
	//{
	//	spells[i] = other.spells[i];
	//}
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
		//spells[i] = other.spells[i];
		//other.spells[i] = nullptr;
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

void Player::InitialiseSpells() {

	spells[0] = Spell(-2,"Eclipse","The cabin shaddows lengthen as you consume what light you can from around you, healing slightly.");
	spells[1] = Spell(5,"Eruption","Your hands blaze into flames, although you dont want to damage anything, you appreciate the warmth and the light while you can sustain it.");
	spells[2] = Spell(-5,"Frostbite","*You are not afflicted with frostbite and cannot cast this healling spell.*");
	spells[3] = Spell(0,"Levitate","You lift up off the ground by a few centimeters, very kind of you not to track mud through the cabin.");
	spells[4] = Spell(0,"Mirage","A perfect copy of you steps off your body, like a snakeskin or a glove, and starts to inspect the ceiling.");
	spells[5] = Spell(0,"Petrify","Your body hardens and freezes in place. You realise that this wont help you search the house, and you revert to your normal self.");
	spells[6] = Spell(0,"Polymorph","You turn yourself into a sheep. This will wear off in 24 hours.");
	spells[7] = Spell(0,"Teleport","Without knowing what way to teleport, you could end up back in the woods and decide to stay under cover.");
	spells[8] = Spell(3,"Thunderwave","Clapping your hands in front of you, papers dust and furniture push and swim through the air around you.");
	spells[9] = Spell(7,"Vortex","You spin with your hands outreached, you can hear the rain outside the house being lifted and pushed away until you feel dizzy and stop.");


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
	int RBounds = noOfSpells;
	int MPoint = (LBounds - RBounds)/2;

	std::string _Str_T = _input.ToLower().CStr(); //  T for Target
	std::string _CStr_M;
	
	MPoint = (RBounds + LBounds)/2;

	while (RBounds - LBounds >1)
	{

#define _DEBUG_

#ifdef _DEBUG_
		std::cout << "( L:" << LBounds <<" - M:" << MPoint << " - R:" << RBounds << " )\n";
#endif

		String _Str_M = spells[MPoint].GetName(); // M for Midpoint
		_Str_M.ToLower();

		_CStr_M = _Str_M.CStr();


		if (_Str_T == _CStr_M)
		{
			std::cout << "SPELL FOUND" << std::endl;
			return 0;
		}
		else if (_Str_T < _CStr_M)
		{
			RBounds = MPoint+1;
			MPoint = (RBounds + LBounds)/ 2;

		} 
		else if (_Str_T > _CStr_M)
		{
			LBounds = MPoint-1;
			MPoint = (RBounds + LBounds)/2;
		}
		
	}

	if (_Str_T == _CStr_M)
	{
		std::cout << "SPELL FOUND" << std::endl;
		return 0;
	}
	else
	{

		std::cout << "SPELL NOT FOUND" << std::endl;
		return -1;
	}
}