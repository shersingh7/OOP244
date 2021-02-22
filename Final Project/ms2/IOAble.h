/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
Version 1.0
Author:	Davinder Verma
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/15  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS_

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds 
{
   class IOAble 
   {
   public:
	   virtual std::ostream& csvWrite(std::ostream& os) const;
	   virtual std::istream& csvRead(std::istream& is);
	   virtual std::ostream& write(std::ostream& os) const;
	   virtual std::istream& read(std::istream& is);
	   virtual ~IOAble();
   };
   std::ostream& operator<<(std::ostream& os, const IOAble& I);
   std::istream& operator>>(std::istream& is, IOAble& I);
}
#endif // !SDDS_IOABLE_H_
