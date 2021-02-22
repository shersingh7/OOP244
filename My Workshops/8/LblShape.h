//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       8 (Lab)
// Date:           17/11/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds 
{
	class LblShape : public Shape
	{
		char* m_label = nullptr; //holds the dynamically allocated label for the Shape

	protected:

		const char* label() const;

	public:

		LblShape();				//Default Constructor
		LblShape(const char* label);
		~LblShape();			//Destructor
		void getSpecs(std::istream& istr);
		LblShape(const LblShape&) = delete;                 //Copy Constructor
		LblShape& operator=(const LblShape&) = delete;      //Assignment operator
	};

}
#endif // !SDDS_LBLSHAPE_H


