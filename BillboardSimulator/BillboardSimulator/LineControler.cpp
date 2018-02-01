#include "LineControler.h"



LineControler::LineControler()
{
}

int LineControler::Init()
{
	std::ifstream file("LINE\\˜Hü.csv");
	if (!file.is_open()) return 0;

	while (!file.eof()) {
		std::list<std::string> strlist;
		std::string str;
		std::getline(file, str);
		std::istringstream strstream(str);
		while (!strstream.eof()) {
			str.clear();
			std::getline(strstream, str, ',');
			if (!str.empty()) strlist.push_back(str);
		}
		if (strlist.empty()) break;
		LineInformation lineinfo;
		lineinfo.str = strlist.front();
		strlist.pop_front();
		switch (strlist.size()) {
		case 3:
			lineinfo.R[0] = lineinfo.R[1] = std::stoi(strlist.front());
			strlist.pop_front();
			lineinfo.G[0] = lineinfo.G[1] = std::stoi(strlist.front());
			strlist.pop_front();
			lineinfo.B[0] = lineinfo.B[1] = std::stoi(strlist.front());
			strlist.pop_front();
			break;
		case 6:
			for (int i = 0; i < 2; i++) {
				lineinfo.R[i] = std::stoi(strlist.front());
				strlist.pop_front();
				lineinfo.G[i] = std::stoi(strlist.front());
				strlist.pop_front();
				lineinfo.B[i] = std::stoi(strlist.front());
				strlist.pop_front();
			}
		}
		veclineinfo.push_back(lineinfo);
	}

	return veclineinfo.size();
}

LineInformation LineControler::GetLineInformation(int id)
{
	if (id < 0 || id > (int)veclineinfo.size() - 1) {
		LineInformation lineinfo;
		return lineinfo;
	}
	return veclineinfo[id];
}

int LineControler::GetLineID(std::string str)
{
	for (unsigned int i = 0; i < veclineinfo.size(); i++)
		if (veclineinfo[i].str == str) return i;	//•¶š—ñ,•¶š—ñí‚ª‡’v‚µ‚½
	return -1;	//‡’v‚·‚éƒf[ƒ^‚ª‚È‚©‚Á‚½ê‡
}


LineControler::~LineControler()
{
}

