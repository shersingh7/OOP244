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
#include <string.h>
#include <cstring>
#include "File.h"

using namespace std;
namespace sdds
{
    FILE* fptr;

    // opens the data file and returns true is successful
    bool openFile(const char filename[]) 
    {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // closes the data file
    void closeFile() 
    {
        if (fptr) fclose(fptr);
    }

    // reads the school extension from the global fptr File pointer
    // returns true if successful
    bool readCode(char code[]) 
    {
        return fscanf(fptr, "%[^ ]", code) == 1;
    }

    // reads the year of the movie from the global fptr File pointer
    // returns true if successful
    bool readExt(int* ext) 
    {
        return fscanf(fptr, "%5d", ext) == 1;

    }

}