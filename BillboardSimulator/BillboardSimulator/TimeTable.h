#pragma once
#include "Header.h"
#include "LineList.h"
#include "StringList.h"
class TimeTable
{
private:
	/*�����\�{��*/
	TIMETABLE timetable;	//�����\
	/*�����\�{��*/

	/*�f�[�^*/
	LineList	linelist;	//�H���ꗗ
	/*�f�[�^*/
public:
	TimeTable();
	int	GetID(int time);
	~TimeTable();
};

