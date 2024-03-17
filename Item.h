#ifndef _ITEM_
#define _ITEM_

#include "String.h"

class Item
{
public:

	Item();
	~Item();

	void Description();
	void Use();
private:

	String descriptionText;

};

#endif // _ITEM_
