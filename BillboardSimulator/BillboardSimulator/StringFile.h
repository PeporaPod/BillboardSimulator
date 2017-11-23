#pragma once
#include "Header.h"
#include <fstream>
#include <iostream>
#include <string>
class StringFile
{
private:
	int count = 0;
	std::vector<StringInformation>	stringvector;
public:
	StringFile();
	void Init();
	bool GetStringInformation(StringInformation& stringinformation, int number);
	~StringFile();
private:
	void singularity();
	bool LoadBinaryString(int filenumber);
};

