#pragma once
#include "Billboard.h"
#include "TimeTable.h"
#include "StringList.h"
class MainFrame
{
private:
	Billboard billboard;
	TimeTable timetable;
	StringList stringlist;
public:
	MainFrame();
	bool Start();
	~MainFrame();
};