#pragma once
#include "Header.h"
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
class Timetable
{
private:
	std::vector<TrainInformation> timetable;
	std::vector<TrainInformationAsString> timetableasstring;
public:
	Timetable();
	void Init(bool stringmode);
	~Timetable();
private:
	void InitAsID();
	void InitAsString();
	void LoadCSV(bool stringmode);
	void StringProjection(std::ifstream* file, std::list<std::string> stringlist);
	bool STOICheck(std::string string);
};

