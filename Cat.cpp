#include "Cat.h"


Cat::Cat()
{
	descriptionText = new String("The cat is purring softly.");
	purring = true;
}

void Cat::Use()
{
	if (purring)
	{
		std::cout << "You move towards the cat's throne to pat it. It stopps purring and glares sharply." << std::endl;
		purring = false;

		delete descriptionText;
		descriptionText = new String("The room is silent except for the rain outside and a distant dripping sound.");

	}
	else
	{
		std::cout << "You put your hand down and step away. Satisfide, the cat returns topurring gently, still watching you." << std::endl;
		purring = true;
		
		delete descriptionText;
		descriptionText = new String("The cat is purring softly, beaming a gently aura of calm.");

	}
}