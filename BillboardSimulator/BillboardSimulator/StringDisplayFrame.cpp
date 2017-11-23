#include "StringDisplayFrame.h"



StringDisplayFrame::StringDisplayFrame()
{
	SetAlwaysRunFlag(FALSE);
	SetGraphMode(SCREENWIDTH_STRINGDISPLAY, SCREENHEIGHT_STRINGDISPLAY, COLORBITDEPTH);
	SetDrawScreen(DX_SCREEN_FRONT);
	SetFontSize(SCREENHEIGHT_STRINGDISPLAY / 12);
	string_id = 0;
}

void StringDisplayFrame::Start()
{
	billboard.Init(SCREENHEIGHT_STRINGDISPLAY / 3, SCREENHEIGHT_STRINGDISPLAY, 0, SCREENWIDTH_STRINGDISPLAY, LED_ROW, LED_COLUMN);
	timetable.Init(true);
	stringfile.Init();
	MainLoop();
}


StringDisplayFrame::~StringDisplayFrame()
{
}

void StringDisplayFrame::MainLoop()
{
	while (!ProcessMessage() && !ClearDrawScreen()) {
		if (!stringfile.GetStringInformation(stringinformation, string_id))
			return;
		billboard.Commit(stringinformation.led_status, GetColor(stringinformation.R, stringinformation.G, stringinformation.B));
		billboard.Draw();
		DrawFormatString(0, 0, GetColor(200, 200, 200), "ID: %03d", string_id + 1);
		WaitKey();
		if (CheckHitKey(KEY_INPUT_RETURN))
			string_id++;
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
			return;
	}
}
