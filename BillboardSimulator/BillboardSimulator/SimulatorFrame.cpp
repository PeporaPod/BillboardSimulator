#include "SimulatorFrame.h"



SimulatorFrame::SimulatorFrame()
{
}

bool SimulatorFrame::Process()
{
	while (!ProcessMessage())
		billboard.Process();
	return false;
}


SimulatorFrame::~SimulatorFrame()
{
}
