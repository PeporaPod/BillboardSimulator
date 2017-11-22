#include "SimulatorFrame.h"



SimulatorFrame::SimulatorFrame()
{
	SetAlwaysRunFlag(TRUE);
	SetGraphMode(SCREENWIDTH_SIMULATOR, SCREENHEIGHT_SIMULATOR, COLORBITDEPTH);
	SetDrawScreen(DX_SCREEN_BACK);
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
