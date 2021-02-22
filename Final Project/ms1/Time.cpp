/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: Time.cpp
Version 1.0
Author:	Davinder Verma
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/09  Preliminary release
2020/11/10  Debugged read function in Time.cpp
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS_

#include "Time.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;
using namespace sdds;

Time& Time::reset()
{
	m_min = getTime();
	return *this;
}

Time::Time(unsigned int min)
{
	m_min = 0;
	m_min = min;
}

std::ostream& sdds::Time::write(std::ostream& ostr) const
{
	int hh, mm;

	hh = (m_min / 60);	// Converts min to hours
	mm = m_min % 60;	//Sets the remaining min to mm

	ostr << setw(2) << setfill('0') << hh << ":"
		<< setw(2) << setfill('0') << mm;

	return ostr;
}

std::istream& sdds::Time::read(std::istream& istr)
{
	string hour, min;
	char a=0;
	string temp;
	int h = 0, m = 0;

	istr >> h >> a >> m;
	if (a != ':')
	{
		istr.setstate(ios::failbit);
	}
	else
	{
		m_min = h * 60 + m; // Converts time to number of minutes
	}

	return istr;
}

sdds::Time::operator int() const
{
	return m_min;
}

Time& sdds::Time::operator*=(int val)
{
	m_min = m_min * val;
	return *this;
}

Time& sdds::Time::operator-=(const Time& D)
{
	int local = 0;
	if (m_min > (unsigned)D)
	{
		local = m_min - D;

	}
	else
	{
		local = (1440 + m_min) - D;
	}
	
	m_min = local;

	return *this;
}

std::ostream& sdds::operator<< (std::ostream& os, const Time& t)
{
	t.write(os);
	return os;
}
std::istream& sdds::operator>> (std::istream& is, Time& t)
{
	t.read(is);
	return is;
}

