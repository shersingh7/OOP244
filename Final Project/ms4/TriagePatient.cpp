/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
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
#include "TriagePatient.h"

using namespace std;
using namespace sdds;

int nextTriageTicket = 1; //Global Variable

TriagePatient::TriagePatient() :Patient(nextTriageTicket)
{
	symptoms = nullptr;
	nextTriageTicket++;
}

TriagePatient::~TriagePatient()
{
	delete[] symptoms;
}


char TriagePatient::type() const
{
	char temp = 'T';
	return temp;
}

std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
{
	Patient::csvWrite(ostr);
	ostr << ',' << symptoms;
	return ostr;
}

std::istream& TriagePatient::csvRead(std::istream& istr)
{
	delete[] symptoms;

	Patient::csvRead(istr);
	istr.ignore();	//Ignores Comma Character

	char temp[511] = {0};
	istr.get(temp, 511, '\n');

	int local = strlen(temp);
	symptoms = new char[local + 1];

	strcpy(symptoms, temp);

	nextTriageTicket = Patient::number() + 1;

	return istr;
}

std::ostream& TriagePatient::write(std::ostream& ostr) const
{
	if (fileIO() == true)
	{
		csvWrite(ostr);
	}
	else
	{
		ostr << "TRIAGE" << endl;
		Patient::write(ostr);
		ostr << endl;
		ostr << "Symptoms: " << symptoms << endl;
	}

	return ostr;
}

std::istream& TriagePatient::read(std::istream& istr)
{
	if (fileIO() == true)
	{
		csvRead(istr);
	}
	else
	{
		delete[] symptoms;

		Patient::read(istr);
		cout << "Symptoms: ";

		char temp[511] = {0};

		istr.get(temp, 511, '\n');
		istr.ignore();

		int local = strlen(temp);

		symptoms = new char[local + 1];
		strcpy(symptoms, temp);

		nextTriageTicket = Patient::number() + 1;
	}
	return istr;
}
