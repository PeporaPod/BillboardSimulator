#pragma once
#include "ModeChangerFrame.h"
#include "SimulatorFrame.h"
#include "StringCheckerFrame.h"
class MainFrame
{
private:
	char mode;
	ModeChangerFrame* modechangerframe;
	SimulatorFrame* simulatorframe;
	StringCheckerFrame* stringcheckerframe;
public:
	MainFrame();
	bool Start();
	~MainFrame();
};