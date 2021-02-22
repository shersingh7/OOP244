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
#include "School.h"
using namespace std;
using namespace sdds;

void flushkeys();
bool yes();

// flushes the keyboard
void flushkeys()
{
    while (cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes()
{
    char ch = cin.get();
    flushkeys();
    return ch == 'y' || ch == 'Y';
}


int main()
{
    bool done = false;
    char code[5];
    loadSchoolInfo();
    cout << "Seneca School Extension search." << endl << endl;
    while (!done)
    {
        cout << "Enter the School code: ";
        cin >> code;
        flushkeys();
        displayInfo(code);
        cout << "Do another search? (Y)es: ";
        done = !yes();
        cout << endl;
    }
    cout << "Goodbye!" << endl;
    return 0;
}