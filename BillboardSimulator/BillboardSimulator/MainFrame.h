#pragma once
#include "SimulatorFrame.h"
class MainFrame
{
private:
	int mode;
	SimulatorFrame simulatorframe;
public:
	MainFrame();
	int Process();
	~MainFrame();
};

