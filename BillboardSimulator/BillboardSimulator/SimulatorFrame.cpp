#include "SimulatorFrame.h"



//
//	コンストラクタ
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
	SetMouseDispFlag(FALSE);
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
	stringcontroler.Init();	//文字列情報の初期化
	if (!timetablecontroler.Init(stringcontroler)) return;	//時刻表情報の初期化
	billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(0).type_id[0]));
	billboard.Draw();
	ScreenFlip();
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
