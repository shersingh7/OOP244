/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
Version 1.0
Author:	Davinder Verma
Revision History
-----------------------------------------------------------
Date      Reason
2020/11/15  Preliminary release
2020/11/19  Debugged DMA
2020/11/24	Debugged the constructor
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>

#include "IOAble.h"
#include "Ticket.h"

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_

namespace sdds
{
	class Patient : public IOAble
	{
		char* m_name;
		int ohipNum;
		Ticket m_ticket;
		bool fileFlag;

	public:

		Patient(int tNum = 0, bool fileIO = false);		//Constructor
		~Patient();									//Destructor

		Patient(const Patient& P) = delete;				//Copy Constructor
		Patient& operator=(const Patient& P) = delete;	//Assignment Operator

		virtual char type() const = 0;	//Pure Virtual Function
		bool fileIO()const;				//Query
		void fileIO(bool fileIO);		//Modifier


		void setArrivalTime();	//Sets the time of the ticket of the patient to the current time
		operator Time()const;	//returns the time of the ticket
		int number()const;

		std::ostream& csvWrite(std::ostream& os)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& istr);
	};
	bool operator==(const Patient& P, char a);				//Character Comparison
	bool operator==(const Patient& P1, const Patient& P2);	//Patient Comparison

}
#endif // !SDDS_PATIENT_H_


