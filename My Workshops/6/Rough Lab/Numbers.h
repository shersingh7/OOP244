#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds 
{
   class Numbers 
   {
      double* m_numbers = nullptr;
      char* m_filename = nullptr;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void sort();
      void setFilename(const char* filename);
      int numberCount()const;
      bool load();
      void save();
      

   public:
      Numbers();
      Numbers(const char* filename);
      double average()const;
      double max()const;
      double min()const;
      ~Numbers();


      Numbers& operator+=(const double number);

   

      std::ostream& display(std::ostream& ostr) const;


      Numbers(const Numbers& numbers);

      Numbers& operator=(const Numbers& );

      
   };
    
   std::ostream& operator<<(std::ostream& os, const Numbers& N);

   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

