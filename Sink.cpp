#include "Sink.h"


Sink::Sink()
{
	descriptionText = new String("You can hear the sink dripping.");
	sinkBroken = false;
}

void Sink::Use()
{
	if (sinkBroken)
	{
		std::cout << "You try to collect some water into your hand, but the dripping is too slow. You give up." << std::endl;
	}
	else {
		std::cout << "Turn the tap to get some water but the handle comes off in your hand." << std::endl;
		sinkBroken = true;
	}
}