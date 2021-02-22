//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       8 (Lab)
// Date:           17/11/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include "Line.h"

using namespace std;
using namespace sdds;

    Line::Line() :LblShape()
    {
        m_length = 0;
    }

    Line::~Line()
    {
    }

    Line::Line(const char* label, int length) : LblShape(label)
    {
        m_length = length;
    }

    void Line::getSpecs(std::istream& istr)
    {
        LblShape::getSpecs(istr);

        istr >> m_length;
        istr.ignore(2000, '\n');
    }

    void Line::draw(std::ostream& os) const
    {
        if ((m_length > 0) && (LblShape::label() != nullptr))
        {
            os << LblShape::label() << endl;

            for (int i = 0; i < m_length; i++)
            {
                os << '=';
            }
        }
    }


