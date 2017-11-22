#include "StringDisplayFrame.h"



StringDisplayFrame::StringDisplayFrame()
{
	SetGraphMode(SCREENWIDTH_STRINGDISPLAY, SCREENHEIGHT_STRINGDISPLAY, COLORBITDEPTH);
	SetDrawScreen(DX_SCREEN_BACK);
	
	SetFontSize(SCREENHEIGHT_STRINGDISPLAY / 3 / 2);
}

void StringDisplayFrame::Start()
{
	billboard.Init(SCREENHEIGHT_STRINGDISPLAY / 3, SCREENHEIGHT_STRINGDISPLAY, 0, SCREENWIDTH_STRINGDISPLAY, LED_ROW, LED_COLUMN);
	billboard.Draw();
	WaitKey();
}


StringDisplayFrame::~StringDisplayFrame()
{
}
