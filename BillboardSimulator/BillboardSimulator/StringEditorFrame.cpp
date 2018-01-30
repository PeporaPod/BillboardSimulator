#include "StringEditorFrame.h"



StringEditorFrame::StringEditorFrame()
{
	SetAlwaysRunFlag(FALSE);
	SetGraphMode(SCREENWIDTH_STRINGEDITOR, SCREENHEIGHT_STRINGEDITOR, COLORBITDEPTH);
	SetDrawScreen(DX_SCREEN_FRONT);
	SetFontSize(SCREENHEIGHT_STRINGDISPLAY / 12);
	SetMouseDispFlag(TRUE);
	current_id = 0;
}

void StringEditorFrame::Start()
{
	billboard.Init(SCREENHEIGHT_STRINGEDITOR / 2, SCREENHEIGHT_STRINGEDITOR, 0, SCREENWIDTH_STRINGEDITOR, LED_ROW, LED_COLUMN);	//LEDマトリクスの初期化
	size = stringcontroler.Init();
	current_strinfo = stringcontroler.GetStringInformation(current_id);
	billboard.Commit(current_strinfo.led_map, GetColor(current_strinfo.R, current_strinfo.G, current_strinfo.B));
	DrawFormatString(0, SCREENHEIGHT_STRINGDISPLAY / 12, GetColor(200, 200, 200), "ID: %03d / type:%c %s\nwidth: %2d | R: %3d G: %3d B: %3d", current_id + 1, current_strinfo.type, current_strinfo.str.c_str(), current_strinfo.width, current_strinfo.R, current_strinfo.G, current_strinfo.B);
	billboard.Draw();
	WaitKey();
}


StringEditorFrame::~StringEditorFrame()
{
}

void StringEditorFrame::WriteOut()
{
}
