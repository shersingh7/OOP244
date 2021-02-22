/* Citation and Sources...
Final Project Milestone ?
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include "utils.h"
#include "Menu.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;
using namespace sdds;

Menu::Menu(const char* text, int NoOfSelections)
{
	delete[] m_text;
	m_text = new char[strlen(text) + 1];
	strcpy(m_text, text);
	m_noOfSel = NoOfSelections;
}

sdds::Menu::~Menu()
{
	delete[] m_text;
	m_noOfSel = 0;
}

std::ostream& sdds::Menu::display(std::ostream& ostr) const
{
	ostr << "Tester Options menu:\n1- Option one\n2- Option two\n3- Option three\n";
	ostr << "0- Exit\n> ";
	return ostr;
}

int& sdds::Menu::operator>>(int& Selection)
{
	int input = 0;
	
	display();
	cin >> input;

	if (input >= 0 && input <= m_noOfSel)
	{
		Selection = input;
	}
	else
	{
		do
		{
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "Invalid value enterd, retry[0 <= value <= " << m_noOfSel << "]: ";
			cin >> input;
			
		} while (!(input >= 0 && input <= m_noOfSel));

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "Bad integer value, try again: ";
			cin >> input;
		}
		Selection = input;
	}
		
	return Selection;
}
