#include "Sink.h"


Sink::Sink()
{
	descriptionText = new String("You can hear a sink dripping in the dark.");
	sinkBroken = false;
}

void Sink::Use()
{
	if (sinkBroken)
	{
		std::cout << "You try to collect some water into your hand, but the dripping is too slow. You give up." << std::endl;
	}
	else {
		std::cout << "You turn the sink handle to get some water but it breaks off in your hand." << std::endl;
		sinkBroken = true;
	}
}