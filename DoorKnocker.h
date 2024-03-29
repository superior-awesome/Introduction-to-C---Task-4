#pragma once

#include "Item.h"
#ifndef _DOORKNOCKER_

#define _DOORKNOCKER_

class DoorKnocker : public Item
{

	public:
	DoorKnocker();

	void Use() override;
};

#endif