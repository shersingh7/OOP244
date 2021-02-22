//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       8 (Lab)
// Date:           17/11/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds 
{
   class Rectangle :public LblShape
   {
	   int m_width;		//holds the width
	   int m_height;	//holds the height of a rectangular frame

   public:
		   Rectangle();		//Deafault Constructor
		   Rectangle(const char* label, int width, int height);
		   void getSpecs(std::istream& istr);
		   void draw(std::ostream& os)const;
   };
}
#endif