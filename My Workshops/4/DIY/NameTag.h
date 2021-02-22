//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       4 (DIY)
// Date:           10/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_BOX_H_
#define SDDS_BOX_H_

namespace sdds
{
    class NameTag
    {
        char* m_name;           // the content name pointer: this pointer holds the name of the material to be kept in the NameTag dynamically

        int m_extension = 0;    // This variable holds the extension.

        void setName(const char* Cstr);     //This function sets the name according to their length.

        bool isUnusable(const char* name, int extension)const;     //This function checks if the values in the NameTag are valid or not.
     
        void setUnusable();     //This sets the name pointer and extension value to null.
            
    public:
        NameTag()
        {
            m_name = nullptr;
            m_extension = '\0';
        }

        NameTag(const char* name)
        {
            //m_name = nullptr;
            setName(name);
            m_extension = 1;

        }

        NameTag(const char* name, int extension)
        {
            //m_name = nullptr;

            if (isUnusable(name , extension))
            {
                setUnusable();
            }
            else
            {
              setName(name);
              m_extension = extension;
            }
        }

        ~NameTag()
        {
            if (m_name != nullptr)
            {
                delete[] m_name;
                m_name = nullptr;
            }

        }

        std::ostream& print()const;     //Prints the data in the object

        NameTag& read();                //Reads the input and saves into object

        void addExt();                  //Gets extension input

        void extLength();               //Calculates the extension length
    };
}


#endif