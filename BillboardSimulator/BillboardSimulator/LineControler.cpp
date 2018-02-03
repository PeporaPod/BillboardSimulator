#include "LineControler.h"



//
//	コンストラクタ
//
//
LineControler::LineControler()
{
}

int LineControler::Init()
{
	/*ファイルをオープン*/
	std::ifstream file("LINE\\路線.csv");								//路線情報ファイルをオープン
	if (!file.is_open()) return 0;											//エラー処理
	/*ファイルをオープン*/

	veclineinfo.clear();												//路線情報配列の初期化
	/*路線情報のロード*/
	while (!file.eof()) {
		/*CSVファイルから1路線分の情報を取得*/
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
		/*CSVファイルから1路線分の情報を取得*/
		/*フォーマット変換*/
		LineInformation lineinfo;										//新規路線情報のバッファ
		lineinfo.str = strlist.front();										//路線名の取得
		strlist.pop_front();
		switch (strlist.size()) {
		case 3:																//路線カラーが1種の場合
			lineinfo.R[0] = lineinfo.R[1] = My_stoi(strlist.front());			//R光度
			strlist.pop_front();
			lineinfo.G[0] = lineinfo.G[1] = My_stoi(strlist.front());			//G光度
			strlist.pop_front();
			lineinfo.B[0] = lineinfo.B[1] = My_stoi(strlist.front());			//B光度
			strlist.pop_front();
			break;
		case 6:																//路線カラーが2種の場合
			for (int i = 0; i < 2; i++) {
				lineinfo.R[i] = My_stoi(strlist.front());						//R光度
				strlist.pop_front();
				lineinfo.G[i] = My_stoi(strlist.front());						//G光度
				strlist.pop_front();
				lineinfo.B[i] = My_stoi(strlist.front());						//B光度
				strlist.pop_front();
			}
		}
		/*フォーマット変換*/
		veclineinfo.push_back(lineinfo);									//路線情報を配列へ追加
	}
	/*路線情報のロード*/

	return veclineinfo.size();											//取得した路線数を返却
}



//
//
//
//
LineInformation LineControler::GetLineInformation(int id)
{
	if (id < 0 || id > (int)veclineinfo.size() - 1) {
		LineInformation lineinfo;
		return lineinfo;								//合致するデータがなかった場合
	}
	return veclineinfo[id];								//指定の路線情報を返却
}



//
//
//
//
int LineControler::GetLineID(std::string str)
{
	for (unsigned int i = 0; i < veclineinfo.size(); i++)
		if (veclineinfo[i].str == str) return i;			//文字列,文字列種が合致した
	return -1;												//合致するデータがなかった場合
}



//
//	デストラクタ
//
//
LineControler::~LineControler()
{
}

