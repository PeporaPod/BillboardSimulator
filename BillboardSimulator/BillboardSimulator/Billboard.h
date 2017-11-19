#pragma once
#include "Header.h"
#include "TimeTable.h"
class Billboard
{
private:
	/*LEDマトリクス*/
				int			led_row;								//LED高
				int			led_column;								//LED幅
				LED_MATRIX	led_matrix;								//LEDの行列
	unsigned	int			led_color_off = GetColor(32, 32, 32);	//LED消灯色
	/*LEDマトリクス*/

	/*更新トリガ*/
	DATEDATA	prev_datetime;		//前回の処理を行った時刻
	int			prev_millisecond;	//前回のディスプレイ出力時のミリ秒時刻
	bool		english_trigger;	//英語表記トリガ
	int			firsttrain_id;		//先発列車の時刻表ID
	/*更新トリガ*/
public:
	Billboard();							//コンストラクタ及び初期化処理
	void Init();							//初期化処理
	void Start();							//開始処理
	void Clear();							//LEDを全て消灯する
	void Set();								//裏画面へ描画
	void Update();							//逐次更新処理
	void Process(DATEDATA now_datetime);	//ディスプレイ出力・表示内容更新
	void Change();

	~Billboard();							//デストラクタ
};


