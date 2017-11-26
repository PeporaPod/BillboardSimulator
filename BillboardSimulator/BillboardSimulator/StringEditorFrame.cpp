#include "StringEditorFrame.h"



StringEditorFrame::StringEditorFrame()
{
	SetAlwaysRunFlag(FALSE);
	SetGraphMode(SCREENWIDTH_STRINGEDITOR, SCREENHEIGHT_STRINGEDITOR, COLORBITDEPTH);
	SetDrawScreen(DX_SCREEN_FRONT);
	SetFontSize(SCREENHEIGHT_STRINGDISPLAY / 12);
	SetMouseDispFlag(TRUE);
}

void StringEditorFrame::Start()
{
	billboard.Init(SCREENHEIGHT_STRINGEDITOR / 2, SCREENHEIGHT_STRINGEDITOR, 0, SCREENWIDTH_STRINGEDITOR, LED_ROW, LED_COLUMN);
	billboard.Commit(stringinformation.led_status, GetColor(stringinformation.R, stringinformation.G, stringinformation.B));
	billboard.Draw();
	WaitKey();
}


StringEditorFrame::~StringEditorFrame()
{
}

void StringEditorFrame::WriteOut()
{
}
