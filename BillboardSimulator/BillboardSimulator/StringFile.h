#pragma once
#include "Header.h"
#include <fstream>
#include <list>
#include <string>
class StringFile
{
private:
	int count = 0;
	std::list<StringInformation>	stringlist;
	std::vector<StringInformation>	numberstring;
	std::vector<StringInformation>	symbolstring;
	std::vector<StringInformation>	stringvector;
public:
	StringFile();
	void Init();
	~StringFile();
private:
	void singularity();
	bool LoadBinaryString(int filenumber);
	void Assort();
};

