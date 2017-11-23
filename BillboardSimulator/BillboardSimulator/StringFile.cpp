#include "StringFile.h"



StringFile::StringFile()
{
}

void StringFile::Init()
{
	for (int i = 1; LoadBinaryString(i); i++) count++;
	singularity();
}

void StringFile::GetStringInformation(StringInformation& stringinformation, int number)
{
	if ((unsigned int)number < stringvector.size())
		stringinformation = stringvector[number];
}


StringFile::~StringFile()
{
}

void StringFile::singularity()
{
	std::ifstream file;
	file.open("0.seg");
	if (file.is_open()) {
		StringInformation strinfo;
		for (int row = 0; row < LED_ROW; row++) {
			std::string str;
			std::getline(file, str);
			unsigned long long led_array = 0;
			unsigned long long operatorbit = 0x8000000000000000;
			for (int column = 0; (unsigned int)column < str.size() && column < LED_COLUMN; row++) {
				if (str[column] = '1')
					led_array = led_array & operatorbit;
				operatorbit = operatorbit >> 1;
			}
			strinfo.led_status[row] = led_array;
		}
		stringvector.push_back(strinfo);
		file.close();
	}
	file.open("0", std::fstream::binary);
	if (file.is_open()) {
		StringInformation strinfo;
		file.read(strinfo.string, sizeof(StringInformation::string));
		file.read((char*)&strinfo.width, sizeof(StringInformation::width));
		file.read(&strinfo.type, sizeof(StringInformation::type));
		file.read((char*)&strinfo.R, sizeof(StringInformation::R));
		file.read((char*)&strinfo.G, sizeof(StringInformation::G));
		file.read((char*)&strinfo.B, sizeof(StringInformation::B));
		for (int row = 0; row < LED_ROW; row++)
			file.read((char*)&strinfo.led_status[row], sizeof(unsigned long long));
		stringvector.push_back(strinfo);
		file.close();
	}
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
	stringvector.push_back(strinfo);
	return true;
}

