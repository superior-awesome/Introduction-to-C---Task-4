#pragma once

#ifndef _DONUTBOX_

#define _DONUTBOX_




class BoxOfDonuts : public Item
{

public:
	BoxOfDonuts();
	//~BoxOfDonuts();

	void Use();


private:
	bool DonutInTheBox;

};

#endif