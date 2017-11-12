#pragma once
#include "Header.h"
#include "TimeTable.h"
class Billboard
{
private:
	/*LED板本体*/
	LEDTABLE	ledtable;			//LEDの行列
	TABLESIZE	tablesize;			//LEDの行列数
	/*LED板本体*/

	/*データ*/
	TimeTable	timetable;			//時刻表
	/*データ*/

	/*更新トリガ*/
	DATEDATA	prev_datetime;		//前回の処理を行った時刻
	int			prev_millisecond;	//前回のディスプレイ出力時のミリ秒時刻
	bool		english_trigger;	//英語表記トリガ
	int			firsttrain_id;		//先発列車の時刻表ID
	/*更新トリガ*/
public:
	Billboard();							//コンストラクタ及び初期化処理

	bool Init();							//初期化処理
	void Start();							//開始処理
	void Clear();							//LEDを全て消灯する
	void Set();								//裏画面へ描画
	void Update();							//逐次更新処理
	void Process(DATEDATA now_datetime);	//ディスプレイ出力・表示内容更新
	void Change();

	~Billboard();							//デストラクタ
};


