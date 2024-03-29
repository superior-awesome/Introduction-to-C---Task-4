#include "Bookshelf.h"

Bookshelf::Bookshelf()
{
	descriptionText = new String("As the book spines stare at you in small, neat curving shapes, you realise that you dont know Japanese and cant read any of these books.");
}

void Bookshelf::Use()
{
	std::cout << "Recognising the D&D Player Handbook from its logo, you pull it from the bookshelf and drop it on your foot. \nTake 2d6 bludegeoning damage...\nYou place the book back where it was." << std::endl;
}