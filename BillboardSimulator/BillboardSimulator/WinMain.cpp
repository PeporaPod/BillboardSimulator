#include <DxLib.h>
#include "MainFrame.h"


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();

	MainFrame mainframe;
	mainframe.Process();

	DxLib_End();
	return 0;
}