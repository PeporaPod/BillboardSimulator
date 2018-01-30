#pragma once
#include "Header.h"
#include <fstream>
#include <iostream>
#include <string>
#include <list>

//
//	文字列情報制御クラス
//
//		Init()メソッドによりデータ取得
//
//
//
class StringControler
{
private:
	std::vector<StringInformation> vecstrinfo;	//文字列情報格納ベクトル
	std::list<int> error_file;	//エラーを含むファイルの番号
public:
	StringControler();	//コンストラクタ
	int Init();	//データロード
	StringInformation GetStringInformation(int id);	//番号で文字列情報を返却
	StringInformation GetStringInformation(std::string str, char type);	//表記文字列と文字列種から文字列情報を返却
	int GetStringID(std::string str, char type);
	~StringControler();	//デストラクタ
private:
//	void singularity();
	int LoadStringInformation(const unsigned int file_id);
};

