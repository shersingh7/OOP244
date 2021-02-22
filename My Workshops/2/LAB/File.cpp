//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       2 (Lab)
// Date:           01/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
   FILE* fptr;
   bool openFile(const char filename[]) 
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords() 
   {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) 
      {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile() 
   {
      if (fptr) fclose(fptr);
   }
     
// TODO: read functions go here   

   bool read(char* name) 
   {
       return fscanf(fptr, "%[^,],", name) == 1;
   }

   bool read(int& sNum) 
   {
       return fscanf(fptr, "%d,", &sNum) == 1;
   }

   bool read(double& gpa)
   {
       return fscanf(fptr, "%lf\n", &gpa) == 1;
   }
}