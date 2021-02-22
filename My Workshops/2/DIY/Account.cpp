//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       2 (Home)
// Date:           01/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Account.h"
#include "File.h"

using namespace std;
namespace sdds
{
	int noOfAccounts = 10;
	Account* accounts = nullptr;

	void sort()
	{
		int i, j;
		Account temp;
		for (i = noOfAccounts - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (accounts[j].balance > accounts[j + 1].balance)
				{
					temp = accounts[j];
					accounts[j] = accounts[j + 1];
					accounts[j + 1] = temp;
				}
			}
		}
	}

	bool load(Account& accounts)
	{
		bool ok = false;
		int aNum[10];

		// if reading of account number is successful
		if (read(*aNum))
		{
			//int nlength = 0;
			//nlength = sizeof(*aNum);

			// allocate memory to the size of the aNum + 1
			// and keep its address in the name of the Account Reference

			//accounts.accountNumber = *new int[nlength + 1];

			// copy the account number into the newly allocated memory
			// read account number and balance from the file into the corresponding
			// variables in the Account Reference

			for (int i = 0; i < noOfAccounts; i++)
			{
				accounts.accountNumber = *aNum;
			}

			if(read(accounts.balance))
			{
				ok = true;
			}
			else
			{
				ok = false;
			}
			// make sure the "ok" flag is set to true, if all is good
		}
		return ok;
	}

	bool load(const char *filename)
	{
		bool ok = false;
		int i = 0;
		if (openFile(filename))
		{
			// set the noOfAccounts to the number of records in the file.
			noOfAccounts = noOfRecords();

			// dyanamically allocated an array of accounts into the global
			// Account pointer; "accounts" to the size of the noOfAccounts.
			accounts = new Account[noOfAccounts];

			// in a loop load the account records from the file into 
			// the dynamic array.
			for (i = 0; i < noOfAccounts; i++)
			{
				load(accounts[i]);
			}

			// if th number of the records does not match the number of reads
			// print an error message
			if (!(i = noOfAccounts))
			{
				cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
				ok = false;
			}
			else
			{
				ok = true;
			}

			closeFile();

		}

		else
		{
			cout << "Could not open data file: " << filename << endl;
		}

		return ok;
	}

	void display(Account& accounts)
	{
		cout << accounts.accountNumber << ":  " << accounts.balance << endl;
	}

	void display()
	{
		sort();
		int j = 1;

		cout << "Account#: Balance\n";


		for (int i = 0; i < noOfAccounts; i++)
		{
			cout << j << ": ";
			display(accounts[i]);
			j++;
		}
	}


	void deallocateMemory()
	{
		//delete[] &aNum;
		//delete[] &accounts.accountNumber;
		delete [] accounts;
		accounts = nullptr;
	}



}