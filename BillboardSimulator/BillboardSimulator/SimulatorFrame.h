#pragma once
#include "Billboard.h"
#include "Timetable.h"
#include "StringFile.h"
class SimulatorFrame
{
private:
	Billboard billboard;
	Timetable timetable;
	StringFile stringfile;
public:
	SimulatorFrame();
	void Start();
	~SimulatorFrame();
};

