//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       4 (Lab)
// Date:           10/10/2020
//==============================================


#ifndef SDDS_BOX_H_
#define SDDS_BOX_H_

namespace sdds
{
    class Box
    {
        char* m_contentName;    // the content name pointer:
                                // this pointer holds the name of the material to be kept in the box
                                // dynamically
        int m_width;            // The dimensions of the box in Inches
        int m_height;
        int m_length;
        int m_contentVolume;    // the content volume:
                                // This variable holds the volume of the material currently in 
                                // the box in Cubic Inches


        void setName(const char* Cstr);

        void setUnusable();

        bool isUnusable()const;

        bool hasContent()const;

    public:
        Box()
        {
            m_width = 12;
            m_height = 12;
            m_length = 12;
            m_contentName = nullptr;
            m_contentVolume = 0;

        }

        Box(int sideLength, const char* contentName = nullptr)
        {
            m_contentName = nullptr;

            if (sideLength < 5 || sideLength > 36)
            {
                setUnusable();
            }
            else
            {
                m_width = sideLength;
                m_height = sideLength;
                m_length = sideLength;
                m_contentVolume = 0;
                setName(contentName);
            }
        }

        Box(int width, int height, int length, const char* contentName = nullptr)
        {
            m_contentName = nullptr;

            if ((length < 5 || length > 36) || (width < 5 || width > 36) || (height < 5 || height > 36))
            {
                setUnusable();
            }
            else
            {
                m_width = width;
                m_height = height;
                m_length = length;
                m_contentVolume = 0;
                setName(contentName);
            }

        }

        ~Box()
        {
           delete[] m_contentName;
           m_contentName = nullptr;
        }

    //public:

        int capacity()const;

        int quantity()const;

        Box& setContent(const char* contentName);

        std::ostream& display()const;

        Box& add(int quantity);

        Box& add(Box& B);


    };



}


#endif