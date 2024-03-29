// Introduction to C++ - Task 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "header.h"

int main()
{
 
    std::cout << "Hello World." << std::endl;

    Game currentGame;

    bool gameRunning = true;

    std::cout << "----------------------------------------\n\n"
        <<"You have been walking in the woods for hours, a far longer hike than you planned.\n"
        <<"In the dark of a sudden storm you lost your way and you fear you will never find \n"
        <<"the carpark again.\n\n"
        <<"In a flash of approaching lightning, you see a house, a lodge in a clearing and \n"
        << "drag your feet towards it.\n\n"
        << "The cabin is tall but not wide. As you get closer your eyes adjust and you can \n"
        << "see it is made of thick logs holding a sharp slanted roof.\n\n"
        << "The dark forest behind you seems to receed as you step up onto the short porch \n"
        << "glad to be out of the wind even for a moment.\n\n"
        << "You swat away a nest of spider webs and take a breath.\n\n";

   // currentGame.DescribeAllRooms();

    while (gameRunning)
    {
        if (currentGame.Tick() == 1)
        {
            gameRunning = false;
        };
    }

    std::cout << "Goodbye World." << std::endl;

    return 0;
}
