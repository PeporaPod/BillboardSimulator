#pragma once
#include <DxLib.h>
#include "Billboard.h"
#include "Timetable.h"
#include "StringFile.h"
class StringDisplayFrame
{
private:
	Billboard	billboard;
	Timetable	timetable;
	StringFile	stringfile;
public:
	StringDisplayFrame();
	void Start();
	~StringDisplayFrame();
};

