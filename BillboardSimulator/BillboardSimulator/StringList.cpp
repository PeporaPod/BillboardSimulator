#include "StringList.h"



std::string StringList::StringToFilePass(std::string string)
{
	string.insert(0, SEGDIRECTORY);
	string += SEGEXTENSION;
	return string;
}

bool StringList::AddNumberString(std::string string)
{
	StringInformation strinfo;
	strinfo.string	= string;
	strinfo.color	= GetColor(173, 255, 47);

	string.insert(0, SEGNUMBERSTRINGDIRECTORY);
	string += SEGEXTENSION;

	std::ifstream file(string);
	if (!file.is_open()) return false;
	
	BOOLTABLE booltable;
	TABLESIZE tablesize;
	while (!file.eof()) {
		std::string str;
		std::getline(file, str);
		BOOLROW boolrow;
		for (UNSIGNEDINT i = 0; i < str.size(); i++) {
			if (str[i] == '1')
				boolrow.push_back(true);
			else
				boolrow.push_back(false);
		}
		booltable.push_back(boolrow);
		if (tablesize.column < (int)str.size())
			tablesize.column = str.size();
	}
	tablesize.row = booltable.size();

	/*�G���[����*/
	for (int i = 0; i < tablesize.row; i++)
		for (int j = (int)booltable[i].size(); j < tablesize.column; j++)
			booltable[i].push_back(false);
	/*�G���[����*/

	strinfo.table	= booltable;
	strinfo.size	= tablesize;
	StringList::number_string.push_back(strinfo);

	return true;
}

bool StringList::SetNumberString(LEDTABLE & billboard, int id, int x, int y)
{
	if (id == -1) return false;

	for (int i = 0; i < number_string[id].size.row; i++) {
		if (i + y >= (int)billboard.size()) break;	//�s�͂ݏo������
		for (int j = 0; j < number_string[id].size.column; j++) {
			if (j + x >= (int)billboard[i].size()) break;	//��͂ݏo������
			if (number_string[id].table[i][j])
				billboard[i + y][j + x].color = number_string[id].color;	//�_���w��
			else
				billboard[i + y][j + x].color = LED_OFF;				//�����w��
		}
	}

	return true;
}

bool StringList::AddString(PCHAR string, int red, int green, int blue)
{
	StringInformation strinfo;
	strinfo.string = string;
	strinfo.color = GetColor(red, green, blue);

	std::ifstream file(StringList::StringToFilePass(string));
	if (!file.is_open()) return false;

	BOOLTABLE booltable;
	TABLESIZE tablesize;
	while (!file.eof()) {
		std::string str;
		std::getline(file, str);
		BOOLROW boolrow;
		for (UNSIGNEDINT i = 0; i < str.size(); i++) {
			if (str[i] == '1')
				boolrow.push_back(true);
			else
				boolrow.push_back(false);
		}
		booltable.push_back(boolrow);
		if (tablesize.column < (int)str.size())
			tablesize.column = str.size();
	}
	tablesize.row = booltable.size();

	/*�G���[����*/
	for (int i = 0; i < tablesize.row; i++)
		for (int j = (int)booltable[i].size(); j < tablesize.column; j++)
			booltable[i].push_back(false);
	/*�G���[����*/

	strinfo.table = booltable;
	strinfo.size = tablesize;
	StringList::stringlist.push_back(strinfo);

	return true;
}

StringList::StringList()
{
}

bool StringList::Init()
{
	for (int i = 0; i < 10; i++) {
		std::ostringstream strstream;
		strstream << i;
		std::string string = strstream.str();
		if (!StringList::AddNumberString(string)) return false;
	}
	std::string string = "COLON";
	if (!StringList::AddNumberString(string)) return false;

	return true;
}

bool StringList::Add_Single(PCHAR string, int red, int green, int blue)
{
	if (!AddString(string, red, green, blue)) return false;
	std::string ENstring(string);						//������o�b�t�@
	ENstring += "_EN";										//��������p��\�L�ɕϊ�
	if (!AddString(&ENstring.front(), red, green, blue)) {
		stringlist.pop_back();
		return false;
	}
	return true;
}

int StringList::Add_Multiple(PCHAR ENUM_File)
{
	/*�t�@�C������*/
	std::ifstream file(ENUM_File);		//�t�@�C���I�[�v��
	if (!file.is_open()) return false;		//�G���[����
	/*�t�@�C������*/

	/*�ǂݎ��*/
	int count = 0;								//�ǉ����ꂽ������̐�

	while (!file.eof()) {
		std::string str;						//�v�f������o�b�t�@
		std::getline(file, str);				//��s�擾
		std::istringstream strstream(str);		//������s�o�b�t�@
		std::vector<std::string> element;	//�e�v�f�̕�����o�b�t�@
		while (!strstream.eof()) {
			str.clear();							//�v�f������o�b�t�@�̃N���A
			std::getline(strstream, str, ',');		//��v�f�擾
			if (!str.empty()) element.push_back(str);	//�v�f�̊m��
		}
		if (element.size() == 4) {
			if (Check_StringToInt(element[1]) && Check_StringToInt(element[2]) && Check_StringToInt(element[3])) {
				int red = std::stoi(element[1]);								//�ԗv�f
				int green = std::stoi(element[2]);								//�Ηv�f
				int blue = std::stoi(element[3]);								//�v�f
				if (Add_Single(&element[0].front(), red, green, blue)) count++;	//�������ǉ�
			}
		}
	}
	/*�ǂݎ��*/
	return count;
}

bool StringList::Draw(LEDTABLE& ledtable, TABLESIZE tablesize, int id, int x, int y, bool english_trigger)
{
	if (id == -1) return false;

	id += english_trigger;
	for (int row = 0; row < stringlist[id].size.row; row++) {
		if (row + y >= tablesize.row) break;	//�s�͂ݏo������
		for (int column = 0; column < stringlist[id].size.column; column++) {
			if (column + x >= tablesize.column) break;	//��͂ݏo������
			if (stringlist[id].table[row][column])
				ledtable[row + y][column + x].color = stringlist[id].color;	//�_���w��
			else
				ledtable[row + y][column + x].color = LED_OFF;				//�����w��
		}
	}

	return true;
}

bool StringList::SetDepartureTime(LEDTABLE& billboard, int departuretime, int x, int y)
{
	departuretime %= 2400;
	int time[5];
	time[0] = departuretime / 1000;
	time[1] = departuretime / 100 % 10;
	time[2] = 10;
	time[3] = departuretime / 10 % 10;
	time[4] = departuretime % 10;
	
	if (time[0])
		SetNumberString(billboard, time[0], x, y);
	SetNumberString(billboard, time[1], x + 12, y);
	SetNumberString(billboard, time[2], x + 25, y);
	SetNumberString(billboard, time[3], x + 29, y);
	SetNumberString(billboard, time[4], x + 41, y);

	return true;
}

int StringList::GetID(std::string string)
{
	for (int i = 0; i < (int)stringlist.size(); i++)
		if (stringlist[i].string == string) return i;
	return -1;
}


StringList::~StringList()
{
}
