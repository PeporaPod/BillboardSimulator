#include "StringDisplayFrame.h"



StringDisplayFrame::StringDisplayFrame()
{
	SetAlwaysRunFlag(FALSE);
	SetGraphMode(SCREENWIDTH_STRINGDISPLAY, SCREENHEIGHT_STRINGDISPLAY, COLORBITDEPTH);
	SetDrawScreen(DX_SCREEN_FRONT);
	SetFontSize(SCREENHEIGHT_STRINGDISPLAY / 12);
	SetMouseDispFlag(FALSE);
	string_id = 0;
}

void StringDisplayFrame::Start()
{
	billboard.Init(SCREENHEIGHT_STRINGDISPLAY / 3, SCREENHEIGHT_STRINGDISPLAY, 0, SCREENWIDTH_STRINGDISPLAY, LED_ROW, LED_COLUMN);
	timetable.Init(true);
	size = stringfile.Init();
	MainLoop();
}


StringDisplayFrame::~StringDisplayFrame()
{
}

void StringDisplayFrame::MainLoop()
{
	while (!ProcessMessage() && !ClearDrawScreen() && string_id < size) {
		stringinformation = stringfile.GetStringInformation(string_id);
		billboard.Commit(stringinformation.led_map, GetColor(stringinformation.R, stringinformation.G, stringinformation.B));
		billboard.Draw();
		DrawFormatString(0, SCREENHEIGHT_STRINGDISPLAY / 12, GetColor(200, 200, 200), "ID: %03d / type:%c %s\nwidht: %2d | R: %3d G: %3d B: %3d", string_id + 1, stringinformation.type, stringinformation.str.c_str(), stringinformation.width, stringinformation.R, stringinformation.G, stringinformation.B);
		WaitKey();
		if (CheckHitKey(KEY_INPUT_RETURN))
			string_id++;
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
			return;
	}
}
