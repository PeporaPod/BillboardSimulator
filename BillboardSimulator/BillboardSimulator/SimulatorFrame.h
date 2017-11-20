#pragma once
#include "Billboard.h"
#include "TimeTable.h"
#include "StringList.h"
class SimulatorFrame
{
private:
	Billboard billboard;
	TimeTable timetable;
	StringList stringlist;
public:
	SimulatorFrame();
	bool Start();
	~SimulatorFrame();
};