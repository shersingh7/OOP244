//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       3 (DIY)
// Date:           08/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include "Bar.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace sdds;

void Bar::setEmpty()
{
    m_title[0] = '\0';
    m_fillValue = '\0';
    m_sampleValue = -1;
}

void Bar::set(const char* title, char fillchar, int sampleValue)
{
    if (sampleValue < 0 && sampleValue > 100)
    {
        setEmpty();
    }
    else
    {
        m_sampleValue = sampleValue;
        strcpy(m_title, title);
    }
}

bool Bar::isValid()const
{
    bool ok = false;

    if (m_sampleValue >= 0 && m_sampleValue <= 100)
    {
        ok = true;
    }
    return ok;
}

void Bar::draw()const
{
    if (isValid())
    {
        cout.fill('.');
        cout.width(20);
        cout << left;
        cout << m_title;
        cout << "|";

        int finalValue = m_sampleValue / 2;

        for (int i = 0; i < finalValue; i++)
        {
            cout << '=';
        }

        cout << endl;
    }
}
