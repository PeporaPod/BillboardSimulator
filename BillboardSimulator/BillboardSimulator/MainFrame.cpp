#include "MainFrame.h"



//
//	コンストラクタ
//
//		ウィンドウモード切替
//		グローバルフォント設定
//
//
//
MainFrame::MainFrame()
{
#ifndef FULL_SCREEN
	ChangeWindowMode(TRUE);							//ウィンドウモード
#endif
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);	//アンチエイリアスフォント
	ChangeFont("Yu Gothic");						//フォント: Yu Gothic
	SetFontThickness(4);							//フォントの太さ
}



//
//	Startメソッド
//
//		DXライブラリの起動
//		モード選択 / 終了
//		選択したモードへ処理を引き継ぐ
//
//
//
bool MainFrame::Start()
{
	DxLib_Init();											//DXライブラリの起動
	
	/*メインループ*/
	do {
		mode = -1;											//選択モードを初期化

		/*モードセレクタ*/
		modeselectorframe = new ModeSelectorFrame;			//モードセレクタを構築
		mode = modeselectorframe->Start();					//稼働開始
		delete modeselectorframe;							//モードセレクタを終了
		/*モードセレクタ*/

		/*分岐処理*/
		switch (mode) {
		case 1:													//シミュレータモード
			simulatorframe = new SimulatorFrame;					//シミュレータを構築
			simulatorframe->Start();								//稼働開始
			delete simulatorframe;									//シミュレータを終了
			break;
		case 2:													//文字列ディスプレイモード
			stringdisplayframe = new StringDisplayFrame;			//文字列ディスプレイを構築
			stringdisplayframe->Start();							//稼働開始
			delete stringdisplayframe;								//文字列ディスプレイを終了
			break;
		case 3:													//文字列エディタモード
			stringeditorframe = new StringEditorFrame;				//文字列エディタを構築
			stringeditorframe->Start();								//稼働開始
			delete stringeditorframe;								//文字列エディタを終了
			break;
		case 0:													//正常終了
			return true;
		default:												//異常終了
			return false;
		}
		/*分岐処理*/
	} while (true);
	/*メインループ*/
}



//
//	デストラクタ
//
//		DXライブラリの終了
//
//
//
MainFrame::~MainFrame()
{
	DxLib_End();	//DXライブラリの終了
}

