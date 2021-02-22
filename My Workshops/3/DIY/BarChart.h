//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       3 (DIY)
// Date:           08/10/2020
//==============================================

#ifndef SDDS_BARCHART_H_
#define SDDS_BARCHART_H_

#include "Bar.h"

namespace sdds
{
	class BarChart
	{
		//Mandatory member variables
		char* m_chartTitle;				//holds the dynamically allocated "title of the chart"
		Bar* m_barArrays;				//holds the dynamically allocated array of Bars

		//Suggested member variables
		char fill;						//holds the fill character
		int sizeOfArray;				//holds the size of the dynamically allocated array of Bars
		int m_samplesAdded;				
		int m_noOfSamples;				

	public:

		//Mandatory member functions
		void init(const char* title, int noOfSamples, char fillCharacter);
		void add(const char* bar_title, int value);
		void draw()const;
		void deallocate();

	};

}
#endif // !SDDS_BARCHART_H_