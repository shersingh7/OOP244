/* Citation and Sources...
Final Project Milestone 5
Module: PreTraige
Filename: PreTraige.cpp
Version 1.0
Author:	Davinder Verma
Revision History
-----------------------------------------------------------
Date      Reason
2020/12/01  Preliminary release
2020/12/04	Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>

#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"

using namespace std;
using namespace sdds;

	PreTriage::PreTriage(const char* dataFilename)
		: m_averCovidWait(15), m_averTriageWait(5), 
		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		int temp = strlen(dataFilename);
		m_dataFilename = new char[temp + 1];

		strcpy(m_dataFilename, dataFilename);

		load();
	}

	PreTriage::~PreTriage() 
	{
		ofstream file(m_dataFilename, ofstream::trunc); //trunc for overwriting the content

		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: "; m_averCovidWait.write(cout) << endl;
		cout << "   Triage: "; m_averTriageWait.write(cout) << endl;

		file << m_averCovidWait << ',' << m_averTriageWait << endl;
		cout << "Saving m_lineup..." << endl;

		for (int i = 0; i < m_lineupSize; i++) 
		{
			cout << i + 1 << "- "; m_lineup[i]->csvWrite(cout) << endl;
			m_lineup[i]->csvWrite(file) << endl;

			delete m_lineup[i];
		}

		delete[] m_dataFilename;
		cout << "done!" << endl;
	}

	const Time PreTriage::getWaitTime(const Patient& p) const 
	{
		int temp = 0;

		for (int i = 0; i < m_lineupSize; i++)
		{
			if (m_lineup[i]->type() == p.type()) 
			{
				temp++;
			}
		}

		if (p.type() == 'T') 
		{
			temp *= (int)m_averTriageWait;
		}
		else 
		{
			temp *= (int)m_averCovidWait;
		}

		return (Time)temp;
	}

	void PreTriage::setAverageWaitTime(const Patient& p) 
	{
		int temp = 0;

		if (p.type() == 'C') 
		{
			temp = ((Time().reset() - (Time)p) + ((int)m_averCovidWait * (p.number() - 1)));
			m_averCovidWait = temp / p.number();
		}
		else
		{
			temp = ((Time().reset() - (Time)p) + ((int)m_averTriageWait * (p.number() - 1)));
			m_averTriageWait = temp / p.number();
		}
	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int temp = -1;
		bool ok = true;

		for (int i = 0; ((i < maxNoOfPatients) && (ok == true)); i++)
		{
			if (m_lineup[i]->type() == type)
			{
				temp = i;
				ok = false;
			}
		}

		return temp;
	}

	void PreTriage::load()
	{
		cout << "Loading data..." << endl;

		ifstream inputFile;
		inputFile.open(m_dataFilename);

		inputFile >> m_averCovidWait;
		inputFile.ignore();

		inputFile >> m_averTriageWait;
		inputFile.ignore(1000, '\n');

		Patient* person{};

		bool ok = true;

		char type = '\0';

		for (int i = 0; ((i < maxNoOfPatients) && (ok == true)); i++) 
		{
			type = '\0';
			inputFile.get(type);
			inputFile.ignore();

			if (type == 'T')
			{
				person = new TriagePatient();
			}
			else if (type == 'C')
			{
				person = new CovidPatient();
			}
			else
			{
				ok = false;
			}

			if (ok == true) 
			{
				person->fileIO(true);
				person->csvRead(inputFile);
				person->fileIO(false);
				m_lineup[m_lineupSize] = person;
				m_lineupSize++;

				if (m_lineupSize >= 100)
				{
					cout << "Warning: number of records exceeded 100" << endl;
					ok = false;
				}

				if (type == 'C') 
				{
					inputFile.ignore(100, '\n');
				}

			}
		}

		if (m_lineupSize == 0)
		{
			cout << "No data or bad data file!" << endl << endl;
		}
		else 
		{
			cout << m_lineupSize << " Records imported..." << endl << endl;
		}

		inputFile.close();
	}

	void PreTriage::reg() 
	{
		int selection = 0;

		if (m_lineupSize >= 100) 
		{ 
			cout << "Line up full!" << endl;
			return;
		}

		m_pMenu >> selection;

		if (selection == 1)
		{
			m_lineup[m_lineupSize] = new CovidPatient();
		}
		else if (selection == 2)
		{
			m_lineup[m_lineupSize] = new TriagePatient();
		}

		m_lineup[m_lineupSize]->setArrivalTime();
		m_lineup[m_lineupSize]->fileIO(false);

		cout << "Please enter patient information: " << endl;
		m_lineup[m_lineupSize]->read(cin);
		cout << endl;

		cout << "******************************************" << endl;

		m_lineup[m_lineupSize]->write(cout);
		cout << "Estimated Wait Time: ";

		getWaitTime(*m_lineup[m_lineupSize]).write(cout);
		cout << endl;

		cout << "******************************************" << endl << endl;

		m_lineupSize++;

		return;
		
	}

	void PreTriage::admit() 
	{
		char temp = '\0';
		int selection = 0;

		m_pMenu >> selection;

		if (selection == 1)
		{
			temp = 'C';
		}
		else if (selection == 2)
		{
			temp = 'T';
		}

		int index = indexOfFirstInLine(temp);

		if (index != -1) 
		{
			cout << "\n******************************************\n";
			m_lineup[index]->fileIO(false);

			cout << "Calling for ";
			m_lineup[index]->write(cout);

			cout << "******************************************\n\n";

			setAverageWaitTime(*m_lineup[index]);
			removePatientFromLineup(index);
		}

	}

	void PreTriage::run(void)
	{
		int selection = 0;
		
		do
		{
			m_appMenu >> selection;

			if (selection == 1)
			{
				reg();
			}

			else if (selection == 2)
			{
				admit();
			}

			
		}while (selection != 0);
	}




