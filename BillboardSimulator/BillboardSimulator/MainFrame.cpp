#include "MainFrame.h"



//
//	コンストラクタ
//
//		ウィンドウモード切替
//		フォント設定
//		DXライブラリの起動
//
//
//
MainFrame::MainFrame()
{
	ChangeWindowMode(TRUE);							//ウィンドウモード
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);	//アンチエイリアスフォント
	ChangeFont("Yu Gothic");						//フォント: Yu Gothic
	DxLib_Init();									//DXライブラリの起動
}



//
//	Startメソッド
//
//		モード設定 / 終了
//		各モードへ処理を委譲
//
//
//
bool MainFrame::Start()
{
	/*メインループ*/
	do {
		mode = -1;//エラー対応用の初期化

		/*モードセレクタ*/
		modeselectorframe = new ModeSelectorFrame;	//モードセレクタを構築
		mode = modeselectorframe->Start();			//稼働開始
		delete modeselectorframe;					//モードセレクタを終了
		/*モードセレクタ*/

		/*分岐処理*/
		switch (mode) {
		case 0:												//終了
			break;
		case 1:												//シミュレータモード
			simulatorframe = new SimulatorFrame;				//シミュレータを構築
			simulatorframe->Start();							//稼働開始
			delete simulatorframe;								//シミュレータを終了
			break;
		case 2:												//文字列ディスプレイモード
			stringdisplayframe = new StringDisplayFrame;		//文字列ディスプレイを構築
			stringdisplayframe->Start();						//稼働開始
			delete stringdisplayframe;							//文字列ディスプレイを終了
			break;
		case 3:												//文字列エディタモード
			stringeditorframe = new StringEditorFrame;			//文字列エディタを構築
			stringeditorframe->Start();							//稼働開始
			delete stringeditorframe;							//文字列エディタを終了
			break;
		default:											//エラー時
			return false;
		}
		/*分岐処理*/
	} while (mode);
	/*メインループ*/

	return true;
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
