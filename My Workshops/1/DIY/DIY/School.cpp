//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       1 (DIY)
// Date:           22/09/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "School.h"

using namespace std;
using namespace sdds;
namespace sdds
{
    School school[24];


    // returns true is the genre arg is substring of any of the
   // genres of the target of the mvp (Movie*) arg.
    bool hasCode(const School* mvp, const char scode[]) 
    {

            bool found = false;
      
            if (strstr(mvp->code, scode)) 
            {
                found = true;
            }
        
        return found;
    }

    // loads all the entries into the global array of structures.
    bool loadSchoolInfo()
    {
        School sch;
        int num = 0; // number of entries read
        bool ok = true;
        if (openFile("schools.dat"))
        {
            while (ok && num < 24) 
            {
                ok = readCode(sch.code) &&
                    readExt(&sch.ext);
                if (ok) 
                    school[num++] = sch;
            }
            closeFile();
        }
        return num == 24;
    }

    //This will display the extension if found.
    void displayCode(const School* mvp)
    {
        cout << "416 491 5050 x " << mvp->ext << endl;
    }
    
    //This will search the input in the global array.
    void displayInfo(const char scode[])
    {
        int i;
        bool found = false;

        for (i = 0; i < 24; i++)
        {
            if (hasCode(&school[i], scode))
            {
                found = true;
                displayCode(&school[i]);
            }
        }
                
        if (!found) 
        {
            cout << scode << " School code not found!"  << endl;
        }
    }

    
}

