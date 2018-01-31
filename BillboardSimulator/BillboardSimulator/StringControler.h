#pragma once
#include "Header.h"

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
	std::vector<StringInformation> vecstrinfo;			//文字列情報格納ベクトル
	std::array<StringInformation, 11> vecnumstrinfo;	//数字情報(0-9)+':'格納ベクトル
public:
	//初期化系メソッド
	StringControler();												//コンストラクタ
	int Init();														//データロード

	//文字列情報のゲッタ
	StringInformation GetStringInformation(int id);					//番号で文字列情報を返却
	StringInformation GetStringInformation(char * str, char type);	//表記文字列と文字列種から文字列情報を返却
	StringInformation GetNumberStringInformation(int number);		//数またはコロン専用の文字列情報取得メソッド

	//文字列のID変換
	int GetStringID(std::string str, char type);					//文字列と文字列種から文字列IDを返却
	
	//終了処理系メソッド
	~StringControler();												//デストラクタ
private:
	//細分化内部処理
	bool LoadStringInformation(const unsigned int file_id);			//ファイルから文字列情報をロード
};

