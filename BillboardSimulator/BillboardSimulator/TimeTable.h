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

	//�ǂݍ��ݏ���
	bool	Processing(std::list<std::string> element, LineList linelist, StringList stringlist);
public:
	TimeTable();

	//�����\�̓ǂݍ���
	int		Init();
	//LED�̓_����Ԃ𔽉f
	void	Set(LED_MATRIX& led_matrix, TABLESIZE tablesize, int id, int row, int x, int y, bool english_trigger);
	//�攭��Ԃ̏����擾
	int		GetID(int time);

	~TimeTable();
};

