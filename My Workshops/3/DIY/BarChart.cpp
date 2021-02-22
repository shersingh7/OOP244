//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       3 (DIY)
// Date:           08/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include "BarChart.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace sdds;

void BarChart::init(const char* title, int noOfSamples, char fillCharacter)
{
    if (noOfSamples < 0 && title == nullptr)
    {
        title = nullptr;
        fillCharacter = '\0';
        noOfSamples = -1;
    }
    else
    {
        m_noOfSamples = noOfSamples;
        fill = fillCharacter;
        m_samplesAdded = 0;

        int length = strlen(title);
        m_chartTitle = new char[length + 1];

        strcpy(m_chartTitle, title);

        m_barArrays = new Bar[m_noOfSamples];

    }
}

void BarChart::add(const char* bar_title, int value)
{
    if (m_samplesAdded < m_noOfSamples)
    {
        m_barArrays[m_samplesAdded].set(bar_title, fill, value);
        m_samplesAdded++;
    }
}

void BarChart::draw()const
{
    if (m_samplesAdded == m_noOfSamples)
    {
        cout << m_chartTitle << endl;

        for (int i = 0; i < 71; i++)
        {
            cout << "-";
        }

        cout << endl;

        for (int i = 0; i < m_noOfSamples; i++)
        {
            m_barArrays[i].draw();
        }

        for (int i = 0; i < 71; i++)
        {
            cout << "-";
        }

        cout << endl;

    }
    else
    {
        cout << "Invalid Chart!" << endl;
    }

}

void BarChart::deallocate()
{
    delete[] m_chartTitle;
    m_chartTitle = nullptr;

    delete[] m_barArrays;
    m_barArrays = nullptr;
}