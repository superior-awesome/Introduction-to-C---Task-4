// Introduction to C++ - Task 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "header.h"

int main()
{
 
    Game currentGame;

   // String testStr("test");
   //bool bcheck = testStr.EqualTo("tesdt");

   // std::cout << "----> " << bcheck << std::endl;

    bool gameRunning = true;

    Room rHolder = currentGame.GetRoomObject({1,1});
    rHolder.useItem();



    while (gameRunning)
    {
        currentGame.Tick();
    }
    
    return 0;
}
