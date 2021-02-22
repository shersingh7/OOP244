//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       8 (Lab)
// Date:           17/11/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds
{
   class Shape 
   {
   public:
	   	   virtual void draw(std::ostream& os)const = 0;
		   virtual void getSpecs(std::istream& istr) = 0;
		   virtual ~Shape();
   };
   std::ostream& operator<<(std::ostream& os, Shape& S);
   std::istream& operator>>(std::istream& istr, Shape& S);
}

#endif // !SDDS_SHAPE_H

