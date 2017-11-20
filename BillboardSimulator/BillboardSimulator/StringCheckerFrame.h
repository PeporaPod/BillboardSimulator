#pragma once
#include "Billboard.h"
#include "TimeTable.h"
#include "StringList.h"
class StringCheckerFrame
{
private:
	Billboard billboard;
	TimeTable timetable;
	StringList stringlist;
public:
	StringCheckerFrame();
	bool Start();
	~StringCheckerFrame();
};

