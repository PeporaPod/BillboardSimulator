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
	SetFontSize(SCREENHEIGHT_MAIN / 14);								//フォントサイズ設定
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
	//選択肢を表示
	DrawString(0, 0, "\nSelect Mode\n 0: End\n 1: Simulator\n 2: String Display\n 3: String Editor", GetColor(200, 200, 200));

	/*モード選択*/
	do {
		WaitKey();							//入力待ち
		if (CheckHitKey(KEY_INPUT_0))
			return 0;							//終了
		else if (CheckHitKey(KEY_INPUT_1))
			return 1;							//シミュレータモードID
		else if (CheckHitKey(KEY_INPUT_2))
			return 2;							//文字列ディスプレイモードID
		else if (CheckHitKey(KEY_INPUT_3))
			return 3;							//文字列エディタモードID
	} while (!ProcessMessage());
	/*モード選択*/

	return -1;									//エラー時
}



//
//	デストラクタ
//
//
//
ModeSelectorFrame::~ModeSelectorFrame()
{
}
