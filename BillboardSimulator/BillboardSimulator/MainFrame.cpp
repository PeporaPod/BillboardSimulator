#include "MainFrame.h"



MainFrame::MainFrame()
{
	SetAlwaysRunFlag(TRUE);
	ChangeWindowMode(TRUE);
	SetGraphMode(SCREENWIDTH, SCREENHEIGHT, 32);
	SetDrawScreen(DX_SCREEN_BACK);
}

bool MainFrame::Start()
{
	if (DxLib_Init() == -1) return false;
	return billboard.Init();
}

bool MainFrame::Process()
{
	return false;
}


MainFrame::~MainFrame()
{
}
