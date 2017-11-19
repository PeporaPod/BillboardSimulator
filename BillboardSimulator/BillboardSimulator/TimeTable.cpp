#include "TimeTable.h"



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
