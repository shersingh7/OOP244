//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       8 (Lab)
// Date:           17/11/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include "Rectangle.h"

#include <iostream>
#include <iomanip>

using namespace std;
using namespace sdds;

	Rectangle::Rectangle() :LblShape()
	{
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label)
	{
		/*if ((m_height < 3) && (m_width < strlen(LblShape::label()) + 2))
		{
			m_width = 0;
			m_height = 0;
		}
		else*/
		{
			m_width = width;
			m_height = height;
		}
		
	}

	void Rectangle::getSpecs(std::istream& istr)
	{
		LblShape::getSpecs(istr);

		istr >> m_width;
		istr.ignore();

		istr >> m_height;
		istr.ignore(2000, '\n');
	}

	void Rectangle::draw(std::ostream& os) const
	{
		if (!(m_height == 0 && m_width == 0))
		{
			os << '+';

			for (int i = 0; i < m_width - 2; i++)
			{
				os << '-';
			}

			os << '+' << endl;
			os << '|';
			os << left;
			os << setw((m_width)-2);
			os << LblShape::label() << '|' << endl;
			for (int i = 0; i < m_height - 3; i++)
			{
				os << '|';

				for (int i = 0; i < m_width - 2; i++)
				{
					os << ' ';
				}

				os << '|' << endl;
			}
			os << '+';

			for (int i = 0; i < m_width - 2; i++)
			{
				os << '-';
			}

			os << '+';
		}
		
	}


