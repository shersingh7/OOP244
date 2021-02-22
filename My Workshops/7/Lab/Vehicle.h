//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       7 (Lab)
// Date:           9/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#ifndef _SDDS_VEHICLE_H_
#define _SDDS_VEHICLE_H_

#include <iostream>

namespace sdds
{
	class Vehicle
	{
	protected:
		char m_numPlate[9]; //Holds the plate number
		char m_address[64];	//Holds the addresss
		int m_year;			//Vehicle Built Year

	public:

		Vehicle(const char* numPlate, const int builtYear); //Custom Constructor
		void moveTo(const char* address);					//Changes the address
		std::ostream& write(std::ostream& os)const;			//Inserts os in the current object
		std::istream& read(std::istream& in);				//Reads from the stream in from the current object
	};
	std::ostream& operator<< (std::ostream& os, const Vehicle& V);	
	std::istream& operator>> (std::istream& in, Vehicle& V);		
}
#endif // !_SDDS_VEHICLE_H_