#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds 
{
    void Numbers::save()
    {
        if (m_numbers != nullptr)
        {
            ofstream f;
            f.open(m_filename);
            for (int i = 0; i < m_numCount; i++)
            {
                f << m_numbers << endl;
            }
            f.close();
        }
    }
    Numbers& Numbers::operator+=(const double number)
    {
        if (m_numbers != nullptr || m_numCount < 0)
        {
            double* temp = nullptr;
            temp = new double[m_numCount + 1];

            for (int i = 0; i < m_numCount; i++)
            {
                temp[i] = m_numbers[i];
                //memcpy(temp, m_numbers, m_numCount);
                //*temp = *m_numbers;
                //*temp++ = *m_numbers++;
            }
            // copy the m_numbers to temp and delete the temp array
            //temp = m_numbers;

            delete[] m_numbers;
            m_numbers = nullptr;
            m_numbers = temp;
            temp = nullptr;
            sort();
        }
        return *this;
    }
    std::ostream& Numbers::display(std::ostream& ostr) const
    {
        //if (m_numbers != nullptr)
        if (m_numCount > 0)
        {
            ostr << "=========================" << endl;
            if (m_isOriginal == true)
            {
                ostr << m_filename << endl;
            }
            else
            {
                ostr << "*** COPY ***" << endl;
            }
            for (int i = 0; i < m_numCount; i++)
            {
                ostr << m_numbers[i];// << ",";
                if (i + 1 < m_numCount)ostr << ",";
                
                
                
            }
            ostr << endl << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number: " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average :" << average() << endl;
            ostr << "=========================";
        }
        else
        {
            ostr << "Empty List" << endl;
        }
        return ostr;
    }
    Numbers::Numbers() {
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }

   std::ostream& operator<<(std::ostream& os, const Numbers& N)
   {
       N.display(os);
       return os;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   int Numbers::numberCount()const
   {
       int num = 0;
       char a; //= 0.0;
       ifstream f;
       f.open(m_filename);
       while (f)//!f.eof())                 //while the end of file is NOT reached
       {
           f >> a;
            if (a == '\n')
            {
                num++;
            }
       }
       f.close();
       return num-1;
   }

   //bool Numbers::load()
   //{
   //    bool ok = false;
   //    int temp = 0;
   //    if (m_numCount > 0)
   //    {
   //        m_numbers = new double[m_numCount + 1];

   //        ifstream f;
   //        f.open(m_filename);

   //        if (f.is_open())                     //if the file is open
   //        {
   //            while (!f.eof())                 //while the end of file is NOT reached
   //            {
   //                f >> m_numbers[temp];
   //                temp++;
   //            }
   //            f.close();                         //closing the file
   //        }
   //    }


   //    if (temp == m_numCount)
   //    {
   //        ok = true;
   //    }
   //    return ok;
   //}

   bool Numbers::load()
   {
       bool ok = false;
       int temp = 0;
       if (m_numCount > 0)
       {
           m_numbers = nullptr;
           m_numbers = new double[m_numCount + 1];

           ifstream f;
           f.open(m_filename);

           if (f.is_open())                     //if the file is open
           {
               while (f)//(!f.eof())                 //while the end of file is NOT reached
               {
                
                   for (int i = 0; i < m_numCount; i++)
                   {
                       f >> m_numbers[i];
                       temp++;
                   }
                   //f >> m_numbers[temp];
                   //temp++;
               }
               f.close();                         //closing the file
           }

       }

       if (temp == m_numCount)
       {
           ok = true;
       }
       return ok;
   }
   

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }

   std::istream& operator>>(std::istream& istr, Numbers& N)
   {
       double temp =0.0;
       //ifstream f;
       //f.open(m_filename);

       istr >> temp;

      /* if (f)
       {
           f >> temp;
       }*/

       N += temp;
       return istr;
   }

   Numbers::Numbers(const Numbers& source)
   {
       m_numbers = nullptr;
       m_filename = nullptr;

       *this = source;
   }

   Numbers& Numbers::operator=(const Numbers& numbers)
   {
       if (this != &numbers)//numbers.m_numbers != nullptr)
       {
           if (m_numbers != nullptr)
           {
               delete[] m_numbers;
               m_numbers = nullptr;
           }
           m_numbers = new double[numbers.m_numCount +1];
           for (int i = 0; i < numbers.m_numCount; i++)
           {
               m_numbers[i] = numbers.m_numbers[i];
           }
           m_numCount = numbers.m_numCount;
       }
       else
       {
           m_numbers = nullptr;
           m_filename = nullptr;
           m_numCount = -1;
       }

       return *this;
       //// data members of the current object (LHS): name, idnum, salary

       //if (&numbers != n)        // 1. check for self-assignment: x=x;
       //{
       //    //cout << "\t =: release memory for [" << name << "]" << endl;
       
       //    if (m_numbers != nullptr)
       //        delete[] m_numbers;    // 2. release current memory storage

       //      //cout << "\t =: allocate new memory storage\n";
       //    int length = strlen(m_numbers);
       //    // 3. request memory storage and copy the data
       //    m_numbers = new (nothrow) double[rhs.m_numbers];

       //    /* init( strlen( rhs.name ), rhs.name ); */

       //  // 4. copy the data from rhs to the current object
       //    if (m_numbers != nullptr) 
       //    {
       //        m_numbers = rhs.m_numbers;
       //    }
       }
      // return *this;  // the current object!
   }

//}
