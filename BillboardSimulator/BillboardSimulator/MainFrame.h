#pragma once
#include <DxLib.h>
#include "ModeSelectorFrame.h"
#include "SimulatorFrame.h"
#include "StringDisplayFrame.h"
class MainFrame
{
	int mode;
	ModeSelectorFrame* modeselectorframe;
	SimulatorFrame* simulatorframe;
	StringDisplayFrame* stringdisplayframe;
public:
	MainFrame();
	void Start();
	~MainFrame();
};

