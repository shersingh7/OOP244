//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       7 (Lab)
// Date:           9/10/2020
//==============================================
#define _CRT_SECURE_NO_WARNINGS

#ifndef _SDDS_TRUCK_H_
#define _SDDS_TRUCK_H_

#include "Vehicle.h"
namespace sdds
{
	class Truck :public Vehicle
	{
		double m_capacity;		//Holds the capacity in kilograms
		double m_cargoLoad;		//Holds the current cargo load

	public:

		Truck(const char* numPlate, const int builtYear, const double capacity, const char* address); //Custom constructor
		bool addCargo(double cargo);					//Adds the cargo capacity
		bool unloadCargo();								//Unloads current cargo
		std::ostream& write(std::ostream& os)const;		
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& T);
	std::istream& operator>>(std::istream& in, Truck& T);
}
#endif // !_SDDS_TRUCK_H_