#pragma once
#include "Header.h"
#include <fstream>
#include <list>
class StringFile
{
private:
	std::list<StringInformation>	stringlist;
	std::vector<StringInformation>	numberstring;
	std::vector<StringInformation>	symbolstring;
	std::vector<StringInformation>	stringvector;
public:
	StringFile();
	void Init();
	~StringFile();
private:
	bool LoadBinaryString(int filenumber);
};

