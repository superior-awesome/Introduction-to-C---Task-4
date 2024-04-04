#pragma once

#ifndef _CAT_

#define _CAT_

#include "Item.h"
class Cat : public Item
{
	
public:
	Cat();

	void Use();

private:

	bool purring;
};


#endif