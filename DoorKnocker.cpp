#include "DoorKnocker.h"


DoorKnocker::DoorKnocker()
	{
		descriptionText = new String("The brass knocker is heavy and smooth in your hand. \nIt is too dark to see but you can feel intricate metalwork");
	}

void DoorKnocker::Use()
	{
		std::cout << "You heave and clang the metal twice but hear no stirring in the house. \nThe wind pushes you north towards the house." << std::endl;
	}
