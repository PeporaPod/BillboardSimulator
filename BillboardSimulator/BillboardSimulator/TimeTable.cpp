#include "TimeTable.h"



bool TimeTable::Processing(std::list<std::string> element, LineList linelist, StringList stringlist)
{
	if (element.size() < 4) return false;

	//路線ID
	int line =linelist.GetID(element.front());
	element.pop_front();
	if (element.empty()) return false;

	//種別ID
//	int type = stringlist.GetID(element.front());
	element.pop_front();
	if (element.empty()) return false;

	//発車時刻
	if (!Check_StringToInt(element.front()))
		return false;
	int time = std::stoi(element.front());
	element.pop_front();
	if (element.empty()) return false;

	//行先
//	int destination = stringlist.GetID(element.front());

	//4
	

	TrainInformation traininfo;
	traininfo.line = line;
//	traininfo.type = type;
//	traininfo.time = time;
//	traininfo.destination = destination;
	timetable.push_back(traininfo);

	return true;
}



//
//	コンストラクタ
//
//
TimeTable::TimeTable()
{
	std::ifstream file("新宿駅.csv");
	if (!file.is_open()) return;

	while (!file.eof()) {
		std::string str;
		std::getline(file, str);
		std::istringstream strstream(str);

		TrainInformation traininfo;
		std::list<std::string> strlist;
		while (!strstream.eof()) {
			str.clear();
			std::getline(strstream, str, ',');
			strlist.push_back(str);
		}
		if (strlist.size() < 7) break;
		traininfo.line = strlist.front(); strlist.pop_front();
		traininfo.type = strlist.front(); strlist.pop_front();
		strlist.pop_front(); strlist.pop_front();
		traininfo.departure_time = strlist.front(); strlist.pop_front();
		traininfo.destination = strlist.front(); strlist.pop_front();
		traininfo.platform = strlist.front(); strlist.pop_front();
		strlist.clear();
		timetable.push_back(traininfo);
	}
}



//
//	時刻表の読み込み
//
//
int TimeTable::Init()
{
	int count = 0;	//項目数

//	std::ifstream file(TIMETABLEFILE);	//ファイルオープン
//	if (!file.is_open()) return -1;			//エラー処理

	/*列車情報の読み込み*/
//	while (!file.eof()) {
		std::string str;
//		std::getline(file, str);
		std::istringstream strstream(str);		//一行読み込み
		std::list<std::string> element;

		while (!strstream.eof()) {
			str.clear();
			std::getline(strstream, str, ',');		//一項目読み込み
			element.push_back(str);
		}

//		if (Processing(element, linelist, stringlist))	//項目をフォーマット変換
			count++;										//列車数をカウント
		return 0;
	}
	/*列車情報の読み込み*/

//	return count;	//読み込んだ項目数を返す
//}



//
//	時刻表IDに対応する列車を先発としてLEDに列車情報を反映
//
//
void TimeTable::Set(LED_MATRIX& led_matrix, TABLESIZE tablesize, int id, int row, int x, int y, bool english_trigger)
{
	if (id == -1) return;	//列車が存在しない場合は終了

	for (int number = 0; number < row; number++) {
		if (id + number > (int)timetable.size()) break;	//終電処理

		//路線色
//		linelist.Set(led_matrix, tablesize, timetable[id + number].line, 16 * number + y);
		//種別
//		stringlist.Draw(led_matrix, tablesize, timetable[id + number].type, x + 8, 16 * number + y, english_trigger);
		//発車時刻
//		stringlist.SetDepartureTime(led_matrix, timetable[id + number].time, x + 56, 16 * number + y);
		//行先
//		stringlist.Draw(led_matrix, tablesize, timetable[id + number].destination, x + 112, 16 * number + y, english_trigger);
	}
}



//
//	時刻を参照して先発列車の時刻表IDを走査する
//
//
int TimeTable::GetID(int time)
{
	for (int id = 0; id < (int)timetable.size(); id++);
//		if (time < timetable[id].time) return id;	//発車時刻が現在時刻よりも遅い列車のIDを返す

	return -1;	//見つからなかった場合
}



TimeTable::~TimeTable()
{
}
