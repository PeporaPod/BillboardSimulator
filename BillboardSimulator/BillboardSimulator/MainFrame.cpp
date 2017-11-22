#include "MainFrame.h"



MainFrame::MainFrame()
{
	ChangeWindowMode(TRUE);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
	ChangeFont("Yu Gothic");
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
		case 1:
			simulatorframe = new SimulatorFrame;
			simulatorframe->Start();
			delete simulatorframe;
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
