#pragma once
//==============================================
// Name:           Davinder Verma
// Student Number: 121802201
// Email:          dverma22@myseneca.ca
// Section:        NCC
// Workshop:       1 (DIY)
// Date:           22/09/2020
//==============================================

#pragma once
#ifndef sdds_FILE_H
#define sdds_FILE_H

namespace sdds
{
	bool openFile(const char filename[]);
	void closeFile();
	bool readCode(char code[]);
	bool readExt(int* ext);
	
}


#endif
