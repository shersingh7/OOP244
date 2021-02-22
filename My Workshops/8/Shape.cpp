//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       8 (Lab)
// Date:           17/11/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include "Shape.h"

using namespace std;
using namespace sdds;

    Shape::~Shape() 
    {
        
    }

    std::ostream& sdds::operator<<(std::ostream& os, Shape& S)
    {
        S.draw(os);
        return os;
    }
    std::istream& sdds::operator>>(std::istream& istr, Shape& S)
    {
        S.getSpecs(istr);
        return istr;
    }

