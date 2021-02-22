//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       5 (Lab)
// Date:           21/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds 
{
   void Account::setEmpty()
   {
      m_number = -1;
      m_balance = 0.0;
   }

   // New account
   Account::Account() 
   {  
      m_number = 0;
      m_balance = 0.0;
   }
   
   Account::Account(int number, double balance) 
   {
      setEmpty();

      if (checkLength(number) == 5 && balance > 0) 
      {
         m_number = number;
         m_balance = balance;
      }
   }

   std::ostream& Account::display() const
   {
      if (*this) 
      {  
         cout << "Acc#: ";
         if (~(*this)) 
            cout << "Not Set";
         else
            cout << " " << m_number << " ";
         cout << ", Balance: ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         //return cout;
      }
      else 
      {
         cout << "Invalid Account";
      }
      return cout;
    }

   int Account::checkLength(int accountNumber)const
   {
       int length = 0;
       int temp = accountNumber;

       while (temp != 0)
       {
           temp = temp / 10;
           length++;
       }
       return length;
   }
   
   Account::operator bool() const
   {
       bool ok = false;

       if ((checkLength(m_number) == 5) || m_number != -1)
       {
           ok = true;
       }
       return ok;
   }

   Account::operator int() const
   {
       return m_number;
   }

   Account::operator double() const
   {
       return m_balance;
   }

   bool Account::operator~() const
   {
       bool ok = false;

       if (m_number == 0)
       {
           ok = true;
       }
       return ok;
   }

   Account& Account::operator=(const int num)
   {
       if (!(*this))
       {
           setEmpty();
       }
       else 
       {
           if (checkLength(num) == 5)
           {
               m_number = num;
           }
           else
           {
               setEmpty();
           }
       }

       return *this;
   }

    Account& Account::operator=(Account& account)
   {
       if (m_balance != -1) 
       {
           if (!(*this))
           {
               setEmpty();
           }
           else 
           {
               m_balance += account.m_balance;
               account.m_balance = 0;
           }
       }
       return *this;
   }

   Account& Account::operator+=(double bal)
   {
       if (*this)
       {
           if (bal > 0)
           {
               m_balance += bal;
           }
       }
       return *this;
   }

   Account& Account::operator-=(double bal)
   {
       if (*this)
       {
           if (bal > 0 && bal <= m_balance)
           {
               m_balance -= bal;
           }
       }
       return *this;
   }

   double operator+(const Account& account1, const Account& account2)
   {
       double sum;

       if (!(account1))
       {
           sum = 0;
       }
       else 
       {
           sum = account1.m_balance + account2.m_balance;
       }

       return sum;
   }

   double operator+=(double& ret, const Account& account)
   {
       double sum;
       sum = account.m_balance;
       
       ret += sum;

       return ret;
   }
}

