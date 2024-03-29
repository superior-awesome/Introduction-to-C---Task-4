#include "Item.h"
#include "BoxOfDonuts.h"

BoxOfDonuts::BoxOfDonuts()
{
	DonutInTheBox = true;
	descriptionText = new String("There is a box with one donut inside on the marbel benchtop.");
}

void BoxOfDonuts::Use()
{
	if (DonutInTheBox)
	{
		DonutInTheBox = false;
		delete descriptionText;
		
		std::cout << "You lift the box lid and snatch the last Donut from the box, gulping it down before whoever left it here comes back." << std::endl;
		
		descriptionText = new String("There is empty box on the marbel benchtop.");
		
	}
	else
	{
		std::cout << "You think about licking the powedered sugar in the box for a moment...but decide against it." << std::endl;
	}
}