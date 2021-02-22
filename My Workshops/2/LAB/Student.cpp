//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       2 (Lab)
// Date:           01/10/2020
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Student.h"
#include "File.h"

using namespace std;

namespace sdds 
{
    int noOfStudents = 14;
    Student* students = nullptr;

    void sort() 
    {
        int i, j;
        Student temp;
        for (i = noOfStudents - 1; i > 0; i--) 
        {
            for (j = 0; j < i; j++) 
            {
                if (students[j].m_gpa > students[j + 1].m_gpa) 
                {
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

    bool load(Student& students) 
    {
        bool ok = false;
        char name[128];

        // if reading of name is successful
        if (read(name)) 
        {
             int nlength = 0;
             nlength = strlen(name);

            // allocate memory to the size of the name + 1
            // and keep its address in the name of the Student Reference
             students.m_name = new char[nlength + 1];

            // copy the name into the newly allocated memory
            // read student number and gpa from the file into the corresponding
            // variables in the Student Referenct
             if (strcpy(students.m_name, name) && read(students.m_studentNumber) && read(students.m_gpa))
             {
                 ok = true;
             }
             else
             {
                 ok = false;
             }
            // make sure the "ok" flag is set to true, if all is good
        }
        return ok;
    }

    // TODO: Finish the implementation of the 0 arg load function 
    bool load() 
    {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) 
        {
            // set the noOfStudents to the number of records in the file.
            noOfStudents = noOfRecords();

            // dyanamically allocated an array of students into the global
            // Student pointer; "students" to the size of the noOfStudents.
            students = new Student[noOfStudents];

            // in a loop load the student records from the file into 
            // the dynamic array.
            for (i = 0; i < noOfStudents; i++)
            {
                load(students[i]);
            }

            // if th number of the records does not match the number of reads
            // print an error message
            if (!(i = noOfStudents)) 
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
                ok = false;
            }
            else 
            {
                ok = true;
            }

            closeFile();

        }

        else 
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }

        return ok;
    }

    // TODO: Implementation for the display functions go here
    void display(Student& students)
    {
        cout << students.m_name << ", " << students.m_studentNumber << ": " << students.m_gpa << endl;
    }

    void display()
    {
        int j = 1;
        sort();

        for (int i = 0; i < noOfStudents; i++)
        {
            cout << j << ": ";
            display(students[i]);
            j++;
        }

    }

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory()
    {
        for (int i = 0; i < noOfStudents; i++)
        {
            delete[] students[i].m_name;
            students[i].m_name = nullptr;
        }

        delete[]students;
        students = nullptr;
    }
}

