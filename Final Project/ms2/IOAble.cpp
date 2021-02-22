/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
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

#include <iostream>
#include "IOAble.h"
using namespace std;
using namespace sdds;


std::ostream& IOAble::csvWrite(std::ostream& os) const
{
    return os;
}

std::istream& IOAble::csvRead(std::istream& is)
{
    return is;
}

std::ostream& IOAble::write(std::ostream& os) const
{
    return os;
}

std::istream& IOAble::read(std::istream& is)
{
    return is;
}

IOAble::~IOAble()
    {
    }
    std::ostream& sdds::operator<<(std::ostream& os, const IOAble& I)
    {
        I.write(os);
        return os;
    }
    std::istream& sdds::operator>>(std::istream& is, IOAble& I)
    {
        I.read(is);
        return is;
    }
