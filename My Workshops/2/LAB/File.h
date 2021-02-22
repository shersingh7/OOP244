//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       2 (Lab)
// Date:           01/10/2020
//==============================================
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds 
{
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();

	// TODO: Declare read prototypes

	bool read(char* name);
	bool read(int& sNum);
	bool read(double& gpa);

}

#endif // !SDDS_FILE_H_
