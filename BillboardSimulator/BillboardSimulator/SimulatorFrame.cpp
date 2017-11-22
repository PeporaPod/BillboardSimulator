#include "SimulatorFrame.h"



SimulatorFrame::SimulatorFrame()
{
	SetAlwaysRunFlag(TRUE);
	SetGraphMode(SCREENWIDTH_SIMULATOR, SCREENHEIGHT_SIMULATOR, COLORBITDEPTH);
}

void SimulatorFrame::Start()
{
	billboard.Init();
	billboard.Draw();
	WaitKey();
}


SimulatorFrame::~SimulatorFrame()
{
}
