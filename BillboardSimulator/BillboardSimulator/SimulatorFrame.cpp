#include "SimulatorFrame.h"



SimulatorFrame::SimulatorFrame()
{
}

bool SimulatorFrame::Start()
{
	printfDx("Initializing Billboard\n"); ScreenFlip();
	billboard.Init();
	billboard.Start();

	return true;
}


SimulatorFrame::~SimulatorFrame()
{
}
