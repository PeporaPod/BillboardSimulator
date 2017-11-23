#pragma once
#include "Header.h"
#include <fstream>
#include <string>
class StringFile
{
private:
	int count = 0;
	std::vector<StringInformation>	stringvector;
public:
	StringFile();
	void Init();
	void GetStringInformation(StringInformation& stringinformation, int offset);
	~StringFile();
private:
	void singularity();
	bool LoadBinaryString(int filenumber);
};

