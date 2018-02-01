#include "ModeSelectorFrame.h"



//
//	コンストラクタ
//
//		常時処理設定
//		画面描画設定
//		フォント設定
//
//
//
ModeSelectorFrame::ModeSelectorFrame()
{
	SetAlwaysRunFlag(FALSE);											//常時処理をオフ
	SetGraphMode(SCREENWIDTH_MAIN, SCREENHEIGHT_MAIN, COLORBITDEPTH);	//画面サイズ設定
	SetDrawScreen(DX_SCREEN_FRONT);										//表画面描画
	SetFontSize(font_size);												//フォントサイズ設定
	SetMouseDispFlag(TRUE);												//マウス表示を"あり"に設定
}



//
//	Startメソッド
//
//		選択肢表示
//		モード選択
//
//
//
int ModeSelectorFrame::Start()
{
	/*選択肢を表示*/
	DrawString(0, (int)(0.5 * font_size), "モードを選択して下さい\n 0: プログラムの終了\n 1: シミュレータモード\n 2: 文字列確認モード\n 3: 文字列編集モード", GetColor(200, 200, 200));
	/*選択肢を表示*/

	/*モード選択*/
	do {
		WaitKey();										//入力待ち
		if		(CheckHitKey(KEY_INPUT_0)) return 0;		//終了
		else if (CheckHitKey(KEY_INPUT_1)) return 1;		//シミュレータモードID
		else if (CheckHitKey(KEY_INPUT_2)) return 2;		//文字列ディスプレイモードID
		else if (CheckHitKey(KEY_INPUT_3)) return 3;		//文字列エディタモードID
	} while (!ProcessMessage());
	return -1;											//エラー時
	/*モード選択*/
}



//
//	デストラクタ
//
//
//
ModeSelectorFrame::~ModeSelectorFrame()
{
}
