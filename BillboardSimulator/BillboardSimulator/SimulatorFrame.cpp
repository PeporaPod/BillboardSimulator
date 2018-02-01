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
	linecontroler.Init();	//路線情報の初期化
	stringcontroler.Init();	//文字列情報の初期化
	if (!timetablecontroler.Init(linecontroler, stringcontroler)) return;	//時刻表情報の初期化
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
	int update_time = GetNowCount();
	int engtrig = 0;
	DATEDATA datedata;
	while (!CheckHitKey(KEY_INPUT_ESCAPE)) {
		GetDateTime(&datedata);
		int id = -1;
		if (GetNowCount() - update_time > 3000) {
			update_time = GetNowCount();
			engtrig = engtrig ? 0 : 1;
		}
		while (timetablecontroler.GetTrainInformation(++id).departure_time <= datedata.Hour * 100 + datedata.Min);
		for (int i = 0; i < 8; i++) {
			billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(id + i).type_id[engtrig]), 16 * i, 5);
			billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(id + i).destination_id[engtrig]), 16 * i, 53);
			if (timetablecontroler.GetTrainInformation(id + i).departure_time % 2400 / 1000)
				billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time % 2400 / 1000), 16 * i, 117);
			billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time % 2400 / 100 % 10), 16 * i, 129);
			billboard.Commit(stringcontroler.GetNumberStringInformation(10), 16 * i, 141);
			billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time / 10 % 10), 16 * i, 144);
			billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time % 10), 16 * i, 156);
			billboard.Commit(linecontroler.GetLineInformation(timetablecontroler.GetTrainInformation(id + i).line_id), 16 * i);
		}
		billboard.Draw();
		ScreenFlip();
	}
}
