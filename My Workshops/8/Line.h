//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       8 (Lab)
// Date:           17/11/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds
{
	class Line :public LblShape
	{
		int m_length; //Holds the length of the Line in characters

	public:
		Line();		//Default Constructor
		~Line();	//Destructor
		Line(const char* label, int length);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& os)const;
	};
}
#endif // !SDDS_LINE_H

