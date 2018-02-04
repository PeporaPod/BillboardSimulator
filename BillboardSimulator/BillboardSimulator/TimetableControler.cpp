#include "TimetableControler.h"



TimetableControler::TimetableControler()
{
}



bool TimetableControler::Init(LineControler linecontroler, StringControler stringcontroler)
{
	std::ifstream file("TT\\êVèhâw.csv");
	if (!file.is_open()) return false;

	while (!file.eof()) {
		std::list<std::string> strlist;
		std::string str;
		std::getline(file, str);
		std::istringstream strstream(str);
		while (!strstream.eof()) {
			str.clear();
			std::getline(strstream, str, ',');
			strlist.push_back(str);
		}
		timetable.push_back(ProcessTrainInformation(strlist, &linecontroler, &stringcontroler));
	}
	return true;
}



TrainInformation TimetableControler::GetTrainInformation(int id)
{
	return timetable[id];
}



TimetableControler::~TimetableControler()
{
}





TrainInformation TimetableControler::ProcessTrainInformation(std::list<std::string> strlist, LineControler* linecontroler, StringControler* stringcontroler)
{
	TrainInformation traininfo;
	if (strlist.size() != 9) return traininfo;
	traininfo.line_color_id = linecontroler->GetLineID(strlist.front());
	traininfo.line_str_id[0] = stringcontroler->GetStringID(strlist.front(), 'J');
	traininfo.line_str_id[1] = stringcontroler->GetStringID(strlist.front(), 'E');
	strlist.pop_front();
	traininfo.type_id[0] = stringcontroler->GetStringID(strlist.front(), 'J');
	traininfo.type_id[1] = stringcontroler->GetStringID(strlist.front(), 'E');
	strlist.pop_front();
	strlist.pop_front();
	strlist.pop_front();
	traininfo.departure_time = My_stoi(strlist.front());
	strlist.pop_front();
	traininfo.destination_id[0] = stringcontroler->GetStringID(strlist.front(), 'J');
	traininfo.destination_id[1] = stringcontroler->GetStringID(strlist.front(), 'E');
	strlist.pop_front();
	traininfo.track = My_stoi(strlist.front());
	strlist.pop_front();
	if (strlist.front().size()) traininfo.dep = true;
	strlist.pop_front();
	return traininfo;
}

