/* Citation and Sources...
Final Project Milestone 3
Module: Time
Filename: Time.h
Version 1.0
Author:	Davinder Verma
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/15  Preliminary release
2020/12/04  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
namespace sdds {
   class Time {
       
      unsigned int m_min = 0;

   public:
      Time& reset();                                    //Resets the time to current time
      Time(unsigned int min = 0);                       //Sets the time in the object
      std::ostream& write(std::ostream& ostr) const;    //Writes the time into a stream in HH:MM format
      std::istream& read(std::istream& istr);           //Reads the time form a stream in H:M format
      operator int()const;                              //Converts time to m_min
      Time& operator *= (int val);                      //Multiplies the Time by val
      Time& operator-=(const Time& D);                  //Calculates the time difference between the current time and the incoming argument Time D
      Time& operator-(const Time& ROperand);
   };
   // helper operator << and >> prototypes
   std::ostream& operator<< (std::ostream& os, const Time& t);  //Inserts a Time object into an ostream object
   std::istream& operator>> (std::istream& is, Time& t);        //Extracts data from an istream object into the Time object

}



#endif // !SDDS_TIME_H

