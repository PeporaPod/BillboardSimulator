#include "LineList.h"



//
//	路線名と路線カラーの取得
//
//
bool LineList::Process(std::list<std::string> element)
{
	if (element.empty()) return false;

	LineInformation lineinfo;	//路線情報

	lineinfo.line = element.front();	//路線名の取得
	element.pop_front();

	/*路線色1*/
	int rgb[3];
	for (int i = 0; i < 3; i++) {
		if (element.empty()) return false;
		if (!Check_StringToInt(element.front())) return false;	//エラー処理
		rgb[i] = std::stoi(element.front());
		element.pop_front();
	}
	lineinfo.color[0] = GetColor(rgb[0], rgb[1], rgb[2]);
	/*路線色1*/

	/*路線色2*/
	for (int i = 0; i < 3; i++) {
		if (element.empty()) break;
		if (!Check_StringToInt(element.front())) break;	//エラー処理
		rgb[i] = std::stoi(element.front());
		element.pop_front();
	}
	lineinfo.color[1] = GetColor(rgb[0], rgb[1], rgb[2]);
	/*路線色2*/

	linelist.push_back(lineinfo);	//路線情報の追加

	return false;
}



//
//コンストラクタ
//
//
LineList::LineList()
{
}



//
//	路線の読み込み
//
//
int LineList::Init()
{
	/*ファイルオープン*/
	std::ifstream file(LINEFILE);
	if (!file.is_open()) return -1;
	/*ファイルオープン*/

	int count = 0;	//読み込んだ路線数

	/*路線読み込み*/
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
			count++;						//路線数をカウント
	}
	/*路線読み込み*/

	return count;	//読み込んだ路線数
}



//
//	路線カラーをLEDに反映
//
//
void LineList::Set(LEDTABLE & led_table, TABLESIZE table_size, int line_id, int y)
{
	if (line_id == -1) return;

	/*路線1色目*/
	for (int row = 1; row < 8; row++) {
		if (row + y >= table_size.row) break;
		for (int column = 0; column < 4; column++) {
			if (column >= table_size.column) break;
			led_table[row + y][column].color = linelist[line_id].color[0];
			led_table[row + y][table_size.column - column - 1].color = linelist[line_id].color[0];
		}
	}
	/*路線1色目*/

	/*路線2色目*/
	for (int row = 8; row < 15; row++) {
		if (row + y >= table_size.row) break;
		for (int column = 0; column < 4; column++) {
			if (column >= table_size.column) break;
			led_table[row + y][column].color = linelist[line_id].color[1];
			led_table[row + y][table_size.column - column - 1].color = linelist[line_id].color[1];
		}
	}
	/*路線2色目*/
}



//
//	路線IDを取得
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
//	デストラクタ
//
//
LineList::~LineList()
{
}