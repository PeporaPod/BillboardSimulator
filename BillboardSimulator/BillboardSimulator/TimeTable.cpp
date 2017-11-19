#include "TimeTable.h"



bool TimeTable::Processing(std::list<std::string> element, LineList linelist, StringList stringlist)
{
	if (element.size() < 4) return false;

	//�H��ID
	int line =linelist.GetID(element.front());
	element.pop_front();
	if (element.empty()) return false;

	//���ID
//	int type = stringlist.GetID(element.front());
	element.pop_front();
	if (element.empty()) return false;

	//���Ԏ���
	if (!Check_StringToInt(element.front()))
		return false;
	int time = std::stoi(element.front());
	element.pop_front();
	if (element.empty()) return false;

	//�s��
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
//	�����\�̓ǂݍ���
//
//
int TimeTable::Init()
{
	int count = 0;	//���ڐ�

//	std::ifstream file(TIMETABLEFILE);	//�t�@�C���I�[�v��
//	if (!file.is_open()) return -1;			//�G���[����

	/*��ԏ��̓ǂݍ���*/
//	while (!file.eof()) {
		std::string str;
//		std::getline(file, str);
		std::istringstream strstream(str);		//��s�ǂݍ���
		std::list<std::string> element;

		while (!strstream.eof()) {
			str.clear();
			std::getline(strstream, str, ',');		//�ꍀ�ړǂݍ���
			element.push_back(str);
		}

//		if (Processing(element, linelist, stringlist))	//���ڂ��t�H�[�}�b�g�ϊ�
			count++;										//��Ԑ����J�E���g
		return 0;
	}
	/*��ԏ��̓ǂݍ���*/

//	return count;	//�ǂݍ��񂾍��ڐ���Ԃ�
//}



//
//	�����\ID�ɑΉ������Ԃ�攭�Ƃ���LED�ɗ�ԏ��𔽉f
//
//
void TimeTable::Set(LED_MATRIX& led_matrix, TABLESIZE tablesize, int id, int row, int x, int y, bool english_trigger)
{
	if (id == -1) return;	//��Ԃ����݂��Ȃ��ꍇ�͏I��

	for (int number = 0; number < row; number++) {
		if (id + number > (int)timetable.size()) break;	//�I�d����

		//�H���F
//		linelist.Set(led_matrix, tablesize, timetable[id + number].line, 16 * number + y);
		//���
//		stringlist.Draw(led_matrix, tablesize, timetable[id + number].type, x + 8, 16 * number + y, english_trigger);
		//���Ԏ���
//		stringlist.SetDepartureTime(led_matrix, timetable[id + number].time, x + 56, 16 * number + y);
		//�s��
//		stringlist.Draw(led_matrix, tablesize, timetable[id + number].destination, x + 112, 16 * number + y, english_trigger);
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
