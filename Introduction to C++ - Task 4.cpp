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

    String MainString("Wow");

    String SecondString;

   // SecondString = MainString;


    Room* rHolder = currentGame.GetRoomObject({ 10,1 });; 

    std::cout << "\n" << rHolder;

    rHolder->useItem();

    rHolder = currentGame.GetRoomObject({ 0,0 });;
    std::cout << "\n" << rHolder;

    rHolder->useItem();


    currentGame.DescribeAllRooms();

    std::cout << "Goodbye World." << std::endl;

    return 0;
}
