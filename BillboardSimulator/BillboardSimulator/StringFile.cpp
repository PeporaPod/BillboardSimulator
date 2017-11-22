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


	StringInformation strinfo;
	file.read(strinfo.string, sizeof(StringInformation::string));
	file.read((char*)&strinfo.width, sizeof(StringInformation::width));
	file.read(&strinfo.type, sizeof(StringInformation::type));
	file.read((char*)&strinfo.R, sizeof(StringInformation::R));
	file.read((char*)&strinfo.G, sizeof(StringInformation::G));
	file.read((char*)&strinfo.B, sizeof(StringInformation::B));
	for (int row = 0; row < LED_ROW; row++)
		file.read((char*)&strinfo.led_status[row], sizeof(unsigned long long));
	stringlist.push_back(strinfo);
	return true;
}
