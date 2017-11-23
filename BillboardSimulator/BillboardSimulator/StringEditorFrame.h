#pragma once
#include <DxLib.h>
#include "Billboard.h"
#include "Timetable.h"
#include "StringFile.h"
#include "EditorControler.h"
class StringEditorFrame
{
private:
	Billboard	billboard;
	Timetable	timetable;
	StringFile	stringfile;
	EditorControler editorcontroler;
public:
	StringEditorFrame();
	void Start();
	~StringEditorFrame();
};

