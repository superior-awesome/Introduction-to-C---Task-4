#include "Lamp.h"

Lamp::Lamp()
{
	lampIsOn = false;
	descriptionText = new String("A squat, grey lamp sits on the sidetable. It could be an elephant but it is too ugly to be sure.");
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
		std::cout <<"You fiddle with the lamp. A warm yellow pours down across the walls and your eyes slowly adjust to the shaddows." << std::endl;
		lampIsOn = true;
	}
	else 
	{
		std::cout << "You dont like the shadow shapes and reach for the switch. The lamp is now off." << std::endl;
		lampIsOn = false;
	}
}
