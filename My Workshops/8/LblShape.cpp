//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       8 (Lab)
// Date:           17/11/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>

#include "LblShape.h"

using namespace std;
using namespace sdds;

    const char* LblShape::label() const
    {
        return m_label;
    }

    LblShape::LblShape()
    {
        //the m_label is already initialized to null
    }

    LblShape::LblShape(const char* label)
    {
        int temp;
        temp = strlen(label);
        m_label = new char[temp + 1];
        strcpy(m_label, label);
    }

    LblShape::~LblShape()
    {
        delete[] m_label;
    }

    void LblShape::getSpecs(std::istream& istr)
    {
        char temp[21] = {0};

        istr.get(temp, 21, ',');
        delete[] m_label;

        int local = strlen(temp);

        m_label = new char[local + 1];

        strcpy(m_label, temp);
        istr.ignore(2000, ',');
    }

