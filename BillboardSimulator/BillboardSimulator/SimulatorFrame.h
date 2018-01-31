#pragma once
#include "Billboard.h"
#include "TimetableControler.h"
#include "StringControler.h"



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
	TimetableControler timetablecontroler;	//時刻表
	StringControler stringcontroler;	//文字列情報
	TrainInformation traininformation;
public:
	SimulatorFrame();	//コンストラク
	void Start();		//稼働開始メソッド
	~SimulatorFrame();	//デストラクタ
};

