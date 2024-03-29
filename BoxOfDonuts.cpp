#include "Item.h"
#include "BoxOfDonuts.h"

BoxOfDonuts::BoxOfDonuts()
{
	
	numberOfDonuts = 3;
	descriptionText = new String("Your stomach spies a box with donuts inside.");
}

void BoxOfDonuts::Use()
{

	
	if (numberOfDonuts == 1)
	{
		std::cout << "You gulp down the last donut without realizing it, wiping your hands together to dust off the sugar." << std::endl;
		delete descriptionText;
		descriptionText = new String("There is empty box on the benchtop.");

	} else if (numberOfDonuts>0)
	{

		std::cout << "Starving, you wolf down a donut throwing powdered sugar onto your rainslicked hands." << std::endl;

		
	}
	else
	{

		std::cout << "You think about licking the powedered sugar in the box...but decide against it." << std::endl;
	}
	numberOfDonuts--;

	
}