#pragma once
#include <DxLib.h>
#include "Billboard.h"
#include "Timetable.h"
#include "StringFile.h"
class StringDisplayFrame
{
private:
	int string_id;
	Billboard	billboard;
	Timetable	timetable;
	StringFile	stringfile;
	StringInformation stringinformation;
public:
	StringDisplayFrame();
	void Start();
	~StringDisplayFrame();
private:
	void MainLoop();
};

