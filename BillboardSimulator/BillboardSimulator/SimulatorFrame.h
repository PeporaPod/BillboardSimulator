#pragma once
#include "Billboard.h"
#include "TimetableControler.h"
#include "StringControler.h"
#include "LineControler.h"



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
	Billboard			billboard;			//LEDマトリクス
	LineControler		linecontroler;		//路線情報制御クラス
	StringControler		stringcontroler;	//文字列情報
	TimetableControler	timetablecontroler;	//時刻表
public:
	SimulatorFrame();	//コンストラクタ
	void Start();		//稼働開始メソッド
	~SimulatorFrame();	//デストラクタ
private:
	void MainLoop();	//主処理メソッド
};

