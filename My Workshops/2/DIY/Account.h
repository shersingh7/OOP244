//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       2 (Home)
// Date:           01/10/2020
//==============================================

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_

//#define DATAFILE "accounts.csv"

namespace sdds 
{
    struct Account
    {
        int accountNumber;
        double balance;
    };

    //sorts the dynamic array of Array based on the balance of the students.
    void sort();

    // loads a account structue with its values from the file
    bool load(Account& accounts);

    // allocates the dyanmic array of accounts and loads all the file
    // records into the array
    bool load(const char *filename);

    // displays a account record on the screen:
    void display();

    // first sorts the accounts then displays all the accounts on the screen
    void display(Account& accounts);

    // It will deallocate the account array 
	void deallocateMemory();
}
#endif // SDDS_ACCOUNT_H_