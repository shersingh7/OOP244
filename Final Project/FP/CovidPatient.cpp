/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.cpp
Version 1.0
Author:	Davinder Verma
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/22  Preliminary release
2020/11/24  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "CovidPatient.h"

using namespace std;
using namespace sdds;

int nextCovidTicket = 1; //Global Variable

CovidPatient::CovidPatient() :Patient(nextCovidTicket)
{
	nextCovidTicket++;
}

char CovidPatient::type() const
{
	char temp = 'C';
	return temp;
}

std::ostream& CovidPatient::csvWrite(std::ostream& ostr) const
{
	Patient::csvWrite(ostr);
	return ostr;
}

std::istream& CovidPatient::csvRead(std::istream& istr)
{
	Patient::csvRead(istr);

	int temp = Patient::number();
	nextCovidTicket = temp + 1;

	return istr;
}

std::ostream& CovidPatient::write(std::ostream& ostr) const
{
	if (fileIO() == true)
	{
		csvWrite(ostr);
	}
	else
	{
		ostr << "COVID TEST" << endl;
		Patient::write(ostr) << endl;
	}

	return ostr;
}

std::istream& CovidPatient::read(std::istream& istr)
{
	if (fileIO() == true)
	{
		csvRead(istr);
	}
	else
	{
		Patient::read(istr);
	}
	
	return istr;
}

