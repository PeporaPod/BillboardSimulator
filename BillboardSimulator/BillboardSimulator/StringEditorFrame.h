#pragma once
#include <DxLib.h>
#include "Billboard.h"
#include "Timetable.h"
#include "StringFile.h"
class StringEditorFrame
{
private:
	Billboard	billboard;
	Timetable	timetable;
	StringFile	stringfile;
public:
	StringEditorFrame();
	void Start();
	~StringEditorFrame();
};

