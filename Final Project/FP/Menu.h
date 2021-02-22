/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: Menu.h
Version 1.0
Author:	Davinder Verma
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/09  Preliminary release
2020/11/10  Debugged read function in Time.cpp
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
   class Menu{
      char* m_text = nullptr;   //holds the menu content dynamically
      int m_noOfSel;            //holds the number of options displayed in menu content
   public:
      Menu(const char* text, int NoOfSelections); //Dynamically allocates memory to hold the content pointed by m_text
      virtual ~Menu();                            //Deallocates the dynamically allocated memory
      Menu(const Menu&) = delete;                 //Copy Constructor
      Menu& operator=(const Menu&) = delete;      //Assignment operator
      std::ostream& display(std::ostream& ostr = std::cout)const;   //Displays the menu
      int& operator>>(int& Selection);
   };
}
#endif // !SDDS_MENU_H_
