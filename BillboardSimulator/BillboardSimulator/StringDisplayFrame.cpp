#include "StringDisplayFrame.h"



//
//	コンストラクタ
//
//
StringDisplayFrame::StringDisplayFrame()
{
	SetAlwaysRunFlag(FALSE);															//バックグラウンド時動作停止
	SetGraphMode(SCREENWIDTH_STRINGDISPLAY, SCREENHEIGHT_STRINGDISPLAY, COLORBITDEPTH);	//描画サイズ,色ビット深度指定
	SetDrawScreen(DX_SCREEN_BACK);														//描画先画面を裏画面に指定
	SetFontSize(font_size);																//フォントサイズ設定
	SetMouseDispFlag(TRUE);																//マウスポインタを表示
	current_id = 0;																		//初期表示文字列IDを初期化
}



//
//	実行開始メソッド
//
//
void StringDisplayFrame::Start()
{
	billboard.Init((int)(font_size * 4), SCREENHEIGHT_STRINGDISPLAY, 0, SCREENWIDTH_STRINGDISPLAY, LED_ROW, LED_COLUMN);	//LEDマトリクスの初期化
	str_vecsize = stringcontroler.Init();																					//文字列情報の初期化,読み込んだ文字列数の取得
	StringDisplayFrame::MainLoop();																							//主実行メソッドへ制御を委譲
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
	while (!ProcessMessage() && current_id < str_vecsize) {
		current_strinfo = stringcontroler.GetStringInformation(current_id);	//文字列情報の取得

		/*描画処理*/
			//裏画面の初期化
		ClearDrawScreen();
			//情報の描画
		DrawFormatString(0, (int)(0.5 * font_size), GetColor(200, 200, 200), "ID:%03d / type:%c / %s<EOF>\nwidth: %02d | R: %02x G: %02x B: %02x", current_id + 1, current_strinfo.type, current_strinfo.str.c_str(), current_strinfo.width, current_strinfo.R, current_strinfo.G, current_strinfo.B);
			//LEDマトリクスへマッピングを反映
		billboard.Commit(current_strinfo.led_map, GetColor(current_strinfo.R, current_strinfo.G, current_strinfo.B));
			//LEDマトリクスの描画
		billboard.Draw();
			//画面のフリッピング
		ScreenFlip();
		/*描画処理*/

		/*ユーザ操作*/
		WaitKey();	//キー入力待ち
		if (CheckHitKey(KEY_INPUT_RETURN))							//次の文字へ
			current_id++;
		else if (CheckHitKey(KEY_INPUT_BACK) && current_id > 0)		//前の文字へ
			current_id--;
		else if (CheckHitKey(KEY_INPUT_HOME))						//先頭の文字へ
			current_id = 0;
		else if (CheckHitKey(KEY_INPUT_END))						//末尾の文字へ
			current_id = str_vecsize - 1;
		else if (CheckHitKey(KEY_INPUT_PGDN))						//10個前の文字へ移動
			if (current_id > 9)	current_id -= 10;
			else current_id = 0;
		else if (CheckHitKey(KEY_INPUT_PGUP))						//10個後の文字へ移動
			if (current_id < str_vecsize - 10)	current_id += 10;
			else current_id = str_vecsize - 1;
		else if (CheckHitKey(KEY_INPUT_ESCAPE))						//終了
			return;
		/*ユーザ操作*/
	}
}

