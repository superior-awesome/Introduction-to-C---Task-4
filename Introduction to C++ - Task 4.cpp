// Introduction to C++ - Task 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "header.h"

int main()
{

    Game currentGame;

    bool gameRunning = true;

    std::cout << "----------------------------------------\n\n"
        <<"You have been walking in the woods for hours but you think the Orcs have stopped their chase.\n"
        <<"Your broad hat is flapping in the wink, keeping the rain off your face.\n"
        <<"In a flash of approaching lightning, you see a house, a lodge in a clearing and \n"
        << "drag your magic staff towards it.\n\n"
        << "The cabin is tall but not wide. As you get closer your eyes adjust and you can \n"
        << "see it is made of thick logs holding a sharp slanted roof.\n\n"
        << "The dark forest behind you seems to receed as you step up onto the short porch \n"
        << "glad to be out of the wind even for a moment.\n\n"
        << "You swat away a nest of spider webs and take a breath.\n\n";


    while (gameRunning)
    {
        if (currentGame.Tick() == 1)
        {
            gameRunning = false;
        };
    }

    std::cout << "Application Ended." << std::endl;

    return 0;
}
