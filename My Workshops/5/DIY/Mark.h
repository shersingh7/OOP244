//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       5 (DIY)
// Date:           21/10/2020
//==============================================

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds
{
    class Mark
    {
        int m_marks = NULL;    //Holds the marks
        char m_grade = NULL;   //Holds the grade
        double m_gpa = NULL;   //Holds the GPA
        void setEmpty();       //Sets marks, grades and gpa to impossible values 
        bool isEmpty();        //checks if the marks is empty or not.
        void setGrade();       //Sets the grades according to the input values
        bool isValid(const int);    //checks if the input marks are valid or not.

    public:

        //TO DO

        operator bool() const;

        operator int() const;

        operator double() const;

        operator char() const;

        Mark();  //Default constructor
        
        Mark& operator+=(int number);
        
        Mark(int number);
        
        Mark& operator=(const int);
        
        friend int operator+=(int&, Mark&);
    };





}
#endif // SDDS_ACCOUNT_H_