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

    String MainString("Wow");

    String SecondString;

    SecondString = MainString;


    Room rHolder = currentGame.GetRoomObject({1,1});

    rHolder.useItem();
    rHolder.useItem();



    return 0;
}
