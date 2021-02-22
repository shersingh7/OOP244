//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       5 (Lab)
// Date:           21/10/2020
//==============================================

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds 
{
   class Account 
   {
       int m_number;
       double m_balance;
       void setEmpty();
       int checkLength(int accountNumber)const;

   public:
       Account();
       Account(int number, double balance);
       std::ostream& display()const;

       //To be implemented functions
       operator bool() const;   //Checkes if the the account is valid

       operator int() const;    //Returns the account number
       
       operator double() const; //Returns the balance value
       
       bool operator ~() const; //Checks if the account is new or not
       
       Account& operator=(const int num);    //Sets the account number to integer
       
       Account& operator=(Account& account);    //Sets the account to another Account object
       
       Account& operator+=(double bal);     //Adds the double value to the account balance
       
       Account& operator-=(double bal);     //Reduces the double value from the account balance
       
       friend double operator+(const Account&, const Account&); //Returns the sum of the double values
       
       friend double operator+=(double&, const Account&);       //Accepts a double reference at left and a constant account reference at right and returns a double value.

   };

}
#endif // SDDS_ACCOUNT_H_