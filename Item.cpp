#include "Item.h"

Item::Item()
{
	
	descriptionText = new String("This is a empty Item");
	
}

Item::~Item()
{
	delete[] descriptionText;
};

Item& Item::operator= (const Item& other)
{

	descriptionText = other.descriptionText;

	return *this;
}


void Item::Description() {

}

void Item::Use() {

}

