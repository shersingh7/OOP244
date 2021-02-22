/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.cpp
Version 1.0
Author:	Davinder Verma
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/15  Preliminary release
2020/11/19  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
#include "IOAble.h"
using namespace std;
using namespace sdds;

    Patient::Patient(int tNum, bool fileIO) : m_ticket(tNum)
    {
        m_name = nullptr;
        ohipNum = 0;
        fileFlag = fileIO;
    }

    Patient::~Patient()
    {
        delete[] m_name;
    }

    bool Patient::fileIO()const
    {
        return fileFlag;
    }

    void Patient::fileIO(bool fileIO)
    {
        fileFlag = fileIO;
    }

    bool sdds::operator==(const Patient& P, char a)
    {
        bool ok = false;

        if (P.type() == a)
        {
            ok = true;
        }
        return ok;
    }

    bool sdds::operator==(const Patient& P1, const Patient& P2)
    {
        bool ok = false;

        if (P1.type() == P2.type())
        {
            ok = true;
        }
        return ok;
    }

    void Patient::setArrivalTime()
    {
        m_ticket.resetTime();
    }

    Patient::operator Time() const
    {
        int temp = Time(m_ticket);
        return temp;
    }

    int Patient::number() const
    {
        int local = m_ticket.number();
        return local;
    }

    std::ostream& Patient::csvWrite(std::ostream& os) const
    {
        os << type() 
            << "," << m_name 
            << "," << ohipNum 
            << ",";
        m_ticket.csvWrite(os);

        return os;
    }

    std::istream& Patient::csvRead(std::istream& istr)
    {
        char name[51] = {0};
        istr.get(name, 51, ',');

        int temp = strlen(name);

        delete[] m_name;
        m_name = new char[temp + 1];

        strcpy(m_name, name);

        istr.ignore(2000, ',');
        istr >> ohipNum;
        istr.ignore(2000, ',');

        m_ticket.csvRead(istr);

        return istr;
    }

    std::ostream& Patient::write(std::ostream& os) const
    {
        os << m_ticket << endl 
           << m_name << ", OHIP: " 
           << ohipNum;

        return os;
    }

    std::istream& Patient::read(std::istream& istr)
    {
        cout << "Name: ";
        char name[51] = {0};
        istr.get(name, 51, '\n');

        delete[] m_name;
        int temp = strlen(name);
        m_name = new char[temp + 1];

        strcpy(m_name, name);

        istr.ignore(2000, '\n');
        cout << "OHIP: ";

        ohipNum = validInput(100000000, 999999999);

        return istr;
    }

    

