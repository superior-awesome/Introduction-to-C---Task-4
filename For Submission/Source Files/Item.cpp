#include "Item.h"

Item::Item()
{
	
	descriptionText = new String("EmptyItem");
	
}

// Destructor
Item::~Item()
{
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
	descriptionText->WriteToConsole();
}

void Item::Use() {

	std::cout << "There is no item in this room." << std::endl;

}

