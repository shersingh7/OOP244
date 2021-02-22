//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       3 (Lab)
// Date:           06/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include "Transcript.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace sdds;


char Subject::grade() const
{
    char grade[2];

    if (m_mark >= 80)
    {
        strcpy(grade, "A");
        return *grade;
    }

    else if (m_mark >= 70)
    {
        strcpy(grade, "B");
        return *grade;
    }

    else if (m_mark >= 60)
    {
        strcpy(grade, "C");
        return *grade;
    }

    else if (m_mark >= 50)
    {
        strcpy(grade, "D");
        return *grade;
    }

    else
    {
        strcpy(grade, "F");
        return *grade;
    }
}

void Subject::setEmpty()
{
    m_mark = -1;
    m_code[0] = '\0';
}

void Subject::set(const char* code, int mark)
{
    if (mark >= 0 && mark <= 100)
    {
        m_mark = mark;
        strcpy(m_code, code);
    }
    else
    {
        m_mark = 0;
        m_code[0] = '\0';
    }
}

float Subject::scale4() const
{
    float scale = 0;
    if (m_mark >= 80)
    {
        scale = 4.0;
    }
    else if (m_mark >= 70)
    {
        scale = 3.0;
    }
    else if (m_mark >= 60)
    {
        scale = 2.0;
    }
    else if (m_mark >= 50)
    {
        scale = 1.0;
    }
    else
    {
        scale = 0.0;
    }
    return scale;
}

bool Subject::isValid() const
{
    bool ok = false;

    if (m_mark >= 0 && m_mark <= 100)
    {
        ok = true;
    }
    return ok;
}

void Subject::display() const
{
    if (isValid())
    {
        cout << setw(15);
        cout << left << m_code;
        cout << setw(3);
        cout << right << m_mark;
        cout << setw(10);
        cout << right << grade();
        cout << endl;
    }
}