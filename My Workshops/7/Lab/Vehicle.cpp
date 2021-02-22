//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       7 (Lab)
// Date:           9/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>

#include "Vehicle.h"

using namespace std;
using namespace sdds;

Vehicle::Vehicle(const char* numPlate, const int builtYear)
{
	strcpy(m_numPlate, numPlate);
	strcpy(m_address, "Factory");
	m_year = builtYear;
}
void Vehicle::moveTo(const char* address)
{

	if (address != nullptr)
	{
		cout << "|";
		cout << setw(8) << right << m_numPlate << "| |";
		cout << setw(20) << right << m_address << " ---> ";
		cout << setw(20) << left << address << "|" << endl;
		strcpy(m_address, address);
	}

}
std::ostream& Vehicle::write(std::ostream& os) const
{
	os << "| " << m_year << " | " << m_numPlate << " | " << m_address;

	return os;
}
std::istream& Vehicle::read(std::istream& in)
{
	cout << "Built year: ";
	in >> m_year;
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "License plate: ";
	in.getline(m_numPlate, 9);

	cout << "Current location: ";
	in.getline(m_address, 64);

	return in;
}
std::ostream& sdds::operator<<(std::ostream& os, const Vehicle& V)
{
	V.write(os);
	return os;
}
std::istream& sdds::operator>>(std::istream& in, Vehicle& V)
{
	V.read(in);
	return in;
}

