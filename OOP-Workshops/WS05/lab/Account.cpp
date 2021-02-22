#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
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
         // I (Fardad) removed the "return cout", this was a mistake
         // (copied and pasted by mistake)
         // and had no effect to the execution of the program.
         // As mentioned before we should have only
         // one return statement in a function.
      }
      else {
         cout << "Invalid Account";
      }
      return cout;
    }
   


}