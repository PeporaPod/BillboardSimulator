#pragma once
#include <DxLib.h>
#include "ModeSelectorFrame.h"
#include "SimulatorFrame.h"
#include "StringDisplayFrame.h"
#include "StringEditorFrame.h"
class MainFrame
{
	int mode;
	ModeSelectorFrame*	modeselectorframe;
	SimulatorFrame*		simulatorframe;
	StringDisplayFrame*	stringdisplayframe;
	StringEditorFrame*	stringeditorframe;
public:
	MainFrame();
	bool Start();
	~MainFrame();
};

