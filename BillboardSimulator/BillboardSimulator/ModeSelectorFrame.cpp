#include "ModeSelectorFrame.h"



ModeSelectorFrame::ModeSelectorFrame()
{
	SetAlwaysRunFlag(FALSE);
	SetGraphMode(SCREENWIDTH_MAIN, SCREENHEIGHT_MAIN, COLORBITDEPTH);
	SetDrawScreen(DX_SCREEN_FRONT);
	SetFontSize(SCREENHEIGHT_MAIN / 12);
}

int ModeSelectorFrame::Start()
{
	DrawString(0, 0, "\nSelect Mode\n 0: End\n 1: Simulator\n 2: String Display", GetColor(200, 200, 200));
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
		else if (CheckHitKey(KEY_INPUT_4))
			return 4;
		else if (CheckHitKey(KEY_INPUT_5))
			return 5;
		else if (CheckHitKey(KEY_INPUT_6))
			return 6;
		else if (CheckHitKey(KEY_INPUT_7))
			return 7;
		else if (CheckHitKey(KEY_INPUT_8))
			return 8;
		else if (CheckHitKey(KEY_INPUT_9))
			return 9;
	} while (!ProcessMessage());
	return -1;
}


ModeSelectorFrame::~ModeSelectorFrame()
{
}
