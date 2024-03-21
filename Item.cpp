#include "Item.h"

Item::Item()
{
	
	descriptionText = String("This is a empty Item");

}

Item::~Item() = default;

Item& Item::operator= (const Item& other)
{
	descriptionText = other.descriptionText;

	return *this;
}


void Item::Description() {

}

void Item::Use() {

}

