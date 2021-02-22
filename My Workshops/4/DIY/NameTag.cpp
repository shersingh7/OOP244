//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       4 (DIY)
// Date:           10/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <string>
#include <iomanip>
#include <cstring>
#include "NameTag.h"

using namespace std;
using namespace sdds;

void NameTag::setName(const char* Cstr)
{
	if (Cstr != nullptr)
	{
		//delete[] m_name;
		m_name = nullptr;

		int length = strlen(Cstr);

		if (length >= 40)
		{
			m_name = new char[41];
			strncpy(m_name, Cstr,40);
			m_name[40] = '\0';
		}
		else
		{
			m_name = new char[length + 1];
			strcpy(m_name, Cstr);
		}
	}
}

void NameTag::extLength()
{
	int input;
	int temp;
	int length = 0;

	cout << "Please enter a 5 digit phone extension: ";
	cin >> input;

	temp = input;

	while (input != 0)
	{
		input = input / 10;
		length++;
	}

	while (length != 5)
	{
		cout << "Invalid value [10000<=value<=99999]: ";
		cin >> input;

		temp = input;

		length = 0;

		while (input != 0)
		{
			input = input / 10;
			length++;
		}

	}
	m_extension = temp;
}

void NameTag::addExt()
{
	char yesNo;
	cout << "Would you like to enter an extension? (Y)es/(N)o: ";
	cin >> yesNo;

	if (yesNo == 'y')
	{
		extLength();
	}
	else
	{
		m_extension = 1;
	}
	fflush(stdin);

}


NameTag& NameTag::read()
{
	delete[] m_name;
	m_name = nullptr;

	string addName;

	cout << "Please enter the name: ";
	getline(cin, addName);

	setName(addName.c_str());

	addExt();

	cin.ignore();

	return *this;
}

void NameTag::setUnusable()
{
	//delete[] m_name;
	m_name = nullptr;

	m_extension = '\0';

}

bool NameTag::isUnusable(const char* name, int extension)const
{
	bool ok = false;

	int count = 0;

	while (extension != 0)			//Calculates the length of the extension
	{
		extension = extension / 10;
		count++;
	}

	if ((name == nullptr) || (count != 5))
	{
		ok = true;
	}
	return ok;
}

ostream& NameTag::print()const
{

	if (m_name == nullptr || m_extension == '\0')
	{
		cout << "EMPTY NAMETAG!\n";
	}
	else
	{
		int nameLength = strlen(m_name);

		if (nameLength <= 20)
		{
			cout << "************************\n";
			cout << setw(23) << left << "*" << "*\n";
			cout << "* " << setw(21) << left << m_name << right << "*\n";
			cout << setw(23) << left << "*" << right << "*\n";
			cout << "* Extension: ";
			if (m_extension == 1)
			{
				cout << "N/A";
				cout << setw(9) << right << "*\n"; //Maybe setw(9)
				cout << setw(23) << left << "*" << right << "*\n";
				cout << "************************\n";
			}
			else
			{
				cout << m_extension;
				cout << setw(7) << right << "*\n"; //Maybe setw(9)
				cout << setw(23) << left << "*" << right << "*\n";
				cout << "************************\n";
			}
	
		}
		if (nameLength >= 40)
		{
			cout << "********************************************\n";
			cout << setw(43) << left << "*" << "*\n";
			cout << "* " << setw(41) << m_name << right << "*\n";
			cout << setw(43) << left << "*" << right << "*\n";
			cout << "* Extension: ";
			if (m_extension == 1)
			{
				cout << "N/A";
				cout << setw(29) << right << "*\n";
				cout << setw(43) << left << "*" << right << "*\n";
				cout << "********************************************\n";
			}
			else
			{
				cout << m_extension;
				cout << setw(27) << right << "*\n";
				cout << setw(43) << left << "*" << right << "*\n";
				cout << "********************************************\n";
			}
				
		}
	}

	return cout;
}


