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
		std::cout << "You move towards the cat to pat it. It stopps purring and glares sharply." << std::endl;
		purring = false;

		delete descriptionText;
		descriptionText = new String("The room is silent, you feel the cat's eyes warding you away.");

	}
	else
	{
		std::cout << "You put your hand down and step away from teh chair. The cat returns to its purring." << std::endl;
		purring = true;
		
		delete descriptionText;
		descriptionText = new String("The cat is purring softly.");

	}
}