#pragma once
#include <DxLib.h>
#include "Billboard.h"
#include "Timetable.h"
#include "StringControler.h"



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
	Billboard			billboard;			//LEDマトリクス
	StringControler		stringcontroler;	//文字列情報制御クラス
	/*基幹データ*/
	/*表示中の文字列情報*/
	int					size;				//表示可能な文字列の数
	int					current_str_id;		//現在表示している文字列ID
	StringInformation	current_strinfo;	//現在表示している文字列情報
	/*表示中の文字列情報*/
public:
	StringDisplayFrame();	//コンストラクタ
	void Start();			//実行開始メソッド
	~StringDisplayFrame();	//デストラクタ
private:
	void MainLoop();		//主実行メソッド
};

