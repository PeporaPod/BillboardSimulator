#pragma once
#include <DxLib.h>
#include "Header.h"
#include "Billboard.h"
#include "Timetable.h"
#include "StringFile.h"
class StringEditorFrame
{
private:
	Billboard billboard;
	StringInformation stringinformation;
public:
	StringEditorFrame();
	void Start();
	~StringEditorFrame();
private:
	void WriteOut();
};

