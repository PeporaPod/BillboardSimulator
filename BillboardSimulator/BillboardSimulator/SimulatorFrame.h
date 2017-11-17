#pragma once
#include <DxLib.h>
#include "Billboard.h"
class SimulatorFrame
{
private:
	Billboard billboard;
public:
	SimulatorFrame();
	bool Process();
	~SimulatorFrame();
};

