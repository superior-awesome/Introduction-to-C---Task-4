#pragma once

#ifndef _DONUTBOX_

#define _DONUTBOX_




class BoxOfDonuts : public Item
{

public:
	BoxOfDonuts();

	void Use();


private:
	int numberOfDonuts;

};

#endif