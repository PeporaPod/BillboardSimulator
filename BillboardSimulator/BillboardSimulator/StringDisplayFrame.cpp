#include "StringDisplayFrame.h"



StringDisplayFrame::StringDisplayFrame()
{
	SetAlwaysRunFlag(FALSE);
	SetGraphMode(SCREENWIDTH_STRINGDISPLAY, SCREENHEIGHT_STRINGDISPLAY, COLORBITDEPTH);
	SetDrawScreen(DX_SCREEN_FRONT);
	SetFontSize(SCREENHEIGHT_STRINGDISPLAY / 12);
}

void StringDisplayFrame::Start()
{
	billboard.Init(SCREENHEIGHT_STRINGDISPLAY / 3, SCREENHEIGHT_STRINGDISPLAY, 0, SCREENWIDTH_STRINGDISPLAY, LED_ROW, LED_COLUMN);
	stringfile.Init();
	billboard.Commit(stringinformation.led_status, GetColor(stringinformation.R, stringinformation.G, stringinformation.B));
	billboard.Draw();
	WaitKey();
}


StringDisplayFrame::~StringDisplayFrame()
{
}
