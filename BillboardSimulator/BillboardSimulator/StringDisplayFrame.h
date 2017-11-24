#pragma once
#include <DxLib.h>
#include "Billboard.h"
#include "Timetable.h"
#include "StringFile.h"



//
//	StringDisplayFrameクラス
//
//		要素
//			LEDマトリクス
//			時刻表情報
//			文字列情報
//			表示中文字列ID
//			表示中文字列情報
//		メソッド
//			コンストラクタ
//			稼働開始メソッド
//			デストラクタ
//		内部メソッド
//			稼働ループ
//
//
//
class StringDisplayFrame
{
private:
	/*基幹データ*/
	Billboard			billboard;
	Timetable			timetable;
	StringFile			stringfile;
	/*基幹データ*/
	/*表示中の文字列情報*/
	int					string_id;
	StringInformation	stringinformation;
	/*表示中の文字列情報*/
public:
	StringDisplayFrame();
	void Start();
	~StringDisplayFrame();
private:
	void MainLoop();
};

