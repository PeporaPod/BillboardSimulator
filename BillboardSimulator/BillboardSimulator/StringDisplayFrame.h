#pragma once
#include <DxLib.h>
#include "Billboard.h"
#include "Timetable.h"
#include "StringFile.h"



//
//	StringDisplayFrame�N���X
//
//		�v�f
//			LED�}�g���N�X
//			�����\���
//			��������
//			�\����������ID
//			�\������������
//		���\�b�h
//			�R���X�g���N�^
//			�ғ��J�n���\�b�h
//			�f�X�g���N�^
//		�������\�b�h
//			�ғ����[�v
//
//
//
class StringDisplayFrame
{
private:
	/*��f�[�^*/
	Billboard			billboard;
	Timetable			timetable;
	StringFile			stringfile;
	/*��f�[�^*/
	/*�\�����̕�������*/
	int					string_id;
	StringInformation	stringinformation;
	/*�\�����̕�������*/
public:
	StringDisplayFrame();
	void Start();
	~StringDisplayFrame();
private:
	void MainLoop();
};

