#include "SimulatorFrame.h"



//
//	コンストラク
//
//		常時処理設定
//		画面描画設定
//
//
//
SimulatorFrame::SimulatorFrame()
{
	SetAlwaysRunFlag(TRUE);														//常時処理をオン
	SetGraphMode(SCREENWIDTH_SIMULATOR, SCREENHEIGHT_SIMULATOR, COLORBITDEPTH);	//画面サイズ
	SetDrawScreen(DX_SCREEN_BACK);												//裏画面描画
}



//
//	稼働開始メソッド
//
//		LEDマトリクスの初期化
//
//
//
void SimulatorFrame::Start()
{
	billboard.Init();	//LEDマトリクスの初期化
	billboard.Draw();
	WaitKey();
}



//
//	デストラクタ
//
//
//
SimulatorFrame::~SimulatorFrame()
{
}
