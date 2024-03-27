#ifndef _ITEM_
#define _ITEM_

#include "String.h"

class Item
{
public:

	Item();
	~Item();
	Item(Item& other);
	Item& operator= (const Item& other);

	Item(Item&& other);

	Item& operator= (Item&& other);

	void Description();
	void Use();

protected:
	String *descriptionText;



};

#endif // _ITEM_
