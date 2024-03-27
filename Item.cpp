#include "Item.h"

Item::Item()
{
	
	descriptionText = new String("EmptyItem");
	
}

// Destructor
Item::~Item()
{
	std::cout << "Deleting: ";
	descriptionText->WriteToConsole();
	std::cout << std::endl;
	delete descriptionText;
};

//	Copy constructor
Item::Item(Item& other)
{
	descriptionText = other.descriptionText;
}

//	Copy operator
Item& Item::operator= (const Item& other)
{

	descriptionText = other.descriptionText;

	return *this;
}

//	Move Constructor
Item::Item(Item&& other)
{
	descriptionText = new String;
	descriptionText = other.descriptionText;
	other.descriptionText = nullptr;
}

//	Move Operator
Item& Item::operator= (Item&& other)
{

	descriptionText = other.descriptionText;
	other.descriptionText = nullptr;

	return *this;
}



void Item::Description() {
	std::cout << "Item Being Described: ";
	descriptionText->WriteToConsole();
	std::cout << std::endl;
}

void Item::Use() {

}

