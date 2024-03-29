#pragma once

#ifndef _LAMP_

#define _LAMP_

#include "Item.h"
class Lamp : public Item
{
public:

	Lamp();

	void Use();

	void SetLamp(bool state);

private:
	bool lampIsOn;
};


#endif  //_LAMP_
