#pragma once
#include "Header.h"
#include "LineList.h"
#include "StringList.h"
class TimeTable
{
private:
	/*時刻表本体*/
	TIMETABLE timetable;	//時刻表
	/*時刻表本体*/

	/*データ*/
	LineList	linelist;	//路線一覧
	/*データ*/

	//読み込み処理
	bool	Processing(std::list<std::string> element, LineList linelist, StringList stringlist);
public:
	TimeTable();

	//時刻表の読み込み
	int		Init();
	//LEDの点灯状態を反映
	void	Set(LED_MATRIX& led_matrix, TABLESIZE tablesize, int id, int row, int x, int y, bool english_trigger);
	//先発列車の情報を取得
	int		GetID(int time);

	~TimeTable();
};

