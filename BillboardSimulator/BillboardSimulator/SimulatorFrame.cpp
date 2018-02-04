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
	SetMouseDispFlag(FALSE);													//マウス表示"なし"
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
	billboard.Init();														//LEDマトリクスの初期化
	linecontroler.Init();													//路線情報の初期化
	stringcontroler.Init();													//文字列情報の初期化
	if (!timetablecontroler.Init(linecontroler, stringcontroler)) return;	//時刻表情報の初期化
	MainLoop();																//主処理メソッドへ制御を委譲
}



//
//	デストラクタ
//
//
//
SimulatorFrame::~SimulatorFrame()
{
	ClearDrawScreen();
	ScreenFlip();
	ClearDrawScreen();
}





//
//	主処理メソッド
//
//
void SimulatorFrame::MainLoop()
{
	std::vector<int> position_x, position_y;
	int radius;
	billboard.GetPositionReference(&position_x, &position_y, &radius);
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
		for (unsigned int i = 0; i < position_y.size() / 16; i++) {
			unsigned int offset_column = 5;
			billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(id + i).line_str_id[engtrig]), 16 * i, offset_column);
			offset_column += 32 + 5;
			billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(id + i).type_id[engtrig]), 16 * i, offset_column);
			offset_column += 32;
			billboard.Commit(stringcontroler.GetStringInformation(timetablecontroler.GetTrainInformation(id + i).destination_id[engtrig]), 16 * i, offset_column);
			offset_column += 64;
			if (timetablecontroler.GetTrainInformation(id + i).departure_time % 2400 / 1000)
				billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time % 2400 / 1000), 16 * i, offset_column);
			offset_column += 12;
			billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time % 2400 / 100 % 10), 16 * i, offset_column);
			offset_column += 12;
			billboard.Commit(stringcontroler.GetNumberStringInformation(10), 16 * i, offset_column);
			offset_column +=  3;
			billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time / 10 % 10), 16 * i, offset_column);
			offset_column += 12;
			billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).departure_time % 10), 16 * i, offset_column);
			offset_column += 12;
			if (timetablecontroler.GetTrainInformation(id + i).dep) {
				if (engtrig) billboard.Commit(stringcontroler.GetStringInformation("始発", 'E'), 16 * i, offset_column);
				else billboard.Commit(stringcontroler.GetStringInformation("始発", 'J'), 16 * i, offset_column);
			}
			if (timetablecontroler.GetTrainInformation(id + i).track / 10) {
				offset_column += 16;
				billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).track / 10), 16 * i, offset_column);
				offset_column += 10;
				billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).track % 10), 16 * i, offset_column);
			}
			else {
				offset_column += 21;
				billboard.Commit(stringcontroler.GetNumberStringInformation(timetablecontroler.GetTrainInformation(id + i).track % 10), 16 * i, offset_column);
			}
			billboard.Commit(linecontroler.GetLineInformation(timetablecontroler.GetTrainInformation(id + i).line_color_id), 16 * i);
		}
		billboard.Draw();
		ScreenFlip();
		billboard.Clear();
	}
}

