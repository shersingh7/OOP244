//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       5 (DIY)
// Date:           21/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds
{
    void Mark::setEmpty() 
    {
        m_marks = 0;
        m_gpa = 0;
        m_grade = 'X';
    }

    bool Mark::isEmpty()
    {
        bool ok = false;

        if (m_marks == 0)
        {
            ok = true;
        }
        return ok;
    }

    void Mark::setGrade()
    {
        if (m_marks >= 0 && m_marks < 50)
        {
            m_grade = 'F';
            m_gpa = 0.0;
        }

        if (m_marks >= 50 && m_marks < 60)
        {
            m_grade = 'D';
            m_gpa = 1.0;
        }

        if (m_marks >= 60 && m_marks < 70)
        {
            m_grade = 'C';
            m_gpa = 2.0;
        }

        if (m_marks >= 70 && m_marks < 80)
        {
            m_grade = 'B';
            m_gpa = 3.0;
        }

        if (m_marks >= 80 && m_marks <= 100)
        {
            m_grade = 'A';
            m_gpa = 4.0;
        }

    }

    bool Mark::isValid(const int num)
    {
        bool ok = false;

        if (num >= 0 && num <= 100)
        {
            ok = true;
        }

        return ok;
    }

    Mark::operator bool() const
    {
        bool ok = false;

        if (((m_marks >= 0) && (m_marks <= 100)) || (m_grade != 'X'))
        {
            ok = true;
        }

        return ok;
    }

    Mark::operator int() const
    {
        return m_marks;
    }

    Mark::operator double() const
    {
        return m_gpa;
    }

    Mark::operator char() const
    {
        return m_grade;
    }

    Mark::Mark() 
    {
        m_marks = 0;
    }

    Mark& Mark::operator+=(int number)
    {
        if (*this)
        {
            int temp = number + m_marks;

            if (temp >= 0 && temp <= 100 && m_grade != 'X')
            {
                m_marks += number;
                setGrade();
            }
            else
            {
                setEmpty();
            }
        }

        return *this;
    }


    Mark::Mark(int number)
    {
        if (isValid(number))
        {
            m_marks = number;
            setGrade();
        }
        else
        {
            setEmpty();
        }
    }

    Mark& Mark::operator=(const int number)
    {
        if (*this)
        {
            if (isValid(number))
            {
                m_marks = number;
                setGrade();
            }
            else
            {
                setEmpty();
            }
        }
        return *this;
    }

    int operator+=(int& sum, Mark& mark)
    {
        if (mark.m_marks < 100)
        {
            sum += mark.m_marks;
        }

        return sum;
    }










}