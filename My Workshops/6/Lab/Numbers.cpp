//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       6 (Lab)
// Date:           4/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Numbers.h"
using namespace std;
namespace sdds 
{
    Numbers* numbers;

    Numbers::Numbers() 
    {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char* filename) 
    {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) 
        {
            delete[] m_numbers;
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        }
        else 
        {
            sort();
        }
    }

    Numbers::Numbers(const Numbers& source)     //Copy constructor
    {
        setEmpty();
        m_isOriginal = false;
        *this = source;
    }

    Numbers& Numbers::operator=(const Numbers& source)     //Copy assignment operator
    {
        delete[] m_numbers;
        m_numCount = source.m_numCount;
        m_numbers = new double[source.m_numCount];

        for (int i = 0; i < source.m_numCount; i++)
        {
            m_numbers[i] = source.m_numbers[i];
        }

        return *this;
    }

    Numbers& Numbers::operator+=(const double number)    
    {
        if (!isEmpty())
        {
            m_numCount++;
            double* temp = nullptr;
            temp = new double[m_numCount];

            for (int i = 0; i < m_numCount - 1; i++)
            {
                temp[i] = m_numbers[i];
            }

            temp[m_numCount - 1] = number;
            delete[] m_numbers;
            m_numbers = temp;
            sort();
        }
        return *this;
    }

    std::ostream& Numbers::display(std::ostream& ostr) const
    {
        if (isEmpty())
        {
            cout << "Empty list";
        }
        else
        {
            ostr << "=========================" << endl;

            if (m_isOriginal)
            {
                ostr << m_filename << endl;
            }
            else
            {
                ostr << "*** COPY ***" << endl;
            }

            for (int i = 0; i < m_numCount - 1; i++)
            {
                ostr << m_numbers[i] << ", ";
            }

            ostr << m_numbers[m_numCount - 1] << endl;
            ostr << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average :        " << average() << endl;
            ostr << "=========================";
        }

        return ostr;
    }

    Numbers::~Numbers() 
    {
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    bool Numbers::isEmpty() const 
    {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty() 
    {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }

    void Numbers::setFilename(const char* filename) 
    {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }

    bool sdds::Numbers::load()
    {
        bool ok = false;
        int count = 0;

        if (m_numCount > 0)
        {
            m_numbers = new double[(m_numCount)];
            ifstream filein(m_filename);
            string input;

            while (!filein.fail() && count < m_numCount)
            {
                filein >> m_numbers[count];
                count++;
            }
        }

        if (count == m_numCount)
        {
            ok = true;
        }
        return ok;
    }


    double Numbers::average() const
    {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }

    double Numbers::min() const
    {
        double minVal = 0.0;
        if (!isEmpty())
        {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }

    double Numbers::max() const
    {
        double maxVal = 0.0;
        if (!isEmpty())
        {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    void Numbers::sort() 
    {
        int i, j;
        double temp;
        for (i = m_numCount - 1; i > 0; i--) 
        {
            for (j = 0; j < i; j++)
            {
                if (m_numbers[j] > m_numbers[j + 1]) 
                {
                    temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }

    int sdds::Numbers::numberCount()
    {
        m_numCount = 0;
        string input;
        ifstream filein(m_filename);

        while (std::getline(filein, input))
        {
            m_numCount++;
        }
        return m_numCount;
    }

    void sdds::Numbers::save()
    {
        if (m_isOriginal == true && !isEmpty())
        {
            ofstream fileout(m_filename, ios::trunc);
            for (int i = 0; i < m_numCount; i++)
            {
                fileout << m_numbers[i] << endl;
            }
        }
    }

    std::ostream& operator<<(std::ostream& os, const Numbers& N)
    {
        return N.display(os);
    }

    std::istream& operator>>(std::istream& istr, Numbers& N)
    {
        double a;
        istr >> a;
        N += a;
        return istr;
    }
}