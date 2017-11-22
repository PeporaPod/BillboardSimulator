#include "ModeSelectorFrame.h"



ModeSelectorFrame::ModeSelectorFrame()
{
	SetAlwaysRunFlag(FALSE);
	SetGraphMode(SCREENWIDTH_MAIN, SCREENHEIGHT_MAIN, COLORBITDEPTH);
	SetDrawScreen(DX_SCREEN_FRONT);
	SetFontSize(SCREENHEIGHT_MAIN / 14);
}

int ModeSelectorFrame::Start()
{
	DrawString(0, 0, "\nSelect Mode\n 0: End\n 1: Simulator\n 2: String Display\n 3: String Editor", GetColor(200, 200, 200));
	do {
		WaitKey();
		if (CheckHitKey(KEY_INPUT_0))
			return 0;
		else if (CheckHitKey(KEY_INPUT_1))
			return 1;
		else if (CheckHitKey(KEY_INPUT_2))
			return 2;
		else if (CheckHitKey(KEY_INPUT_3))
			return 3;
	} while (!ProcessMessage());
	return -1;
}


ModeSelectorFrame::~ModeSelectorFrame()
{
}
