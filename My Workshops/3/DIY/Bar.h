//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       3 (DIY)
// Date:           08/10/2020
//==============================================

#ifndef SDDS_BAR_H_
#define SDDS_BAR_H_

namespace sdds
{
    class Bar
    {
        char m_title[21];    //holds the title
        char m_fillValue;    //holds the fill character
        int m_sampleValue;   //holds the sample value of the bar


    public:
        //Suggested public member functions
        void setEmpty();
        void set(const char* title, char fillchar, int sampleValue);
        bool isValid()const;


        //Mandatory public member function 
        void draw()const;
    };
}




#endif // !SDDS_BAR_H_