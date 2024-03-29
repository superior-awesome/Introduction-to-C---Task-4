#include "DoorKnocker.h"


DoorKnocker::DoorKnocker()
	{
		descriptionText = new String("The door knocker is heavy, smooth, and cold to the touch.");
	}

void DoorKnocker::Use()
	{
		std::cout << "You clang the doorknocker twice but hear no stirring in the house." << std::endl;
	}
