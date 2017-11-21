#include "StringDisplayFrame.h"



StringDisplayFrame::StringDisplayFrame()
{
	SetGraphMode(920, 480, 32);
	SetDrawScreen(DX_SCREEN_BACK);
}

void StringDisplayFrame::Start()
{
	billboard = new Billboard;
	billboard->Init(2 / 3, 1, 0, 1, LED_ROW, LED_COLUMN);
	billboard->Draw();
	WaitKey();
}


StringDisplayFrame::~StringDisplayFrame()
{
	delete billboard;
}
