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
public:
	TimeTable();
	int	GetID(int time);
	~TimeTable();
};

