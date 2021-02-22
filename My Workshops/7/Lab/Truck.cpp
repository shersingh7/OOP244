//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       7 (Lab)
// Date:           9/10/2020
//==============================================
#define _CRT_SECURE_NO_WARNINGS

#include "Truck.h"

using namespace std;
using namespace sdds;

Truck::Truck(const char* numPlate, const int builtYear, const double capacity, const char* address) :Vehicle(numPlate, builtYear)
{
	m_capacity = capacity;
	m_cargoLoad = 0;
	Vehicle::moveTo(address);
}

bool Truck::addCargo(double cargo)
{
	bool ok = false;
	double original = m_cargoLoad;

	m_cargoLoad += cargo;

	if (m_cargoLoad > m_capacity)
	{
		m_cargoLoad = m_capacity;
	}
	if (original != m_cargoLoad)
	{
		ok = true;
	}
	return ok;
}

bool Truck::unloadCargo()
{
	bool ok = false;
	double original = m_cargoLoad;

	m_cargoLoad = 0;

	if (original != m_cargoLoad)
	{
		ok = true;
	}
	return ok;
}

std::ostream& Truck::write(std::ostream& os) const
{
	Vehicle::write(os);

	os << " | " << m_cargoLoad << "/" << m_capacity;

	return os;
}

std::istream& Truck::read(std::istream& in)
{
	Vehicle::read(in);

	cout << "Capacity: ";
	in >> m_capacity;

	cout << "Cargo: ";
	in >> m_cargoLoad;

	return in;
}

std::ostream& sdds::operator<<(std::ostream& os, const Truck& T)
{
	T.write(os);
	return os;
}

std::istream& sdds::operator>>(std::istream& in, Truck& T)
{
	T.read(in);
	return in;
}
