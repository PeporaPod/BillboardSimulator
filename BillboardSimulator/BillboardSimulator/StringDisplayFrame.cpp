#include "StringDisplayFrame.h"



//
//	コンストラクタ
//
//
StringDisplayFrame::StringDisplayFrame()
{
	SetAlwaysRunFlag(FALSE);	//バックグラウンド時動作停止
	SetGraphMode(SCREENWIDTH_STRINGDISPLAY, SCREENHEIGHT_STRINGDISPLAY, COLORBITDEPTH);	//描画サイズ,色ビット深度指定
	SetDrawScreen(DX_SCREEN_BACK);	//描画先画面を裏画面に指定
	SetFontSize(SCREENHEIGHT_STRINGDISPLAY / 12);	//フォントサイズ設定
	SetMouseDispFlag(FALSE);	//マウスポインタを非表示
	current_str_id = 0;	//初期表示文字列IDを初期化
}



//
//	実行開始メソッド
//
//
void StringDisplayFrame::Start()
{
	billboard.Init(SCREENHEIGHT_STRINGDISPLAY / 3, SCREENHEIGHT_STRINGDISPLAY, 0, SCREENWIDTH_STRINGDISPLAY, LED_ROW, LED_COLUMN);	//LEDマトリクスの初期化
	size = stringcontroler.Init();	//文字列情報の初期化,読み込んだ文字列数の取得
	StringDisplayFrame::MainLoop();	//主実行メソッドへ制御を委譲
}



//
//	デストラクタ
//
//
StringDisplayFrame::~StringDisplayFrame()
{
}



//
//	主実行メソッド
//
//
void StringDisplayFrame::MainLoop()
{
	while (!ProcessMessage() && !ClearDrawScreen() && current_str_id < size) {
		current_strinfo = stringcontroler.GetStringInformation(current_str_id);
		billboard.Commit(current_strinfo.led_map, GetColor(current_strinfo.R, current_strinfo.G, current_strinfo.B));
		billboard.Draw();
		DrawFormatString(0, SCREENHEIGHT_STRINGDISPLAY / 12, GetColor(200, 200, 200), "ID: %03d / type:%c %s\nwidth: %2d | R: %3d G: %3d B: %3d", current_str_id + 1, current_strinfo.type, current_strinfo.str.c_str(), current_strinfo.width, current_strinfo.R, current_strinfo.G, current_strinfo.B);
		ScreenFlip();
		WaitKey();
		if (CheckHitKey(KEY_INPUT_RETURN))
			current_str_id++;
		else if (CheckHitKey(KEY_INPUT_BACK)) {
			if (current_str_id > 0) current_str_id--;
		}
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
			return;
	}
}
