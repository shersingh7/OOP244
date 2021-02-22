//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       3 (Lab)
// Date:           06/10/2020
//==============================================


#define SDDS_SUBJECT_H_
#ifndef SDDS_SUBJECT_H_

namespace sdds
{
    class Subject
    {
        char m_code[7]; // holds the subject code (exactly 6 characters)
        int m_mark;
        char grade() const;

    public:
        void setEmpty();
        void set(const char* code, int mark);
        float scale4() const;
        bool isValid() const;
        void display() const;
    };
}


#endif
