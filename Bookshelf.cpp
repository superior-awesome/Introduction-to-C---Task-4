#include "Bookshelf.h"

Bookshelf::Bookshelf()
{
	descriptionText = new String("It is too dark to read any of the spines, but the bookshelf is dauntingly large.");
}

void Bookshelf::Use()
{
	std::cout << "Recognising the D&D Player Handbook from its logo, you pull it from the bookshelf and drop it on your foot. \nTake 2d6 bludegeoning damage.\nYou place the book back where it was." << std::endl;
}