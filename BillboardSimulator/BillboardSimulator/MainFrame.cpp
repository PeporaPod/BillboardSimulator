#include "MainFrame.h"



MainFrame::MainFrame()
{
	ChangeWindowMode(TRUE);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
	ChangeFont("Yu Gothic");
	DxLib_Init();
}

bool MainFrame::Start()
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
		case 3:
			stringeditorframe = new StringEditorFrame;
			stringeditorframe->Start();
			delete stringeditorframe;
			break;
		default:
			return false;
		}
	} while (mode);
	return true;
}


MainFrame::~MainFrame()
{
	DxLib_End();
}
