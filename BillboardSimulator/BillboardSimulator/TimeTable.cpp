#include "TimeTable.h"



//
//	�R���X�g���N�^
//
//
TimeTable::TimeTable()
{
	std::ifstream file("�V�h�w.csv");
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
//	�������Q�Ƃ��Đ攭��Ԃ̎����\ID�𑖍�����
//
//
int TimeTable::GetID(int time)
{
	for (int id = 0; id < (int)timetable.size(); id++);
//		if (time < timetable[id].time) return id;	//���Ԏ��������ݎ��������x����Ԃ�ID��Ԃ�

	return -1;	//������Ȃ������ꍇ
}



TimeTable::~TimeTable()
{
}
