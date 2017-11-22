#include <DxLib.h>
#include "MainFrame.h"


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MainFrame mainframe;
	if (mainframe.Start()) return 0;
	return -1;
}