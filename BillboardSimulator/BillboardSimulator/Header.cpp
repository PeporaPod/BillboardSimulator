#pragma once
#include "Header.h"



bool Check_StringToInt(std::string string) {
	if (string.empty()) return false;
	for (unsigned int i = 0; i < string.size(); i++) {
		if ('0' <= string[i] && string[i] <= '9');
		else return false;
	}
	return true;
}

bool LoadBinaryString(std::vector<StringInformation>& vecstrinfo, int filenumber)
{
	char filepath[7];									//ファイルパス用バッファ
	sprintf_s<7>(filepath, "STR\\%02d", filenumber);	//ファイルパス変換
	std::ifstream file(filepath, std::fstream::binary);	//ファイルオープン
	if (!file.is_open()) return false;						//ファイルオープンエラー

	StringInformation strinfo;		//格納用変数
	//文字列取得
	file.read(strinfo.string, sizeof(StringInformation::string));
	//LED幅取得
	file.read((char*)&strinfo.width, sizeof(StringInformation::width));
	//文字列種別取得
	file.read((char*)&strinfo.type, sizeof(char));
	//赤濃度取得
	file.read((char*)&strinfo.R, 1);
	//緑濃度取得
	file.read((char*)&strinfo.G, 1);
	//青濃度取得
	file.read((char*)&strinfo.B, 1);
	//LED点灯表の取得
	for (int i = 0; i < LED_ROW; i++)
		file.read((char*)&strinfo.LED_Status, sizeof(StringInformation::LED_Status));
	vecstrinfo.push_back(strinfo);	//

	return true;
}