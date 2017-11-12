#include "LineList.h"



//
//	�H�����ƘH���J���[�̎擾
//
//
bool LineList::Process(std::list<std::string> element)
{
	if (element.empty()) return false;

	LineInformation lineinfo;	//�H�����

	lineinfo.line = element.front();	//�H�����̎擾
	element.pop_front();

	/*�H���F1*/
	int rgb[3];
	for (int i = 0; i < 3; i++) {
		if (element.empty()) return false;
		if (!Check_StringToInt(element.front())) return false;	//�G���[����
		rgb[i] = std::stoi(element.front());
		element.pop_front();
	}
	lineinfo.color[0] = GetColor(rgb[0], rgb[1], rgb[2]);
	/*�H���F1*/

	/*�H���F2*/
	for (int i = 0; i < 3; i++) {
		if (element.empty()) break;
		if (!Check_StringToInt(element.front())) break;	//�G���[����
		rgb[i] = std::stoi(element.front());
		element.pop_front();
	}
	lineinfo.color[1] = GetColor(rgb[0], rgb[1], rgb[2]);
	/*�H���F2*/

	linelist.push_back(lineinfo);	//�H�����̒ǉ�

	return false;
}



//
//�R���X�g���N�^
//
//
LineList::LineList()
{
}



//
//	�H���̓ǂݍ���
//
//
int LineList::Init()
{
	/*�t�@�C���I�[�v��*/
	std::ifstream file(LINEFILE);
	if (!file.is_open()) return -1;
	/*�t�@�C���I�[�v��*/

	int count = 0;	//�ǂݍ��񂾘H����

	/*�H���ǂݍ���*/
	while (!file.eof()) {
		std::string str;
		std::getline(file, str);
		std::istringstream strstream(str);

		std::list<std::string> element;
		while (!strstream.eof()) {
			str.clear();
			std::getline(strstream, str, ',');
			element.push_back(str);
		}

		if (LineList::Process(element))
			count++;						//�H�������J�E���g
	}
	/*�H���ǂݍ���*/

	return count;	//�ǂݍ��񂾘H����
}



//
//	�H���J���[��LED�ɔ��f
//
//
void LineList::Set(LEDTABLE & led_table, TABLESIZE table_size, int line_id, int y)
{
	if (line_id == -1) return;

	/*�H��1�F��*/
	for (int row = 1; row < 8; row++) {
		if (row + y >= table_size.row) break;
		for (int column = 0; column < 4; column++) {
			if (column >= table_size.column) break;
			led_table[row + y][column].color = linelist[line_id].color[0];
			led_table[row + y][table_size.column - column - 1].color = linelist[line_id].color[0];
		}
	}
	/*�H��1�F��*/

	/*�H��2�F��*/
	for (int row = 8; row < 15; row++) {
		if (row + y >= table_size.row) break;
		for (int column = 0; column < 4; column++) {
			if (column >= table_size.column) break;
			led_table[row + y][column].color = linelist[line_id].color[1];
			led_table[row + y][table_size.column - column - 1].color = linelist[line_id].color[1];
		}
	}
	/*�H��2�F��*/
}



//
//	�H��ID���擾
//
//
int LineList::GetID(std::string line_name)
{
	int id = 0;
	for (int i = 0; i < (int)linelist.size(); i++)
		if (linelist[i].line == line_name) return i;
	return -1;
}



//
//	�f�X�g���N�^
//
//
LineList::~LineList()
{
}