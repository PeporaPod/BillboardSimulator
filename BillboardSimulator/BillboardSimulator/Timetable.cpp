#include "Timetable.h"



Timetable::Timetable()
{
}

void Timetable::Init(bool stringmode)
{
	if (stringmode)
		InitAsString();
	else
		InitAsID();
}


Timetable::~Timetable()
{
}

void Timetable::InitAsID()
{
}

void Timetable::InitAsString()
{
	LoadCSV(true);
}

void Timetable::LoadCSV(bool stringmode)
{
	std::ifstream file("TT\\êVèhâw.csv");
	if (!file.is_open()) return;

	if (stringmode) {
		std::list<std::string> stringlist;
		StringProjection(&file, stringlist);
	}
}

void Timetable::StringProjection(std::ifstream* file, std::list<std::string> stringlist)
{
	while (!file->eof()) {
		std::string str;
		std::getline(*file, str);
		std::istringstream strstream(str);
		while (!strstream.eof()) {
			str.clear();
			std::getline(strstream, str, ',');
			if (!STOICheck(str) && !str.empty()) stringlist.push_back(str);
		}
	}

	std::list<std::string>::iterator iterator[2] = { stringlist.begin(), stringlist.begin() };
	while (iterator[0] != stringlist.end()) {
		while (iterator[1] != stringlist.end()) {
			if (iterator[0] != iterator[1] && *iterator[0] == *iterator[1])
				iterator[1] = stringlist.erase(iterator[1]);
			else
				iterator[1]++;
		}
		if (iterator[0] != iterator[1]) iterator[0]++;
		iterator[1] = iterator[0];
	}
}

bool Timetable::STOICheck(std::string string)
{
	if (string.empty()) return false;
	for (unsigned int i = 0; i < string.size(); i++)
		if (string[i] < '0' || '9' < string[i])
			return false;
	return true;
}
