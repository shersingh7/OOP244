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
#include <iostream>
#include <iomanip>

using namespace std;
using namespace sdds;

void Transcript::setEmpty()
{
    m_studentName = nullptr;
    m_subjects = nullptr;
}

bool Transcript::isValid() const
{
    bool ok = false;

    if (!(m_studentName == nullptr && m_subjects == nullptr))
    {
        for (int i = 0; i < m_noOfSubjects; i++)
        {
            if (m_subjects[i].isValid())
            {
                ok = true;
            }
        }
    }

    return ok;
}

void Transcript::Title() const
{
    cout << m_studentName << endl;
    cout << "-----------------------------" << endl;
}

float Transcript::gpa() const
{
    float sum = 0, gpa = 0;

    for (int i = 0; i < m_noOfSubjects; i++)
    {
        sum += m_subjects[i].scale4();
    }

    gpa = sum / m_noOfSubjects;

    return gpa;
}

void Transcript::footer() const
{
    cout << "-----------------------------" << endl;
    cout << "                     GPA: ";
    cout << fixed;
    cout << setprecision(1);
    cout << gpa() << endl;
}

void Transcript::init(const char* studentName, int noOfSubjects)
{

    if (noOfSubjects < 0 && studentName == nullptr)
    {
        studentName = nullptr;
        noOfSubjects = -1;

    }
    else
    {
        m_noOfSubjects = noOfSubjects;
        m_subjectsAdded = 0;

        int length = strlen(studentName);
        m_studentName = new char[length + 1];

        strcpy(m_studentName, studentName);

        m_subjects = new Subject[m_noOfSubjects];
    }
}

bool Transcript::add(const char* subject_code, int mark)
{
    bool ok = false;

    if (m_subjectsAdded < m_noOfSubjects)
    {
        m_subjects[m_subjectsAdded].set(subject_code, mark);
        m_subjectsAdded++;
        ok = true;
    }
    return ok;
}

void Transcript::display() const
{
    if (m_subjectsAdded != m_noOfSubjects)
    {
        cout << "Invalid Transcirpt!" << endl;
    }
    else
    {
        Title();

        for (int i = 0; i < m_noOfSubjects; i++)
        {
            m_subjects[i].display();
        }

        footer();
    }
}

void Transcript::deallocate()
{
    delete[] m_studentName;
    m_studentName = nullptr;

    delete[] m_subjects;
    m_subjects = nullptr;
}