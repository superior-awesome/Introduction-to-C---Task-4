#include "Lamp.h"

Lamp::Lamp()
{
	lampIsOn = false;
	descriptionText = new String("A short, squat, red lamp sits on the sidetable.");
	SetLamp(false);
	
}

void Lamp::Use() {
	SetLamp(!lampIsOn);
	descriptionText->WriteToConsole();
	std::cout << std::endl;
}

void Lamp::SetLamp(bool state)
{
	if (state)
	{
		std::cout <<"You are sick of the dark and fiddle with the lamp.A warm yellow pours down across the walls and your eyes slowly adjust to the ugle shaddows thrown." << std::endl;
		lampIsOn = true;
	}
	else 
	{
		std::cout << "There is too much light, you reach for the switch and return to the dark quiet of the room." << std::endl;
		lampIsOn = false;
	}
}
