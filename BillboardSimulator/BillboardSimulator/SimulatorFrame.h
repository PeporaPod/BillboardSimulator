#pragma once
#include "Billboard.h"
#include "Timetable.h"
#include "StringFile.h"



//
//	SimulatorFrameクラス
//
//		要素
//			LEDマトリクス
//			時刻表情報
//			文字列情報
//		メソッド
//			コンストラクタ
//			稼働開始メソッド
//			デストラクタ
//
//
//
class SimulatorFrame
{
private:
	Billboard billboard;	//LEDマトリクス
	Timetable timetable;	//時刻表
	StringFile stringfile;	//文字列情報
public:
	SimulatorFrame();	//コンストラク
	void Start();		//稼働開始メソッド
	~SimulatorFrame();	//デストラクタ
};

