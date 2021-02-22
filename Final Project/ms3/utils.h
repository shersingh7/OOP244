/* Citation and Sources...
Final Project Milestone 3
Module: utils
Filename: utils.h
Version 1.0
Author:	Davinder Verma
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/15  Preliminary release
2020/11/19  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#pragma once
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
   int getInt();
   int validInput(int min, int max); //Validates the input for the given min and max 
   int getTime(); // returns the time of day in minutes

   extern bool debug; // this makes bool sdds::debug variable in utils.cpp global to 
                      // all the files which include: "utils.h" 
                      //(you will learn this in detail in oop345)
}
#endif // !SDDS_UTILS_H_

