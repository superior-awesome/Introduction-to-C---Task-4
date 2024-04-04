#pragma once
#ifndef _SINK_

#define _SINK_

#include "Item.h"


class Sink :  public Item
{
public:
	Sink();

	void Use() override;

private:

	bool sinkBroken;
};

#endif
