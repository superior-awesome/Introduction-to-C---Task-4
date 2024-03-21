#ifndef _ITEM_
#define _ITEM_

#include "String.h"

class Item
{
public:

	Item();
	~Item();
	Item& operator= (const Item& other);

	void Description();
	void Use();
private:

	String descriptionText;

};

#endif // _ITEM_
