/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.h
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

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include "Patient.h"

namespace sdds
{

	class CovidPatient : public Patient
	{

	public:

		CovidPatient();	//Default Constructor

		char type()const;	//Returns character C

		std::ostream& csvWrite(std::ostream& ostr)const;	//Calls the csvWrite of base class
		std::istream& csvRead(std::istream& istr);			//Calls the csvRead of base class
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};

}
#endif // !SDDS_COVIDPATIENT_H_