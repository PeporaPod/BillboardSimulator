#include "StringFile.h"



StringFile::StringFile()
{
}

void StringFile::Init()
{
	for (int i = 1; LoadBinaryString(i); i++);
}


StringFile::~StringFile()
{
}

bool StringFile::LoadBinaryString(int filenumber)
{
	char filepath[8];
	sprintf_s<sizeof(filepath)>(filepath, "STR\\%03d", filenumber);
	std::ifstream file(filepath, std::fstream::binary);
	if (!file.is_open()) return false;


	return true;
}
