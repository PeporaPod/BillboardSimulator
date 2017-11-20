#include "ModeChangerFrame.h"



ModeChangerFrame::ModeChangerFrame()
{
}

int ModeChangerFrame::Start()
{
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		DrawString(0, 0, "Please Set the Running Mode\n0: End\n1: Simulator\n2: String Checker\n3: String Editor", GetColor(255, 255, 255));
		if (CheckHitKey(KEY_INPUT_0))
			return 0;
		else if (CheckHitKey(KEY_INPUT_1))
			return 1;
		else if (CheckHitKey(KEY_INPUT_2))
			return 2;
	}
	return -1;
}


ModeChangerFrame::~ModeChangerFrame()
{
}
