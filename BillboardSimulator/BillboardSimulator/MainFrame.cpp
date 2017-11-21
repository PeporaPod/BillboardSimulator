#include "MainFrame.h"



MainFrame::MainFrame()
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
}

void MainFrame::Start()
{
	do {
		mode = -1;
		modeselectorframe = new ModeSelectorFrame;
		mode = modeselectorframe->Start();
		delete modeselectorframe;

		switch (mode) {
		case 0:
			break;
		case 2:
			stringdisplayframe = new StringDisplayFrame;
			stringdisplayframe->Start();
			delete stringdisplayframe;
			break;
		default:
			return;
		}
	} while (mode);
}


MainFrame::~MainFrame()
{
	DxLib_End();
}
