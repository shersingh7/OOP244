#pragma once
//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       1 (DIY)
// Date:           22/09/2020
//==============================================

#pragma once
#ifndef sdds_SCHOOL_H
#define sdds_SCHOOL_H

#include "File.h"

namespace sdds
{
   
    struct School
    {
        char code[5];
        int ext;
    };


    bool loadSchoolInfo();
    void displayInfo(const char scode[]);
    void displayCode(const School* mvp);
    bool hasCode(const School* mvp, const char scode[]);

}




#endif
