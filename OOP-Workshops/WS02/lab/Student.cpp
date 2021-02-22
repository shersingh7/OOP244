#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"
#include "File.h"
using namespace std;
namespace sdds {
   int noOfStudents;
   Student* students;


   void sort() {
      int i, j;
      Student temp;
      for (i = noOfStudents - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (students[j].m_gpa > students[j + 1].m_gpa) {
               temp = students[j];
               students[j] = students[j + 1];
               students[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one student record from the file and loads it into the student reference
   // argument
   bool load(...............) {
      bool ok = false;
      char name[128];
      // if reading of name is successful
      if (read(name)) {
         // allocate memory to the size of the name + 1
         // and keep its address in the name of the Student Reference

         // copy the name into the newly allocated memroy


         // read student number and gpa from the file into the corresponding
         // variables in the Student Referenct


         // make sure the "ok" flag is set to true, if all is good
      }
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
         // set the noOfStudents to the number of recoreds in the file.

         // dyanamically allocated an array of students into the global
         // Student pointer; "students" to the size of the noOfStudents.

         // in a loop load the student records from the file into 
         // the dynamic array.

         // if th number of the records does not match the number of reads
         // print an error message
         if (.............................){
            cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl
         }
         else {
            ok = true;
         }
         closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here


   // TODO: Implementation for the deallocateMemory function goes here



}