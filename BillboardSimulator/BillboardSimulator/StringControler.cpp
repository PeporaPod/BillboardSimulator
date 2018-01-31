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
	vecstrinfo.clear();	//再読み込み時のための初期化

	//ファイルのロード
	unsigned int file_id = 0;	//読み込むファイル番号
	do if (!LoadStringInformation(++file_id)) break;	//ファイルの読み込み: 関数からエラーの返り値でループを脱出
	while (true);

	//数字用の別枠を初期化
	char num[2] = "0";
	for (int i = 0; i < 10; i++)
		vecnumstrinfo[i] = GetStringInformation(num, 'N'), num[0]++;
	num[0] = ':';
	vecnumstrinfo[10] = GetStringInformation(num, 'N');

	return file_id - 1;	//読み込んだファイル数を返却
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
StringInformation StringControler::GetStringInformation(char * str, char type)
{
	for (unsigned int i = 0; i < vecstrinfo.size(); i++)
		if (vecstrinfo[i].str == str && vecstrinfo[i].type == type) return vecstrinfo[i];	//文字列,文字列種が合致した
	StringInformation strinfo;
	return strinfo;	//合致するものがデータ上になかった場合
}



//
//	数またはコロンから数字文字列を返却
//
//
StringInformation StringControler::GetNumberStringInformation(int number)
{
	if (number < 0 || number > 10)
		return StringInformation();
	return vecnumstrinfo[number];
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
		sprintf_s<sizeof(number)>(number, "%03d", i + 1);
		file << number << " | " << vecstrinfo[i].type << ": " << vecstrinfo[i].str << std::endl;
	}
}





//
//	バイナリファイルから文字列情報を読み出す
//
//
bool StringControler::LoadStringInformation(const unsigned int file_id) {
	//数を文字に変換
	if (file_id > 999) return false; //ファイル番号は1-999までの間. 0は別の取り扱い.
	char file_name[8];	//文字列格納バッファ
	sprintf_s<sizeof(file_name)>(file_name, "STR\\%03u", file_id);	//ファイル名は0パディングありの3桁


	//ファイルオープン
	std::ifstream file(file_name, std::fstream::binary);	//バイナリファイルとしてオープン
	if (!file.is_open()) return false; //読み込みループを終了させるための戻り値


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
error_jump:
	vecstrinfo.push_back(strinfo);

	return true;	//読み取りを終了
}


