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
	MainLoop();
}



//
//	デストラクタ
//
//
//
SimulatorFrame::~SimulatorFrame()
{
}

void SimulatorFrame::MainLoop()
{
	for (int i = 0; i < 8; i++) {
		billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(i).type_id[0]), 16 * i, 0);
		billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(i).destination_id[0]), 16 * i, 48);
		if (timetablecontroler.GetTrainInformation(i).departure_time / 1000)
		billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(i).departure_time / 1000), 16 * i, 102);
		billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(i).departure_time / 100 % 10), 16 * i, 114);
		billboard.Commit(stringcontroler.GetNumberStringInformation(10), 16 * i, 126);
		billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(i).departure_time / 10 % 10), 16 * i, 129);
		billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(i).departure_time % 10), 16 * i, 141);
	}
	billboard.Draw();
	ScreenFlip();
	WaitKey();
}
