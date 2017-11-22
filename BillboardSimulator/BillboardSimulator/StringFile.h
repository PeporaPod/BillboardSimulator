#pragma once
#include "Header.h"
#include <fstream>
class StringFile
{
private:
	std::vector<StringInformation> numberstring;
	std::vector<StringInformation> symbolstring;
	std::vector<StringInformation> stringvector;
public:
	StringFile();
	void Init();
	~StringFile();
private:
	bool LoadBinaryString(int filenumber);
};

