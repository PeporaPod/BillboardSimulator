#include "StringControler.h"



//
//	コンストラクタ
//
//
StringControler::StringControler()
{
}



//
//	全文字列情報のロード
//
//
int StringControler::Init()
{
	if (!vecstrinfo.empty())
		vecstrinfo.clear();
	if (!error_file.empty())
		error_file.clear();
	for (int i = 1; true; i++) {
		switch (LoadStringInformation(i)) {	//バイナリファイルから文字列情報を取得
		case -1:
			return i - 1;	//ファイルが不在の時ループから抜け終了
		case 1:
			error_file.push_back(i);
		}
	}
}



//
//	ID番号から文字列情報を返却
//
//
StringInformation StringControler::GetStringInformation(int id)
{
	if (id < 0 || id > (int)vecstrinfo.size() - 1) {
		StringInformation strinfo;
		return strinfo;
	}
	return vecstrinfo[id];
}



//
//	表記文字列と文字列種から文字列情報を返却
//
//
StringInformation StringControler::GetStringInformation(std::string str, char type)
{
	for (unsigned int i = 0; i < vecstrinfo.size(); i++)
		if (vecstrinfo[i].str == str && vecstrinfo[i].type == type) return vecstrinfo[i];	//文字列,文字列種が合致した
	StringInformation strinfo;
	return strinfo;	//合致するものがデータ上になかった場合
}



//
//	表記文字列と文字列種からIDを返却
//
//
int StringControler::GetStringID(std::string str, char type)
{
	for (unsigned int i = 0; i < vecstrinfo.size(); i++)
		if (vecstrinfo[i].str == str && vecstrinfo[i].type == type) return i;	//文字列,文字列種が合致した
	return -1;	//合致するデータがなかった場合
}



//
//	デストラクタ
//
//
StringControler::~StringControler()
{
	std::ofstream file("STR\\list.txt");
	if (!file.is_open()) return;
	char number[4];
	for (unsigned int i = 0; i < vecstrinfo.size(); i++) {
		sprintf_s<sizeof(number)>(number, "%3d", i + 1);
		file << number << " | " << vecstrinfo[i].type << ": " << vecstrinfo[i].str << std::endl;
	}
}





//
//	バイナリファイルから文字列情報を読み出す
//
//
int StringControler::LoadStringInformation(const unsigned int file_id) {
	//数を文字に変換
	if (file_id > 999) return -1; //ファイル番号は1-999までの間. 0は別の取り扱い.
	char file_name[8];	//文字列格納バッファ
	sprintf_s<sizeof(file_name)>(file_name, "STR\\%03u", file_id);	//ファイル名は0パディングありの3桁


																	//ファイルオープン
	std::ifstream file(file_name, std::fstream::binary);	//バイナリファイルとしてオープン
	if (!file.is_open()) return -1; //読み込みループを終了させるための戻り値


	//データロード
	StringInformation strinfo;
	//マップ取得
	for (int i = 0; i < 16; i++)
		if (!file.read((char*)&strinfo.led_map[i], sizeof(strinfo.led_map[i]))) goto error_jump;
	//使用LED幅取得
	if (!file.read((char*)&strinfo.width, sizeof(StringInformation::width))) goto error_jump;
	//赤光度取得
	if (!file.read((char*)&strinfo.R, sizeof(StringInformation::R))) goto error_jump;
	//緑光度取得
	if (!file.read((char*)&strinfo.G, sizeof(StringInformation::G))) goto error_jump;
	//青光度取得
	if (!file.read((char*)&strinfo.B, sizeof(StringInformation::B))) goto error_jump;
	//文字種別取得
	if (!file.read(&strinfo.type, sizeof(StringInformation::type))) goto error_jump;
	//文字列取得
	if (file.eof()) goto error_jump;
	strinfo.str.clear();
	do {
		char character;
		file.read(&character, sizeof(character));
		strinfo.str.push_back(character);
	} while (!file.eof());
	strinfo.str.pop_back(); strinfo.str.pop_back();


	//取得完了処理
	vecstrinfo.push_back(strinfo);
	return 0;	//読み取りを正常に完了

				//中途エラー発生時の処理
error_jump:
	vecstrinfo.push_back(strinfo);
	return 1;	//フォーマット非準拠ファイルの検出
}


