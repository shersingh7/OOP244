//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       2 (Home)
// Date:           01/10/2020
//==============================================

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds 
{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   bool read(int& aNum);
   bool read(double& balance);

}
#endif // !SDDS_FILE_H_
