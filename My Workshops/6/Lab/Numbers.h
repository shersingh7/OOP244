//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       6 (Lab)
// Date:           4/10/2020
//==============================================

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
    class Numbers {
        double* m_numbers = nullptr;
        char* m_filename = nullptr;
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void setFilename(const char* filename);
        void sort();
        int numberCount();
        bool load();
        void save();


    public:
        Numbers();
        Numbers(const char* filename);
        Numbers(const Numbers&);            //Copy constructor
        double average()const;
        double max()const;
        double min()const;
        ~Numbers();
        std::ostream& display(std::ostream& ostr) const;


        Numbers& operator=(const Numbers& source);     //Copy assignment operator
        Numbers& operator+=(const double number);   
    };
        std::ostream& operator<< (std::ostream& os, const Numbers& N);
        std::istream& operator>> (std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_