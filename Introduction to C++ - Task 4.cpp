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


    std::cout << "The cabin is tall but not wide. As you get closer your eyes adjust and you can see the sturdy log walls and single slanted roof."
        << "\nThe dark forest behind you seems to receed as you step up onto the short porch glad to be out of the wind even for a moment."
        << "\nYou swat away a spider web and take a breath.";

    currentGame.MovePlayer();

    currentGame.MovePlayer();

    Room* rHolder = currentGame.GetRoomObject({ 0,0 });;

  //  rHolder->useItem();


//    currentGame.DescribeAllRooms();

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
